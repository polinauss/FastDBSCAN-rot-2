// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from pointcloud_classifier:msg/ClusterResultArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "pointcloud_classifier/msg/detail/cluster_result_array__functions.h"
#include "pointcloud_classifier/msg/detail/cluster_result_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace pointcloud_classifier
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ClusterResultArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) pointcloud_classifier::msg::ClusterResultArray(_init);
}

void ClusterResultArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<pointcloud_classifier::msg::ClusterResultArray *>(message_memory);
  typed_message->~ClusterResultArray();
}

size_t size_function__ClusterResultArray__clusters(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<pointcloud_classifier::msg::ClusterResult> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ClusterResultArray__clusters(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<pointcloud_classifier::msg::ClusterResult> *>(untyped_member);
  return &member[index];
}

void * get_function__ClusterResultArray__clusters(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<pointcloud_classifier::msg::ClusterResult> *>(untyped_member);
  return &member[index];
}

void fetch_function__ClusterResultArray__clusters(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const pointcloud_classifier::msg::ClusterResult *>(
    get_const_function__ClusterResultArray__clusters(untyped_member, index));
  auto & value = *reinterpret_cast<pointcloud_classifier::msg::ClusterResult *>(untyped_value);
  value = item;
}

void assign_function__ClusterResultArray__clusters(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<pointcloud_classifier::msg::ClusterResult *>(
    get_function__ClusterResultArray__clusters(untyped_member, index));
  const auto & value = *reinterpret_cast<const pointcloud_classifier::msg::ClusterResult *>(untyped_value);
  item = value;
}

void resize_function__ClusterResultArray__clusters(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<pointcloud_classifier::msg::ClusterResult> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ClusterResultArray_message_member_array[1] = {
  {
    "clusters",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<pointcloud_classifier::msg::ClusterResult>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pointcloud_classifier::msg::ClusterResultArray, clusters),  // bytes offset in struct
    nullptr,  // default value
    size_function__ClusterResultArray__clusters,  // size() function pointer
    get_const_function__ClusterResultArray__clusters,  // get_const(index) function pointer
    get_function__ClusterResultArray__clusters,  // get(index) function pointer
    fetch_function__ClusterResultArray__clusters,  // fetch(index, &value) function pointer
    assign_function__ClusterResultArray__clusters,  // assign(index, value) function pointer
    resize_function__ClusterResultArray__clusters  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ClusterResultArray_message_members = {
  "pointcloud_classifier::msg",  // message namespace
  "ClusterResultArray",  // message name
  1,  // number of fields
  sizeof(pointcloud_classifier::msg::ClusterResultArray),
  false,  // has_any_key_member_
  ClusterResultArray_message_member_array,  // message members
  ClusterResultArray_init_function,  // function to initialize message memory (memory has to be allocated)
  ClusterResultArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ClusterResultArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ClusterResultArray_message_members,
  get_message_typesupport_handle_function,
  &pointcloud_classifier__msg__ClusterResultArray__get_type_hash,
  &pointcloud_classifier__msg__ClusterResultArray__get_type_description,
  &pointcloud_classifier__msg__ClusterResultArray__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace pointcloud_classifier


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<pointcloud_classifier::msg::ClusterResultArray>()
{
  return &::pointcloud_classifier::msg::rosidl_typesupport_introspection_cpp::ClusterResultArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, pointcloud_classifier, msg, ClusterResultArray)() {
  return &::pointcloud_classifier::msg::rosidl_typesupport_introspection_cpp::ClusterResultArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
