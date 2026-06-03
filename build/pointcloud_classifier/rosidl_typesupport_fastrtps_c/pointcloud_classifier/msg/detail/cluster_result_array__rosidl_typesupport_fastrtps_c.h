// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from pointcloud_classifier:msg/ClusterResultArray.idl
// generated code does not contain a copyright notice
#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "pointcloud_classifier/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pointcloud_classifier/msg/detail/cluster_result_array__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pointcloud_classifier
bool cdr_serialize_pointcloud_classifier__msg__ClusterResultArray(
  const pointcloud_classifier__msg__ClusterResultArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pointcloud_classifier
bool cdr_deserialize_pointcloud_classifier__msg__ClusterResultArray(
  eprosima::fastcdr::Cdr &,
  pointcloud_classifier__msg__ClusterResultArray * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pointcloud_classifier
size_t get_serialized_size_pointcloud_classifier__msg__ClusterResultArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pointcloud_classifier
size_t max_serialized_size_pointcloud_classifier__msg__ClusterResultArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pointcloud_classifier
bool cdr_serialize_key_pointcloud_classifier__msg__ClusterResultArray(
  const pointcloud_classifier__msg__ClusterResultArray * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pointcloud_classifier
size_t get_serialized_size_key_pointcloud_classifier__msg__ClusterResultArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pointcloud_classifier
size_t max_serialized_size_key_pointcloud_classifier__msg__ClusterResultArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pointcloud_classifier
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pointcloud_classifier, msg, ClusterResultArray)();

#ifdef __cplusplus
}
#endif

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
