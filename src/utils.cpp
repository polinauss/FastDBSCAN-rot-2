#include "utils.hpp"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>
#include <pcl/common/common.h>

namespace utils {

void printCloudStatistics(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud, const std::string& name) {
    if (!cloud || cloud->empty()) { 
      std::cout << "Облако \"" << name << "\" пустое" << std::endl; 
      return; 
    }
    pcl::PointXYZ min_pt, max_pt;
    pcl::getMinMax3D(*cloud, min_pt, max_pt);
    std::cout << "Статистика (" << name << "):" << std::endl;
    std::cout << "Точек: " << cloud->points.size() << std::endl;
    std::cout << "X: [" << formatFloat(min_pt.x) << ", " << formatFloat(max_pt.x) << "]" << std::endl;
    std::cout << "Y: [" << formatFloat(min_pt.y) << ", " << formatFloat(max_pt.y) << "]" << std::endl;
    std::cout << "Z: [" << formatFloat(min_pt.z) << ", " << formatFloat(max_pt.z) << "] (высота)" << std::endl;
}

bool saveResultsToCSV(const std::string& filename, const std::vector<ClusterInfo>& results) {
    std::ofstream file(filename);
    if (!file.is_open())
      return false;
    file << "ID;Тип;Центр_X;Центр_Y;Центр_Z;Точек;Ширина;Высота;Глубина;Плотность\n";
    for (const auto& info : results) {
        file << info.id << ";" << info.type_name << ";"<< formatFloat(info.center_x, 6) << ";" << formatFloat(info.center_y, 6) << ";" << formatFloat(info.center_z, 6) << ";"<< info.num_points << ";" << formatFloat(info.width, 3) << ";" << formatFloat(info.height, 3) << ";"<< formatFloat(info.depth, 3) << ";" << formatFloat(info.density, 3) << "\n";
    }
    file.close();
    std::cout << "Результаты сохранены в CSV: " << filename << std::endl;
    return true;
}

bool saveResultsToCustomFormat(const std::string& filename, const std::vector<ClusterInfo>& results, float timestamp) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    file << std::fixed << std::setprecision(6) << timestamp;
    for (const auto& info : results) {
        file << " " << info.center_x << "," << info.center_y << "," << info.center_z << "," << clusterTypeToInt(info.type);
    }
    file << std::endl;
    file.close();
    std::cout << "Сцена сохранена: " << filename << std::endl;
    return true;
}

std::string formatFloat(float value, int precision) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(precision) << value;
    return ss.str();
}

bool fileExists(const std::string& filename) {
    std::ifstream f(filename.c_str());
    return f.good();
}

std::string getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    auto t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::string objectTypeToString(ObjectType type) {
    switch(type) {
        case ObjectType::TREE: return "TREE";
        case ObjectType::CAR: return "CAR";
        case ObjectType::CYCLIST: return "CYCLIST";
        default: return "UNKNOWN";
    }
}

std::string clusterTypeToInt(ObjectType type) {
    switch(type) {
        case ObjectType::TREE: return "1";
        case ObjectType::CAR: return "2";
        case ObjectType::CYCLIST: return "3";
        default: return "0";
    }
}

}
