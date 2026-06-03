#define PCL_DEPRECATED(version, message) __attribute__((deprecated(message)))
#define VTK_DEPRECATED_LEVEL 0

#include "pointcloud_processor.hpp"
#include "utils.hpp"
#include <pcl/io/pcd_io.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/passthrough.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/common/centroid.h>
#include <pcl/common/distances.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>
#include <iomanip>

PointCloudProcessor::PointCloudProcessor() : 
    original_cloud(new pcl::PointCloud<pcl::PointXYZ>), filtered_cloud(new pcl::PointCloud<pcl::PointXYZ>) {}

PointCloudProcessor::~PointCloudProcessor() {}

bool PointCloudProcessor::loadPCDFile(const std::string& filename) {
    std::cout << "\nЗАГРУЗКА" << std::endl;
    if (!utils::fileExists(filename)) {
        std::cerr << "Файл не найден: " << filename << std::endl;
        return false;
    }
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(filename, *original_cloud) == -1) {
        std::cerr << "Ошибка загрузки!" << std::endl;
        return false;
    }
    utils::printCloudStatistics(original_cloud, "загруженное");
    return true;
}

void PointCloudProcessor::preprocessCloud(int mean_k, float stddev_mult) {
    std::cout << "\nФИЛЬТРАЦИЯ" << std::endl;
    
    pcl::PointCloud<pcl::PointXYZ>::Ptr no_ground(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud(original_cloud);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(0.2, 10.0);
    pass.filter(*no_ground);
    std::cout << "После удаления земли (z < 0.2): " << no_ground->points.size() << " точек" << std::endl;
    
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
    sor.setInputCloud(no_ground);
    sor.setMeanK(mean_k);
    sor.setStddevMulThresh(stddev_mult);
    sor.filter(*filtered_cloud);
    std::cout << "После удаления выбросов: " << filtered_cloud->points.size() << " точек" << std::endl;
}

float PointCloudProcessor::distance(const pcl::PointXYZ& p1, const pcl::PointXYZ& p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dz = p1.z - p2.z;
    return dx*dx + dy*dy + dz*dz;
}

void PointCloudProcessor::initializeKMeansCentroids(const pcl::PointCloud<pcl::PointXYZ>& cloud, std::vector<pcl::PointXYZ>& centroids,int K, const std::string& method) {
    std::random_device rd;
    std::mt19937 gen(rd());
    
    if (method == "random") {
        std::uniform_int_distribution<> dis(0, cloud.points.size() - 1);
        for (int i = 0; i < K; i++) centroids.push_back(cloud.points[dis(gen)]);
    } else {
        std::uniform_int_distribution<> dis(0, cloud.points.size() - 1);
        centroids.push_back(cloud.points[dis(gen)]);
        for (int i = 1; i < K; i++) {
            std::vector<float> distances(cloud.points.size(), std::numeric_limits<float>::max());
            float total_distance = 0;
            for (size_t j = 0; j < cloud.points.size(); j++) {
                float min_dist = std::numeric_limits<float>::max();
                for (const auto& c : centroids) {
                    float d = distance(cloud.points[j], c);
                    min_dist = std::min(min_dist, d);
                }
                distances[j] = min_dist;
                total_distance += min_dist;
            }
            std::uniform_real_distribution<float> prob_dis(0, total_distance);
            float threshold = prob_dis(gen);
            float cumulative = 0;
            size_t selected_idx = 0;
            for (size_t j = 0; j < distances.size(); j++) {
                cumulative += distances[j];
                if (cumulative >= threshold) { selected_idx = j;
                break;
                }
            }
            centroids.push_back(cloud.points[selected_idx]);
        }
    }
}

void PointCloudProcessor::performClustering(float tolerance, int min_size, int max_size) {
    std::cout << "\nКЛАСТЕРИЗАЦИЯ DBSCAN" << std::endl;
    std::cout << "Порог: " << tolerance << " м, Мин. размер: " << min_size << std::endl;
    if (filtered_cloud->empty()) { std::cout << "Облако пустое" << std::endl; return; }
    
    auto start = std::chrono::high_resolution_clock::now();
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
    tree->setInputCloud(filtered_cloud);
    std::vector<pcl::PointIndices> cluster_indices;
    pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
    ec.setClusterTolerance(tolerance);
    ec.setMinClusterSize(min_size);
    ec.setMaxClusterSize(max_size);
    ec.setSearchMethod(tree);
    ec.setInputCloud(filtered_cloud);
    ec.extract(cluster_indices);
    
    clusters.clear();
    for (const auto& indices : cluster_indices) {
        pcl::PointCloud<pcl::PointXYZ>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZ>);
        for (const auto& idx : indices.indices) cluster->points.push_back(filtered_cloud->points[idx]);
        cluster->width = cluster->points.size(); cluster->height = 1;
        clusters.push_back(cluster);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Найдено кластеров: " << clusters.size() << std::endl;
    std::cout << "Время: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " мс" << std::endl;
}

void PointCloudProcessor::performKMeans(int K, int max_iterations, float tolerance) {
    std::cout << "\nКЛАСТЕРИЗАЦИЯ K-MEANS (K=" << K << ")" << std::endl;
    if (filtered_cloud->empty()) { std::cout << "Облако пустое" << std::endl; return; }
    
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<pcl::PointXYZ> centroids;
    initializeKMeansCentroids(*filtered_cloud, centroids, K, "kmeans++");
    std::vector<int> assignments(filtered_cloud->points.size(), -1);
    bool changed = true;
    int iter = 0;
    
    while (changed && iter < max_iterations) {
        changed = false;
        for (size_t i = 0; i < filtered_cloud->points.size(); i++) {
            float min_dist = std::numeric_limits<float>::max();
            int best = 0;
            for (int j = 0; j < K; j++) {
                float d = distance(filtered_cloud->points[i], centroids[j]);
                if (d < min_dist){
                  min_dist = d; best = j;
                }
            }
            if (assignments[i] != best) {
              assignments[i] = best;
              changed = true;
            }
        }
        std::vector<int> counts(K, 0);
        std::vector<pcl::PointXYZ> new_c(K, pcl::PointXYZ(0,0,0));
        for (size_t i = 0; i < assignments.size(); i++) {
            int c = assignments[i];
            new_c[c].x += filtered_cloud->points[i].x;
            new_c[c].y += filtered_cloud->points[i].y;
            new_c[c].z += filtered_cloud->points[i].z;
            counts[c]++;
        }
        float max_change = 0;
        for (int j = 0; j < K; j++) {
            if (counts[j] > 0) {
                new_c[j].x /= counts[j];
                new_c[j].y /= counts[j];
                new_c[j].z /= counts[j];
                float change = sqrt(distance(new_c[j], centroids[j]));
                max_change = std::max(max_change, change);
                centroids[j] = new_c[j];
            }
        }
        if (max_change < tolerance) changed = false;
        iter++;
    }
    
    clusters.clear();
    std::vector<std::vector<int>> cluster_points(K);
    for (size_t i = 0; i < assignments.size(); i++)
      cluster_points[assignments[i]].push_back(i);
    for (int i = 0; i < K; i++) {
        if (cluster_points[i].empty()) continue;
        pcl::PointCloud<pcl::PointXYZ>::Ptr c(new pcl::PointCloud<pcl::PointXYZ>);
        for (int idx : cluster_points[i]) c->points.push_back(filtered_cloud->points[idx]);
        c->width = c->points.size(); c->height = 1;
        clusters.push_back(c);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Кластеров: " << clusters.size() << ", Время: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " мс" << std::endl;
}

void PointCloudProcessor::performFastDBSCAN(int K, float t, float eps, int minPts) {
    std::cout << "\nFASTDBSCAN (K=" << K << ", t=" << t*100 << "%, eps=" << eps << ", minPts=" << minPts << ")" << std::endl;
    if (filtered_cloud->empty()) { std::cout << "Облако пустое" << std::endl; return; }
    
    auto start = std::chrono::high_resolution_clock::now();
    const int N = filtered_cloud->points.size();
    std::vector<pcl::PointXYZ> points(N);
    for (int i = 0; i < N; i++) points[i] = filtered_cloud->points[i];
    
    std::vector<pcl::PointXYZ> centers(K);
    std::random_device rd; std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, N-1);
    for (int i = 0; i < K; i++) centers[i] = points[dis(gen)];
    
    std::vector<int> assignments(N, -1);
    bool changed = true; int iter = 0;
    while (changed && iter < 50) {
        changed = false;
        for (int i = 0; i < N; i++) {
            float min_d = std::numeric_limits<float>::max(); int best = 0;
            for (int j = 0; j < K; j++) {
                float d = pcl::squaredEuclideanDistance(points[i], centers[j]);
                if (d < min_d) { min_d = d; best = j; }
            }
            if (assignments[i] != best) { assignments[i] = best; changed = true; }
        }
        std::vector<int> counts(K, 0);
        std::vector<pcl::PointXYZ> new_c(K, pcl::PointXYZ(0,0,0));
        for (int i = 0; i < N; i++) {
            int c = assignments[i];
            new_c[c].x += points[i].x;
            new_c[c].y += points[i].y;
            new_c[c].z += points[i].z;
            counts[c]++;
        }
        for (int j = 0; j < K; j++) {
            if (counts[j] > 0) {
                new_c[j].x /= counts[j];
                new_c[j].y /= counts[j];
                new_c[j].z /= counts[j];
                centers[j] = new_c[j];
            }
        }
        iter++;
    }
    
    std::vector<std::vector<int>> cluster_points(K);
    for (int i = 0; i < N; i++) cluster_points[assignments[i]].push_back(i);
    
    pcl::PointCloud<pcl::PointXYZ>::Ptr sampled(new pcl::PointCloud<pcl::PointXYZ>);
    std::vector<int> sample_to_original;
    for (int j = 0; j < K; j++) {
        int take = std::max(1, (int)(cluster_points[j].size() * t));
        std::shuffle(cluster_points[j].begin(), cluster_points[j].end(), gen);
        for (int s = 0; s < take && s < (int)cluster_points[j].size(); s++) {
            int idx = cluster_points[j][s];
            sampled->points.push_back(points[idx]);
            sample_to_original.push_back(idx);
        }
    }
    
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>);
    tree->setInputCloud(sampled);
    std::vector<pcl::PointIndices> sample_clusters;
    pcl::EuclideanClusterExtraction<pcl::PointXYZ> ec;
    ec.setClusterTolerance(eps);
    ec.setMinClusterSize(std::max(1, (int)(minPts * t)));
    ec.setSearchMethod(tree);
    ec.setInputCloud(sampled);
    ec.extract(sample_clusters);
    
    std::vector<int> final_labels(N, -1);
    for (size_t i = 0; i < sample_clusters.size(); i++)
        for (int idx : sample_clusters[i].indices)
            final_labels[sample_to_original[idx]] = i;
    
    pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;
    kdtree.setInputCloud(sampled);
    for (int i = 0; i < N; i++) {
        if (final_labels[i] == -1) {
            std::vector<int> idx(1); std::vector<float> d(1);
            kdtree.nearestKSearch(points[i], 1, idx, d);
            if (!idx.empty()) {
                for (size_t j = 0; j < sample_clusters.size(); j++) {
                    if (std::find(sample_clusters[j].indices.begin(), sample_clusters[j].indices.end(), idx[0]) != sample_clusters[j].indices.end()) {
                        final_labels[i] = j; break;
                    }
                }
            }
        }
    }
    
    std::unordered_map<int, std::vector<int>> label_to_idx;
    for (int i = 0; i < N; i++) if (final_labels[i] != -1) label_to_idx[final_labels[i]].push_back(i);
    
    clusters.clear();
    for (const auto& p : label_to_idx) {
        if ((int)p.second.size() >= minPts) {
            pcl::PointCloud<pcl::PointXYZ>::Ptr c(new pcl::PointCloud<pcl::PointXYZ>);
            for (int idx : p.second) c->points.push_back(points[idx]);
            c->width = c->points.size(); c->height = 1;
            clusters.push_back(c);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Кластеров: " << clusters.size() << ", Время: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " мс" << std::endl;
}

void PointCloudProcessor::performHybridClustering(float tol, int min_size, int K, float t) {
    performFastDBSCAN(K, t, tol, min_size);
}

void PointCloudProcessor::calculateClusterProperties(pcl::PointCloud<pcl::PointXYZ>::Ptr cluster, ClusterInfo& info) {
    if (cluster->empty()) return;
    info.min_x = info.max_x = cluster->points[0].x;
    info.min_y = info.max_y = cluster->points[0].y;
    info.min_z = info.max_z = cluster->points[0].z;
    double sx = 0, sy = 0, sz = 0;
    for (const auto& p : cluster->points) {
        sx += p.x; sy += p.y; sz += p.z;
        if (p.x < info.min_x) info.min_x = p.x;
        if (p.y < info.min_y) info.min_y = p.y;
        if (p.z < info.min_z) info.min_z = p.z;
        if (p.x > info.max_x) info.max_x = p.x;
        if (p.y > info.max_y) info.max_y = p.y;
        if (p.z > info.max_z) info.max_z = p.z;
    }
    info.center_x = sx / info.num_points;
    info.center_y = sy / info.num_points;
    info.center_z = sz / info.num_points;
    info.width = info.max_x - info.min_x;
    info.height = info.max_z - info.min_z;
    info.depth = info.max_y - info.min_y;
    info.volume = info.width * info.height * info.depth;
    info.density = (info.volume > 0) ? info.num_points / info.volume : 0;
}

void PointCloudProcessor::analyzeClusters() {
    std::cout << "\nАНАЛИЗ КЛАСТЕРОВ" << std::endl;
    cluster_info_list.clear();
    for (size_t i = 0; i < clusters.size(); i++) {
        ClusterInfo info;
        info.id = i;
        info.num_points = clusters[i]->points.size();
        calculateClusterProperties(clusters[i], info);
        info.type = ObjectType::UNKNOWN;
        info.type_name = utils::objectTypeToString(info.type);
        cluster_info_list.push_back(info);
        std::cout << "Кластер " << i << ": X=" << utils::formatFloat(info.width) << " Y=" << utils::formatFloat(info.depth) << " Z=" << utils::formatFloat(info.height) << std::endl;
    }
}

ObjectType PointCloudProcessor::classifyObject(const ClusterInfo& info) {
    float sx = info.width, sy = info.depth, sz = info.height;
    float hmax = std::max(sx, sy), hmin = std::min(sx, sy), ratio = hmax / hmin;
    if (sz > 2.2f && hmax < sz * 1.5f)
      return ObjectType::TREE;
    if (sz >= 0.8f && sz <= 2.5f) {
        if (hmax >= 3.2f && hmax <= 7.5f && hmin >= 1.2f && hmin <= 3.2f)
          return ObjectType::CAR;
        if (ratio >= 1.5f && hmax >= 3.0f && hmin >= 1.2f)
          return ObjectType::CAR;
    }
    if (sz >= 1.2f && sz <= 1.9f && hmax >= 1.2f && hmax <= 2.2f && hmin >= 0.5f && hmin <= 1.2f)
      return ObjectType::CYCLIST;
    if (sz >= 1.2f && sz <= 1.9f && ratio >= 1.2f && ratio <= 2.5f && hmax >= 1.2f && hmax <= 2.2f)
      return ObjectType::CYCLIST;
    return ObjectType::UNKNOWN;
}

void PointCloudProcessor::classifyClusters() {
    std::cout << "\nКЛАССИФИКАЦИЯ" << std::endl;
    int trees = 0, cars = 0, cyclists = 0;
    for (auto& info : cluster_info_list) {
        info.type = classifyObject(info);
        info.type_name = utils::objectTypeToString(info.type);
        if (info.type == ObjectType::TREE) trees++;
        else if (info.type == ObjectType::CAR) cars++;
        else if (info.type == ObjectType::CYCLIST) cyclists++;
        std::cout << "Кластер " << info.id << ": " << info.type_name << " H=" << utils::formatFloat(info.height,2) << " Pts=" << info.num_points << std::endl;
    }
    std::cout << "ИТОГИ: Деревьев=" << trees << ", Авто=" << cars << ", Вело=" << cyclists << ", Неизв=" << (cluster_info_list.size()-trees-cars-cyclists) << std::endl;
}

bool PointCloudProcessor::saveResultsToFile(const std::string& f) { return utils::saveResultsToCSV(f, cluster_info_list); }
bool PointCloudProcessor::saveResultsToCustomFormat(const std::string& f, float t) { return utils::saveResultsToCustomFormat(f, cluster_info_list, t); }

void PointCloudProcessor::compareClusteringMethods(float dbscan_tol, int min_size, int kmeans_K, int fast_K, float fast_t, float fast_eps, int fast_minPts) {
    std::cout << "СРАВНЕНИЕ МЕТОДОВ" << std::endl;
    auto orig_clusters = clusters;
    auto orig_info = cluster_info_list;
    
    std::cout << "\nDBSCAN" << std::endl;
    performClustering(dbscan_tol, min_size, 100000);
    analyzeClusters();
    classifyClusters();
    int dbscan_obj = cluster_info_list.size(), dbscan_cls = 0;
    for (const auto& i : cluster_info_list)
      if (i.type != ObjectType::UNKNOWN)
        dbscan_cls++;
    
    std::cout << "\nK-MEANS" << std::endl;
    performKMeans(kmeans_K);
    analyzeClusters();
    classifyClusters();
    int kmeans_obj = cluster_info_list.size(), kmeans_cls = 0;
    for (const auto& i : cluster_info_list)
      if (i.type != ObjectType::UNKNOWN)
        kmeans_cls++;
    
    std::cout << "\nFASTDBSCAN" << std::endl;
    performFastDBSCAN(fast_K, fast_t, fast_eps, fast_minPts);
    analyzeClusters(); classifyClusters();
    int fast_obj = cluster_info_list.size(), fast_cls = 0;
    for (const auto& i : cluster_info_list) if (i.type != ObjectType::UNKNOWN) fast_cls++;
    
    std::cout << std::left << std::setw(15) << "Метод" << std::setw(12) << "Кластеров" << std::setw(12) << "Распознано" << std::setw(12) << "Точность%" << std::endl;
    std::cout << std::left << std::setw(15) << "DBSCAN" << std::setw(12) << dbscan_obj << std::setw(12) << dbscan_cls << std::setw(12) << (dbscan_obj>0?100.0*dbscan_cls/dbscan_obj:0) << std::endl;
    std::cout << std::left << std::setw(15) << "K-means" << std::setw(12) << kmeans_obj << std::setw(12) << kmeans_cls << std::setw(12) << (kmeans_obj>0?100.0*kmeans_cls/kmeans_obj:0) << std::endl;
    std::cout << std::left << std::setw(15) << "FastDBSCAN" << std::setw(12) << fast_obj << std::setw(12) << fast_cls << std::setw(12) << (fast_obj>0?100.0*fast_cls/fast_obj:0) << std::endl;
    
    clusters = orig_clusters;
    cluster_info_list = orig_info;
}

void PointCloudProcessor::visualizeResults() {
    std::cout << "\nВИЗУАЛИЗАЦИЯ (q - выход)" << std::endl;
    pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer("Classifier"));
    viewer->setBackgroundColor(0.1, 0.1, 0.1);
    viewer->addCoordinateSystem(2.0);
    
    pcl::PointCloud<pcl::PointXYZ>::Ptr ground(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud(original_cloud);
    pass.setFilterFieldName("z");
    pass.setFilterLimits(-0.2, 0.15);
    pass.filter(*ground);
    if (!ground->empty()) {
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> gray(ground, 80, 80, 80);
        viewer->addPointCloud(ground, gray, "ground");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "ground");
    }
    
    for (size_t i = 0; i < clusters.size() && i < cluster_info_list.size(); i++) {
        float r=0.7, g=0.7, b=0.7;
        if (cluster_info_list[i].type == ObjectType::TREE){
          r=0.2; 
          g=0.8;
          b=0.2;
        }
        else if (cluster_info_list[i].type == ObjectType::CAR) {
          r=0.9;
          g=0.2;
          b=0.2;
        }
        else if (cluster_info_list[i].type == ObjectType::CYCLIST) { 
          r=0.9;
          g=0.9;
          b=0.2;
        }
        
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> color(clusters[i], r*255, g*255, b*255);
        viewer->addPointCloud(clusters[i], color, "cluster_"+std::to_string(i));
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "cluster_"+std::to_string(i));
        
        pcl::PointXYZ c(cluster_info_list[i].center_x, cluster_info_list[i].center_y, cluster_info_list[i].center_z);
        viewer->addSphere(c, 0.12, r, g, b, "sphere_"+std::to_string(i));
        viewer->addText3D(cluster_info_list[i].type_name, c, 0.35, r, g, b, "text_"+std::to_string(i));
    }
    std::cout << "Зеленый-Деревья, Красный-Авто, Желтый-Вело, Серый-Земля" << std::endl;
    while (!viewer->wasStopped()) {
      viewer->spinOnce(100);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void PointCloudProcessor::setTreeParams(float h, float r) {
  TREE_MIN_HEIGHT = h;
  TREE_MAX_WIDTH_RATIO = r;
}
void PointCloudProcessor::setCarParams(float minH, float maxH, float minW, float maxW, float minL, float maxL) {
    CAR_MIN_HEIGHT = minH; CAR_MAX_HEIGHT = maxH;
    CAR_MIN_WIDTH = minW; CAR_MAX_WIDTH = maxW;
    CAR_MIN_LENGTH = minL; CAR_MAX_LENGTH = maxL;
}
void PointCloudProcessor::setCrossingParams(float, float) {}
