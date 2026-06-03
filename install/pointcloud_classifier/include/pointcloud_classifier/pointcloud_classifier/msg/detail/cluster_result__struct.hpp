// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pointcloud_classifier:msg/ClusterResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pointcloud_classifier/msg/cluster_result.hpp"


#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__STRUCT_HPP_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pointcloud_classifier__msg__ClusterResult __attribute__((deprecated))
#else
# define DEPRECATED__pointcloud_classifier__msg__ClusterResult __declspec(deprecated)
#endif

namespace pointcloud_classifier
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ClusterResult_
{
  using Type = ClusterResult_<ContainerAllocator>;

  explicit ClusterResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->type_name = "";
      this->type_code = 0l;
      this->center_x = 0.0f;
      this->center_y = 0.0f;
      this->center_z = 0.0f;
      this->num_points = 0l;
      this->width = 0.0f;
      this->height = 0.0f;
      this->depth = 0.0f;
      this->density = 0.0f;
    }
  }

  explicit ClusterResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->type_name = "";
      this->type_code = 0l;
      this->center_x = 0.0f;
      this->center_y = 0.0f;
      this->center_z = 0.0f;
      this->num_points = 0l;
      this->width = 0.0f;
      this->height = 0.0f;
      this->depth = 0.0f;
      this->density = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _type_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_name_type type_name;
  using _type_code_type =
    int32_t;
  _type_code_type type_code;
  using _center_x_type =
    float;
  _center_x_type center_x;
  using _center_y_type =
    float;
  _center_y_type center_y;
  using _center_z_type =
    float;
  _center_z_type center_z;
  using _num_points_type =
    int32_t;
  _num_points_type num_points;
  using _width_type =
    float;
  _width_type width;
  using _height_type =
    float;
  _height_type height;
  using _depth_type =
    float;
  _depth_type depth;
  using _density_type =
    float;
  _density_type density;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__type_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type_name = _arg;
    return *this;
  }
  Type & set__type_code(
    const int32_t & _arg)
  {
    this->type_code = _arg;
    return *this;
  }
  Type & set__center_x(
    const float & _arg)
  {
    this->center_x = _arg;
    return *this;
  }
  Type & set__center_y(
    const float & _arg)
  {
    this->center_y = _arg;
    return *this;
  }
  Type & set__center_z(
    const float & _arg)
  {
    this->center_z = _arg;
    return *this;
  }
  Type & set__num_points(
    const int32_t & _arg)
  {
    this->num_points = _arg;
    return *this;
  }
  Type & set__width(
    const float & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const float & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__depth(
    const float & _arg)
  {
    this->depth = _arg;
    return *this;
  }
  Type & set__density(
    const float & _arg)
  {
    this->density = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pointcloud_classifier::msg::ClusterResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const pointcloud_classifier::msg::ClusterResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pointcloud_classifier__msg__ClusterResult
    std::shared_ptr<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pointcloud_classifier__msg__ClusterResult
    std::shared_ptr<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ClusterResult_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->type_name != other.type_name) {
      return false;
    }
    if (this->type_code != other.type_code) {
      return false;
    }
    if (this->center_x != other.center_x) {
      return false;
    }
    if (this->center_y != other.center_y) {
      return false;
    }
    if (this->center_z != other.center_z) {
      return false;
    }
    if (this->num_points != other.num_points) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->depth != other.depth) {
      return false;
    }
    if (this->density != other.density) {
      return false;
    }
    return true;
  }
  bool operator!=(const ClusterResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ClusterResult_

// alias to use template instance with default allocator
using ClusterResult =
  pointcloud_classifier::msg::ClusterResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pointcloud_classifier

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__STRUCT_HPP_
