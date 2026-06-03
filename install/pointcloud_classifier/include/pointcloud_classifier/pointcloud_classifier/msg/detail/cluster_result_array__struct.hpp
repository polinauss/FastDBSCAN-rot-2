// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pointcloud_classifier:msg/ClusterResultArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pointcloud_classifier/msg/cluster_result_array.hpp"


#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__STRUCT_HPP_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'clusters'
#include "pointcloud_classifier/msg/detail/cluster_result__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pointcloud_classifier__msg__ClusterResultArray __attribute__((deprecated))
#else
# define DEPRECATED__pointcloud_classifier__msg__ClusterResultArray __declspec(deprecated)
#endif

namespace pointcloud_classifier
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ClusterResultArray_
{
  using Type = ClusterResultArray_<ContainerAllocator>;

  explicit ClusterResultArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ClusterResultArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _clusters_type =
    std::vector<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>>>;
  _clusters_type clusters;

  // setters for named parameter idiom
  Type & set__clusters(
    const std::vector<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pointcloud_classifier::msg::ClusterResult_<ContainerAllocator>>> & _arg)
  {
    this->clusters = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pointcloud_classifier__msg__ClusterResultArray
    std::shared_ptr<pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pointcloud_classifier__msg__ClusterResultArray
    std::shared_ptr<pointcloud_classifier::msg::ClusterResultArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ClusterResultArray_ & other) const
  {
    if (this->clusters != other.clusters) {
      return false;
    }
    return true;
  }
  bool operator!=(const ClusterResultArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ClusterResultArray_

// alias to use template instance with default allocator
using ClusterResultArray =
  pointcloud_classifier::msg::ClusterResultArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pointcloud_classifier

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__STRUCT_HPP_
