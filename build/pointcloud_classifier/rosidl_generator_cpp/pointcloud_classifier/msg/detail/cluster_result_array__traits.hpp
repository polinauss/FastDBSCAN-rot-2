// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pointcloud_classifier:msg/ClusterResultArray.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pointcloud_classifier/msg/cluster_result_array.hpp"


#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__TRAITS_HPP_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pointcloud_classifier/msg/detail/cluster_result_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'clusters'
#include "pointcloud_classifier/msg/detail/cluster_result__traits.hpp"

namespace pointcloud_classifier
{

namespace msg
{

inline void to_flow_style_yaml(
  const ClusterResultArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: clusters
  {
    if (msg.clusters.size() == 0) {
      out << "clusters: []";
    } else {
      out << "clusters: [";
      size_t pending_items = msg.clusters.size();
      for (auto item : msg.clusters) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ClusterResultArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: clusters
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.clusters.size() == 0) {
      out << "clusters: []\n";
    } else {
      out << "clusters:\n";
      for (auto item : msg.clusters) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ClusterResultArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace pointcloud_classifier

namespace rosidl_generator_traits
{

[[deprecated("use pointcloud_classifier::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pointcloud_classifier::msg::ClusterResultArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  pointcloud_classifier::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pointcloud_classifier::msg::to_yaml() instead")]]
inline std::string to_yaml(const pointcloud_classifier::msg::ClusterResultArray & msg)
{
  return pointcloud_classifier::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pointcloud_classifier::msg::ClusterResultArray>()
{
  return "pointcloud_classifier::msg::ClusterResultArray";
}

template<>
inline const char * name<pointcloud_classifier::msg::ClusterResultArray>()
{
  return "pointcloud_classifier/msg/ClusterResultArray";
}

template<>
struct has_fixed_size<pointcloud_classifier::msg::ClusterResultArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pointcloud_classifier::msg::ClusterResultArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pointcloud_classifier::msg::ClusterResultArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT_ARRAY__TRAITS_HPP_
