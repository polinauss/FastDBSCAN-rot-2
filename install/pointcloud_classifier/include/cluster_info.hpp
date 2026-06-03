#ifndef CLUSTER_INFO_HPP
#define CLUSTER_INFO_HPP

#include <string>
#include <pcl/point_types.h>

enum class ObjectType {
    UNKNOWN,
    TREE,
    CAR,
    CYCLIST,
    MULTI_OBJECT
};

struct ClusterInfo {
    int id;
    ObjectType type;
    std::string type_name;
    float center_x, center_y, center_z;
    int num_points;
    float min_x, min_y, min_z;
    float max_x, max_y, max_z;
    float width, height, depth;
    float density;
    float volume;
    
    ClusterInfo() : id(-1), type(ObjectType::UNKNOWN), type_name("UNKNOWN"), center_x(0), center_y(0), center_z(0), num_points(0), min_x(0), min_y(0), min_z(0), max_x(0), max_y(0), max_z(0), width(0), height(0), depth(0), density(0), volume(0) {}
    
    pcl::PointXYZ getCenterAsPoint() const {
        return pcl::PointXYZ(center_x, center_y, center_z);
    }
};

struct BenchmarkResult {
    std::string method_name;
    std::string dataset_name;
    int total_points;
    int filtered_points;
    double time_ms;
    long memory_kb;
    int num_clusters;
    double precision;
    double recall;
    double f1_score;
    double silhouette_score;
    int matched_clusters;
    int total_gt_objects;
};

struct ClusterAnalysis {
    int id;
    int num_points;
    float center_x, center_y, center_z;
    float width, height, depth;
    float volume;
    float density;
    std::string predicted_type;
    int predicted_type_int;
    std::string true_type;
    bool matched;
    float distance_to_gt;
};

struct GroundTruthObject {
    int id;
    std::string type;
    float center_x, center_y, center_z;
    float width, length, height;
};

std::string objectTypeToString(ObjectType type);
ObjectType stringToObjectType(const std::string& str);

#endif
