// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pointcloud_classifier:msg/ClusterResultArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pointcloud_classifier/msg/cluster_result_array.hpp"


#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__BUILDER_HPP_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pointcloud_classifier/msg/detail/cluster_result_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pointcloud_classifier
{

namespace msg
{

namespace builder
{

class Init_ClusterResultArray_clusters
{
public:
  Init_ClusterResultArray_clusters()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::pointcloud_classifier::msg::ClusterResultArray clusters(::pointcloud_classifier::msg::ClusterResultArray::_clusters_type arg)
  {
    msg_.clusters = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResultArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pointcloud_classifier::msg::ClusterResultArray>()
{
  return pointcloud_classifier::msg::builder::Init_ClusterResultArray_clusters();
}

}  // namespace pointcloud_classifier

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__BUILDER_HPP_
