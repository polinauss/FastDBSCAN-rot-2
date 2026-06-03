// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pointcloud_classifier:msg/ClusterResultArray.idl
// generated code does not contain a copyright notice
#include "pointcloud_classifier/msg/detail/cluster_result_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `clusters`
#include "pointcloud_classifier/msg/detail/cluster_result__functions.h"

bool
pointcloud_classifier__msg__ClusterResultArray__init(pointcloud_classifier__msg__ClusterResultArray * msg)
{
  if (!msg) {
    return false;
  }
  // clusters
  if (!pointcloud_classifier__msg__ClusterResult__Sequence__init(&msg->clusters, 0)) {
    pointcloud_classifier__msg__ClusterResultArray__fini(msg);
    return false;
  }
  return true;
}

void
pointcloud_classifier__msg__ClusterResultArray__fini(pointcloud_classifier__msg__ClusterResultArray * msg)
{
  if (!msg) {
    return;
  }
  // clusters
  pointcloud_classifier__msg__ClusterResult__Sequence__fini(&msg->clusters);
}

bool
pointcloud_classifier__msg__ClusterResultArray__are_equal(const pointcloud_classifier__msg__ClusterResultArray * lhs, const pointcloud_classifier__msg__ClusterResultArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // clusters
  if (!pointcloud_classifier__msg__ClusterResult__Sequence__are_equal(
      &(lhs->clusters), &(rhs->clusters)))
  {
    return false;
  }
  return true;
}

bool
pointcloud_classifier__msg__ClusterResultArray__copy(
  const pointcloud_classifier__msg__ClusterResultArray * input,
  pointcloud_classifier__msg__ClusterResultArray * output)
{
  if (!input || !output) {
    return false;
  }
  // clusters
  if (!pointcloud_classifier__msg__ClusterResult__Sequence__copy(
      &(input->clusters), &(output->clusters)))
  {
    return false;
  }
  return true;
}

pointcloud_classifier__msg__ClusterResultArray *
pointcloud_classifier__msg__ClusterResultArray__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pointcloud_classifier__msg__ClusterResultArray * msg = (pointcloud_classifier__msg__ClusterResultArray *)allocator.allocate(sizeof(pointcloud_classifier__msg__ClusterResultArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pointcloud_classifier__msg__ClusterResultArray));
  bool success = pointcloud_classifier__msg__ClusterResultArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pointcloud_classifier__msg__ClusterResultArray__destroy(pointcloud_classifier__msg__ClusterResultArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pointcloud_classifier__msg__ClusterResultArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pointcloud_classifier__msg__ClusterResultArray__Sequence__init(pointcloud_classifier__msg__ClusterResultArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pointcloud_classifier__msg__ClusterResultArray * data = NULL;

  if (size) {
    data = (pointcloud_classifier__msg__ClusterResultArray *)allocator.zero_allocate(size, sizeof(pointcloud_classifier__msg__ClusterResultArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pointcloud_classifier__msg__ClusterResultArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pointcloud_classifier__msg__ClusterResultArray__fini(&data[i - 1]);
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
pointcloud_classifier__msg__ClusterResultArray__Sequence__fini(pointcloud_classifier__msg__ClusterResultArray__Sequence * array)
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
      pointcloud_classifier__msg__ClusterResultArray__fini(&array->data[i]);
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

pointcloud_classifier__msg__ClusterResultArray__Sequence *
pointcloud_classifier__msg__ClusterResultArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pointcloud_classifier__msg__ClusterResultArray__Sequence * array = (pointcloud_classifier__msg__ClusterResultArray__Sequence *)allocator.allocate(sizeof(pointcloud_classifier__msg__ClusterResultArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pointcloud_classifier__msg__ClusterResultArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pointcloud_classifier__msg__ClusterResultArray__Sequence__destroy(pointcloud_classifier__msg__ClusterResultArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pointcloud_classifier__msg__ClusterResultArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pointcloud_classifier__msg__ClusterResultArray__Sequence__are_equal(const pointcloud_classifier__msg__ClusterResultArray__Sequence * lhs, const pointcloud_classifier__msg__ClusterResultArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pointcloud_classifier__msg__ClusterResultArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pointcloud_classifier__msg__ClusterResultArray__Sequence__copy(
  const pointcloud_classifier__msg__ClusterResultArray__Sequence * input,
  pointcloud_classifier__msg__ClusterResultArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pointcloud_classifier__msg__ClusterResultArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pointcloud_classifier__msg__ClusterResultArray * data =
      (pointcloud_classifier__msg__ClusterResultArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pointcloud_classifier__msg__ClusterResultArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pointcloud_classifier__msg__ClusterResultArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pointcloud_classifier__msg__ClusterResultArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
