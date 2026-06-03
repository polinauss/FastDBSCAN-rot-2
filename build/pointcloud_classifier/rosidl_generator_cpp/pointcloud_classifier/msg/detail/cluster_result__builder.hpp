// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pointcloud_classifier:msg/ClusterResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pointcloud_classifier/msg/cluster_result.hpp"


#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__BUILDER_HPP_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pointcloud_classifier/msg/detail/cluster_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pointcloud_classifier
{

namespace msg
{

namespace builder
{

class Init_ClusterResult_density
{
public:
  explicit Init_ClusterResult_density(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  ::pointcloud_classifier::msg::ClusterResult density(::pointcloud_classifier::msg::ClusterResult::_density_type arg)
  {
    msg_.density = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_depth
{
public:
  explicit Init_ClusterResult_depth(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  Init_ClusterResult_density depth(::pointcloud_classifier::msg::ClusterResult::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_ClusterResult_density(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_height
{
public:
  explicit Init_ClusterResult_height(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  Init_ClusterResult_depth height(::pointcloud_classifier::msg::ClusterResult::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_ClusterResult_depth(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_width
{
public:
  explicit Init_ClusterResult_width(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  Init_ClusterResult_height width(::pointcloud_classifier::msg::ClusterResult::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_ClusterResult_height(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_num_points
{
public:
  explicit Init_ClusterResult_num_points(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  Init_ClusterResult_width num_points(::pointcloud_classifier::msg::ClusterResult::_num_points_type arg)
  {
    msg_.num_points = std::move(arg);
    return Init_ClusterResult_width(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_center_z
{
public:
  explicit Init_ClusterResult_center_z(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  Init_ClusterResult_num_points center_z(::pointcloud_classifier::msg::ClusterResult::_center_z_type arg)
  {
    msg_.center_z = std::move(arg);
    return Init_ClusterResult_num_points(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_center_y
{
public:
  explicit Init_ClusterResult_center_y(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  Init_ClusterResult_center_z center_y(::pointcloud_classifier::msg::ClusterResult::_center_y_type arg)
  {
    msg_.center_y = std::move(arg);
    return Init_ClusterResult_center_z(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_center_x
{
public:
  explicit Init_ClusterResult_center_x(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  Init_ClusterResult_center_y center_x(::pointcloud_classifier::msg::ClusterResult::_center_x_type arg)
  {
    msg_.center_x = std::move(arg);
    return Init_ClusterResult_center_y(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_type_code
{
public:
  explicit Init_ClusterResult_type_code(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  Init_ClusterResult_center_x type_code(::pointcloud_classifier::msg::ClusterResult::_type_code_type arg)
  {
    msg_.type_code = std::move(arg);
    return Init_ClusterResult_center_x(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_type_name
{
public:
  explicit Init_ClusterResult_type_name(::pointcloud_classifier::msg::ClusterResult & msg)
  : msg_(msg)
  {}
  Init_ClusterResult_type_code type_name(::pointcloud_classifier::msg::ClusterResult::_type_name_type arg)
  {
    msg_.type_name = std::move(arg);
    return Init_ClusterResult_type_code(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

class Init_ClusterResult_id
{
public:
  Init_ClusterResult_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ClusterResult_type_name id(::pointcloud_classifier::msg::ClusterResult::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ClusterResult_type_name(msg_);
  }

private:
  ::pointcloud_classifier::msg::ClusterResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pointcloud_classifier::msg::ClusterResult>()
{
  return pointcloud_classifier::msg::builder::Init_ClusterResult_id();
}

}  // namespace pointcloud_classifier

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__BUILDER_HPP_
