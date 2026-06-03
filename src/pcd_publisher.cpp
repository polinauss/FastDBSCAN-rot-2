#include <memory>
#include <string>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "pcl/io/pcd_io.h"
#include "pcl/point_types.h"
#include "pcl_conversions/pcl_conversions.h"

class PCDPublisher : public rclcpp::Node
{
public:
    PCDPublisher() : Node("pcd_publisher")
    {
        this->declare_parameter<std::string>("pcd_file", "");
        this->declare_parameter<float>("publish_rate_hz", 1.0);

        std::string pcd_file = this->get_parameter("pcd_file").as_string();
        float rate = this->get_parameter("publish_rate_hz").as_double();
        if (pcd_file.empty()) {
            RCLCPP_ERROR(this->get_logger(), "Parameter 'pcd_file' is required. Use: --ros-args -p pcd_file:=/path/to/file.pcd");
            rclcpp::shutdown();
            return;
        }

        publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("/input_pointcloud", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds((int)(1000.0 / rate)),std::bind(&PCDPublisher::publish, this));
        pcd_file_ = pcd_file;
        RCLCPP_INFO(this->get_logger(), "Publishing PCD file: %s at %.1f Hz", pcd_file_.c_str(), rate);
    }

private:
    void publish()
    {
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
        if (pcl::io::loadPCDFile<pcl::PointXYZ>(pcd_file_, *cloud) == -1) {
            RCLCPP_ERROR(this->get_logger(), "Failed to load PCD file: %s", pcd_file_.c_str());
            return;
        }

        sensor_msgs::msg::PointCloud2 ros_cloud;
        pcl::toROSMsg(*cloud, ros_cloud);
        ros_cloud.header.frame_id = "map";
        ros_cloud.header.stamp = this->now();
        publisher_->publish(ros_cloud);
        RCLCPP_INFO(this->get_logger(), "Published cloud with %zu points", cloud->points.size());
    }

    rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::string pcd_file_;
};

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PCDPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
