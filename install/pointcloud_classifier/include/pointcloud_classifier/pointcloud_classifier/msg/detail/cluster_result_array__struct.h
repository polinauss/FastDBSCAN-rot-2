// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pointcloud_classifier:msg/ClusterResultArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pointcloud_classifier/msg/cluster_result_array.h"


#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__STRUCT_H_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'clusters'
#include "pointcloud_classifier/msg/detail/cluster_result__struct.h"

/// Struct defined in msg/ClusterResultArray in the package pointcloud_classifier.
typedef struct pointcloud_classifier__msg__ClusterResultArray
{
  pointcloud_classifier__msg__ClusterResult__Sequence clusters;
} pointcloud_classifier__msg__ClusterResultArray;

// Struct for a sequence of pointcloud_classifier__msg__ClusterResultArray.
typedef struct pointcloud_classifier__msg__ClusterResultArray__Sequence
{
  pointcloud_classifier__msg__ClusterResultArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pointcloud_classifier__msg__ClusterResultArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__STRUCT_H_
