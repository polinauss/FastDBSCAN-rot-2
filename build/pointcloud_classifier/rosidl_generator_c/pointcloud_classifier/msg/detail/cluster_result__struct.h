// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pointcloud_classifier:msg/ClusterResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pointcloud_classifier/msg/cluster_result.h"


#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__STRUCT_H_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'type_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ClusterResult in the package pointcloud_classifier.
typedef struct pointcloud_classifier__msg__ClusterResult
{
  int32_t id;
  rosidl_runtime_c__String type_name;
  int32_t type_code;
  float center_x;
  float center_y;
  float center_z;
  int32_t num_points;
  float width;
  float height;
  float depth;
  float density;
} pointcloud_classifier__msg__ClusterResult;

// Struct for a sequence of pointcloud_classifier__msg__ClusterResult.
typedef struct pointcloud_classifier__msg__ClusterResult__Sequence
{
  pointcloud_classifier__msg__ClusterResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pointcloud_classifier__msg__ClusterResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__STRUCT_H_
