#include <memory>
#include <string>
#include <vector>
#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "pcl_conversions/pcl_conversions.h"
#include "pcl/point_cloud.h"
#include "pcl/point_types.h"
#include "cluster_info.hpp"
#include "pointcloud_processor.hpp"
#include "pointcloud_classifier/msg/cluster_result_array.hpp"

using PointCloud2 = sensor_msgs::msg::PointCloud2;
class PointCloudClassifierNode : public rclcpp::Node{
public:
    PointCloudClassifierNode() : Node("pointcloud_classifier_node"){
        this->declare_parameter<int>("fastdbscan_K", 80);
        this->declare_parameter<float>("fastdbscan_t", 0.12f);
        this->declare_parameter<float>("fastdbscan_eps", 0.5f);
        this->declare_parameter<int>("fastdbscan_minPts", 40);
        this->declare_parameter<int>("filter_mean_k", 50);
        this->declare_parameter<float>("filter_stddev_mult", 1.0f);
        this->declare_parameter<std::string>("output_file", "classification_results.txt");
        this->declare_parameter<bool>("save_to_file", true);
        fastdbscan_K_ = this->get_parameter("fastdbscan_K").as_int();
        fastdbscan_t_ = this->get_parameter("fastdbscan_t").as_double();
        fastdbscan_eps_ = this->get_parameter("fastdbscan_eps").as_double();
        fastdbscan_minPts_ = this->get_parameter("fastdbscan_minPts").as_int();
        mean_k_ = this->get_parameter("filter_mean_k").as_int();
        stddev_mult_ = this->get_parameter("filter_stddev_mult").as_double();
        output_file_ = this->get_parameter("output_file").as_string();
        save_to_file_ = this->get_parameter("save_to_file").as_bool();
        subscription_ = this->create_subscription<PointCloud2>("/input_pointcloud", 10,std::bind(&PointCloudClassifierNode::cloudCallback, this, std::placeholders::_1));
        result_publisher_ = this->create_publisher<pointcloud_classifier::msg::ClusterResultArray>("/cluster_results", 10);
        RCLCPP_INFO(this->get_logger(),"FastDBSCAN node ready. K=%d, t=%.2f, eps=%.2f, minPts=%d",fastdbscan_K_, fastdbscan_t_, fastdbscan_eps_, fastdbscan_minPts_);
    }

private:
    void cloudCallback(const PointCloud2::SharedPtr msg){
        auto start = std::chrono::steady_clock::now();
        auto stamp = msg->header.stamp;
        pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZ>);
        pcl::fromROSMsg(*msg, *pcl_cloud);
        PointCloudProcessor processor;
        processor.setInputCloud(pcl_cloud);
        processor.preprocessCloud(mean_k_, static_cast<float>(stddev_mult_));
        processor.performFastDBSCAN(fastdbscan_K_, static_cast<float>(fastdbscan_t_),static_cast<float>(fastdbscan_eps_), fastdbscan_minPts_);
        processor.analyzeClusters();
        processor.classifyClusters();
        const auto& results = processor.getResults();
        pointcloud_classifier::msg::ClusterResultArray result_array;
        for (const auto& info : results) {
            pointcloud_classifier::msg::ClusterResult res;
            res.id = info.id;
            res.type_name = info.type_name;
            res.type_code = static_cast<int>(info.type);
            res.center_x = info.center_x;
            res.center_y = info.center_y;
            res.center_z = info.center_z;
            res.num_points = info.num_points;
            res.width = info.width;
            res.height = info.height;
            res.depth = info.depth;
            res.density = info.density;
            res.timestamp = stamp;
            result_array.clusters.push_back(res);
        }

        result_publisher_->publish(result_array);
        if (save_to_file_) {
            processor.saveResultsToFile(output_file_);
        }

        auto end = std::chrono::steady_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        RCLCPP_DEBUG(this->get_logger(), "Processed %zu points -> %zu clusters in %ld ms",pcl_cloud->size(), results.size(), ms);
    }

    rclcpp::Subscription<PointCloud2>::SharedPtr subscription_;
    rclcpp::Publisher<pointcloud_classifier::msg::ClusterResultArray>::SharedPtr result_publisher_;
    int fastdbscan_K_, fastdbscan_minPts_;
    double fastdbscan_t_, fastdbscan_eps_;
    int mean_k_;
    double stddev_mult_;
    std::string output_file_;
    bool save_to_file_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PointCloudClassifierNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
