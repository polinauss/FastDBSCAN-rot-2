#ifndef POINTCLOUD_PROCESSOR_HPP
#define POINTCLOUD_PROCESSOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include "cluster_info.hpp"

class PointCloudProcessor {
private:
    pcl::PointCloud<pcl::PointXYZ>::Ptr original_cloud;
    pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud;
    std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> clusters;
    std::vector<ClusterInfo> cluster_info_list;

    float TREE_MIN_HEIGHT = 2.2f;
    float TREE_MAX_WIDTH_RATIO = 1.5f;
    
    float CAR_MIN_HEIGHT = 0.8f;
    float CAR_MAX_HEIGHT = 2.5f;
    float CAR_MIN_WIDTH = 1.2f;
    float CAR_MAX_WIDTH = 3.2f;
    float CAR_MIN_LENGTH = 3.2f;
    float CAR_MAX_LENGTH = 7.5f;
    
    float CYCLIST_MIN_HEIGHT = 1.2f;
    float CYCLIST_MAX_HEIGHT = 1.9f;
    float CYCLIST_MIN_LENGTH = 1.2f;
    float CYCLIST_MAX_LENGTH = 2.2f;
    float CYCLIST_MIN_WIDTH = 0.5f;
    float CYCLIST_MAX_WIDTH = 1.2f;

    ObjectType classifyObject(const ClusterInfo& info);
    void calculateClusterProperties(pcl::PointCloud<pcl::PointXYZ>::Ptr cluster, ClusterInfo& info);
    
    struct IndexedPoint {
        pcl::PointXYZ point;
        int original_index;
    };
    
    float distance(const pcl::PointXYZ& p1, const pcl::PointXYZ& p2);
    void initializeKMeansCentroids(const pcl::PointCloud<pcl::PointXYZ>& cloud, std::vector<pcl::PointXYZ>& centroids,int K, const std::string& method = "kmeans++");

public:
    PointCloudProcessor();
    ~PointCloudProcessor();

    void setInputCloud(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud) { original_cloud = cloud; }
    bool loadPCDFile(const std::string& filename);
    void preprocessCloud(int mean_k = 50, float stddev_mult = 1.0);

    void performClustering(float cluster_tolerance, int min_cluster_size, int max_cluster_size);
    void performKMeans(int K, int max_iterations = 100, float tolerance = 1e-4);
    void performFastDBSCAN(int K, float t, float eps, int minPts);
    void performHybridClustering(float cluster_tolerance, int min_cluster_size, int K = 100, float t = 0.1f);

    void analyzeClusters();
    void classifyClusters();

    bool saveResultsToFile(const std::string& filename);
    bool saveResultsToCustomFormat(const std::string& filename, float timestamp = 0.0f);

    void visualizeResults();
    
    void compareClusteringMethods(float dbscan_tolerance = 0.5f,int min_cluster_size = 50,int kmeans_K = 50,int fastdbscan_K = 80, float fastdbscan_t = 0.12f,float fastdbscan_eps = 0.5f,int fastdbscan_minPts = 40);

    const pcl::PointCloud<pcl::PointXYZ>::Ptr& getOriginalCloud() const { return original_cloud; }
    const pcl::PointCloud<pcl::PointXYZ>::Ptr& getFilteredCloud() const { return filtered_cloud; }
    const std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr>& getClusters() const { return clusters; }
    const std::vector<ClusterInfo>& getResults() const { return cluster_info_list; }

    void setTreeParams(float min_height, float max_width_ratio);
    void setCarParams(float min_height, float max_height, float min_width, float max_width, float min_length, float max_length);
    void setCrossingParams(float max_height, float min_width);
};

#endif
