// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from pointcloud_classifier:msg/ClusterResultArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pointcloud_classifier/msg/cluster_result_array.h"


#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__FUNCTIONS_H_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "pointcloud_classifier/msg/rosidl_generator_c__visibility_control.h"

#include "pointcloud_classifier/msg/detail/cluster_result_array__struct.h"

/// Initialize msg/ClusterResultArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * pointcloud_classifier__msg__ClusterResultArray
 * )) before or use
 * pointcloud_classifier__msg__ClusterResultArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
bool
pointcloud_classifier__msg__ClusterResultArray__init(pointcloud_classifier__msg__ClusterResultArray * msg);

/// Finalize msg/ClusterResultArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
void
pointcloud_classifier__msg__ClusterResultArray__fini(pointcloud_classifier__msg__ClusterResultArray * msg);

/// Create msg/ClusterResultArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * pointcloud_classifier__msg__ClusterResultArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
pointcloud_classifier__msg__ClusterResultArray *
pointcloud_classifier__msg__ClusterResultArray__create(void);

/// Destroy msg/ClusterResultArray message.
/**
 * It calls
 * pointcloud_classifier__msg__ClusterResultArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
void
pointcloud_classifier__msg__ClusterResultArray__destroy(pointcloud_classifier__msg__ClusterResultArray * msg);

/// Check for msg/ClusterResultArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
bool
pointcloud_classifier__msg__ClusterResultArray__are_equal(const pointcloud_classifier__msg__ClusterResultArray * lhs, const pointcloud_classifier__msg__ClusterResultArray * rhs);

/// Copy a msg/ClusterResultArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
bool
pointcloud_classifier__msg__ClusterResultArray__copy(
  const pointcloud_classifier__msg__ClusterResultArray * input,
  pointcloud_classifier__msg__ClusterResultArray * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
const rosidl_type_hash_t *
pointcloud_classifier__msg__ClusterResultArray__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
const rosidl_runtime_c__type_description__TypeDescription *
pointcloud_classifier__msg__ClusterResultArray__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
const rosidl_runtime_c__type_description__TypeSource *
pointcloud_classifier__msg__ClusterResultArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
const rosidl_runtime_c__type_description__TypeSource__Sequence *
pointcloud_classifier__msg__ClusterResultArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/ClusterResultArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * pointcloud_classifier__msg__ClusterResultArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
bool
pointcloud_classifier__msg__ClusterResultArray__Sequence__init(pointcloud_classifier__msg__ClusterResultArray__Sequence * array, size_t size);

/// Finalize array of msg/ClusterResultArray messages.
/**
 * It calls
 * pointcloud_classifier__msg__ClusterResultArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
void
pointcloud_classifier__msg__ClusterResultArray__Sequence__fini(pointcloud_classifier__msg__ClusterResultArray__Sequence * array);

/// Create array of msg/ClusterResultArray messages.
/**
 * It allocates the memory for the array and calls
 * pointcloud_classifier__msg__ClusterResultArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
pointcloud_classifier__msg__ClusterResultArray__Sequence *
pointcloud_classifier__msg__ClusterResultArray__Sequence__create(size_t size);

/// Destroy array of msg/ClusterResultArray messages.
/**
 * It calls
 * pointcloud_classifier__msg__ClusterResultArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
void
pointcloud_classifier__msg__ClusterResultArray__Sequence__destroy(pointcloud_classifier__msg__ClusterResultArray__Sequence * array);

/// Check for msg/ClusterResultArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
bool
pointcloud_classifier__msg__ClusterResultArray__Sequence__are_equal(const pointcloud_classifier__msg__ClusterResultArray__Sequence * lhs, const pointcloud_classifier__msg__ClusterResultArray__Sequence * rhs);

/// Copy an array of msg/ClusterResultArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
bool
pointcloud_classifier__msg__ClusterResultArray__Sequence__copy(
  const pointcloud_classifier__msg__ClusterResultArray__Sequence * input,
  pointcloud_classifier__msg__ClusterResultArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__FUNCTIONS_H_
