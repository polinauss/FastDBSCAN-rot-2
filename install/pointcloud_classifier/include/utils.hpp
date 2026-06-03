#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include "cluster_info.hpp"

namespace utils {

    void printCloudStatistics(const pcl::PointCloud<pcl::PointXYZ>::Ptr& cloud, const std::string& name);
    bool saveResultsToCSV(const std::string& filename, const std::vector<ClusterInfo>& results);
    bool saveResultsToCustomFormat(const std::string& filename, const std::vector<ClusterInfo>& results, float timestamp = 0.0f);
    std::string formatFloat(float value, int precision = 3);
    bool fileExists(const std::string& filename);
    std::string getCurrentDateTime();
    std::string objectTypeToString(ObjectType type);
    std::string clusterTypeToInt(ObjectType type);

}

#endif
