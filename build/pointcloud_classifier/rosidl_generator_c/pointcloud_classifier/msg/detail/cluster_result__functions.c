// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pointcloud_classifier:msg/ClusterResult.idl
// generated code does not contain a copyright notice
#include "pointcloud_classifier/msg/detail/cluster_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `type_name`
#include "rosidl_runtime_c/string_functions.h"

bool
pointcloud_classifier__msg__ClusterResult__init(pointcloud_classifier__msg__ClusterResult * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // type_name
  if (!rosidl_runtime_c__String__init(&msg->type_name)) {
    pointcloud_classifier__msg__ClusterResult__fini(msg);
    return false;
  }
  // type_code
  // center_x
  // center_y
  // center_z
  // num_points
  // width
  // height
  // depth
  // density
  return true;
}

void
pointcloud_classifier__msg__ClusterResult__fini(pointcloud_classifier__msg__ClusterResult * msg)
{
  if (!msg) {
    return;
  }
  // id
  // type_name
  rosidl_runtime_c__String__fini(&msg->type_name);
  // type_code
  // center_x
  // center_y
  // center_z
  // num_points
  // width
  // height
  // depth
  // density
}

bool
pointcloud_classifier__msg__ClusterResult__are_equal(const pointcloud_classifier__msg__ClusterResult * lhs, const pointcloud_classifier__msg__ClusterResult * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // type_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type_name), &(rhs->type_name)))
  {
    return false;
  }
  // type_code
  if (lhs->type_code != rhs->type_code) {
    return false;
  }
  // center_x
  if (lhs->center_x != rhs->center_x) {
    return false;
  }
  // center_y
  if (lhs->center_y != rhs->center_y) {
    return false;
  }
  // center_z
  if (lhs->center_z != rhs->center_z) {
    return false;
  }
  // num_points
  if (lhs->num_points != rhs->num_points) {
    return false;
  }
  // width
  if (lhs->width != rhs->width) {
    return false;
  }
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // depth
  if (lhs->depth != rhs->depth) {
    return false;
  }
  // density
  if (lhs->density != rhs->density) {
    return false;
  }
  return true;
}

bool
pointcloud_classifier__msg__ClusterResult__copy(
  const pointcloud_classifier__msg__ClusterResult * input,
  pointcloud_classifier__msg__ClusterResult * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // type_name
  if (!rosidl_runtime_c__String__copy(
      &(input->type_name), &(output->type_name)))
  {
    return false;
  }
  // type_code
  output->type_code = input->type_code;
  // center_x
  output->center_x = input->center_x;
  // center_y
  output->center_y = input->center_y;
  // center_z
  output->center_z = input->center_z;
  // num_points
  output->num_points = input->num_points;
  // width
  output->width = input->width;
  // height
  output->height = input->height;
  // depth
  output->depth = input->depth;
  // density
  output->density = input->density;
  return true;
}

pointcloud_classifier__msg__ClusterResult *
pointcloud_classifier__msg__ClusterResult__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pointcloud_classifier__msg__ClusterResult * msg = (pointcloud_classifier__msg__ClusterResult *)allocator.allocate(sizeof(pointcloud_classifier__msg__ClusterResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pointcloud_classifier__msg__ClusterResult));
  bool success = pointcloud_classifier__msg__ClusterResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pointcloud_classifier__msg__ClusterResult__destroy(pointcloud_classifier__msg__ClusterResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pointcloud_classifier__msg__ClusterResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pointcloud_classifier__msg__ClusterResult__Sequence__init(pointcloud_classifier__msg__ClusterResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pointcloud_classifier__msg__ClusterResult * data = NULL;

  if (size) {
    data = (pointcloud_classifier__msg__ClusterResult *)allocator.zero_allocate(size, sizeof(pointcloud_classifier__msg__ClusterResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pointcloud_classifier__msg__ClusterResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pointcloud_classifier__msg__ClusterResult__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pointcloud_classifier__msg__ClusterResult__Sequence__fini(pointcloud_classifier__msg__ClusterResult__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pointcloud_classifier__msg__ClusterResult__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pointcloud_classifier__msg__ClusterResult__Sequence *
pointcloud_classifier__msg__ClusterResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pointcloud_classifier__msg__ClusterResult__Sequence * array = (pointcloud_classifier__msg__ClusterResult__Sequence *)allocator.allocate(sizeof(pointcloud_classifier__msg__ClusterResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pointcloud_classifier__msg__ClusterResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pointcloud_classifier__msg__ClusterResult__Sequence__destroy(pointcloud_classifier__msg__ClusterResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pointcloud_classifier__msg__ClusterResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pointcloud_classifier__msg__ClusterResult__Sequence__are_equal(const pointcloud_classifier__msg__ClusterResult__Sequence * lhs, const pointcloud_classifier__msg__ClusterResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pointcloud_classifier__msg__ClusterResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pointcloud_classifier__msg__ClusterResult__Sequence__copy(
  const pointcloud_classifier__msg__ClusterResult__Sequence * input,
  pointcloud_classifier__msg__ClusterResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pointcloud_classifier__msg__ClusterResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pointcloud_classifier__msg__ClusterResult * data =
      (pointcloud_classifier__msg__ClusterResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pointcloud_classifier__msg__ClusterResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pointcloud_classifier__msg__ClusterResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pointcloud_classifier__msg__ClusterResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
