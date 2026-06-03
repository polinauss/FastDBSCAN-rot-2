// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from pointcloud_classifier:msg/ClusterResult.idl
// generated code does not contain a copyright notice

#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pointcloud_classifier/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "pointcloud_classifier/msg/detail/cluster_result__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace pointcloud_classifier
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pointcloud_classifier
cdr_serialize(
  const pointcloud_classifier::msg::ClusterResult & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pointcloud_classifier
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  pointcloud_classifier::msg::ClusterResult & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pointcloud_classifier
get_serialized_size(
  const pointcloud_classifier::msg::ClusterResult & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pointcloud_classifier
max_serialized_size_ClusterResult(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pointcloud_classifier
cdr_serialize_key(
  const pointcloud_classifier::msg::ClusterResult & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pointcloud_classifier
get_serialized_size_key(
  const pointcloud_classifier::msg::ClusterResult & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pointcloud_classifier
max_serialized_size_key_ClusterResult(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace pointcloud_classifier

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_pointcloud_classifier
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, pointcloud_classifier, msg, ClusterResult)();

#ifdef __cplusplus
}
#endif

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
