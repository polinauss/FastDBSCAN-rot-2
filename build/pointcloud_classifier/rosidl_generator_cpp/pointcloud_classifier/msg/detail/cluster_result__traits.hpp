// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pointcloud_classifier:msg/ClusterResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "pointcloud_classifier/msg/cluster_result.hpp"


#ifndef POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__TRAITS_HPP_
#define POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pointcloud_classifier/msg/detail/cluster_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace pointcloud_classifier
{

namespace msg
{

inline void to_flow_style_yaml(
  const ClusterResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: type_name
  {
    out << "type_name: ";
    rosidl_generator_traits::value_to_yaml(msg.type_name, out);
    out << ", ";
  }

  // member: type_code
  {
    out << "type_code: ";
    rosidl_generator_traits::value_to_yaml(msg.type_code, out);
    out << ", ";
  }

  // member: center_x
  {
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << ", ";
  }

  // member: center_y
  {
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << ", ";
  }

  // member: center_z
  {
    out << "center_z: ";
    rosidl_generator_traits::value_to_yaml(msg.center_z, out);
    out << ", ";
  }

  // member: num_points
  {
    out << "num_points: ";
    rosidl_generator_traits::value_to_yaml(msg.num_points, out);
    out << ", ";
  }

  // member: width
  {
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << ", ";
  }

  // member: height
  {
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << ", ";
  }

  // member: depth
  {
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << ", ";
  }

  // member: density
  {
    out << "density: ";
    rosidl_generator_traits::value_to_yaml(msg.density, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ClusterResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: type_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_name: ";
    rosidl_generator_traits::value_to_yaml(msg.type_name, out);
    out << "\n";
  }

  // member: type_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_code: ";
    rosidl_generator_traits::value_to_yaml(msg.type_code, out);
    out << "\n";
  }

  // member: center_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << "\n";
  }

  // member: center_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << "\n";
  }

  // member: center_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_z: ";
    rosidl_generator_traits::value_to_yaml(msg.center_z, out);
    out << "\n";
  }

  // member: num_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num_points: ";
    rosidl_generator_traits::value_to_yaml(msg.num_points, out);
    out << "\n";
  }

  // member: width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "width: ";
    rosidl_generator_traits::value_to_yaml(msg.width, out);
    out << "\n";
  }

  // member: height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height: ";
    rosidl_generator_traits::value_to_yaml(msg.height, out);
    out << "\n";
  }

  // member: depth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "depth: ";
    rosidl_generator_traits::value_to_yaml(msg.depth, out);
    out << "\n";
  }

  // member: density
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "density: ";
    rosidl_generator_traits::value_to_yaml(msg.density, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ClusterResult & msg, bool use_flow_style = false)
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
  const pointcloud_classifier::msg::ClusterResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  pointcloud_classifier::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pointcloud_classifier::msg::to_yaml() instead")]]
inline std::string to_yaml(const pointcloud_classifier::msg::ClusterResult & msg)
{
  return pointcloud_classifier::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pointcloud_classifier::msg::ClusterResult>()
{
  return "pointcloud_classifier::msg::ClusterResult";
}

template<>
inline const char * name<pointcloud_classifier::msg::ClusterResult>()
{
  return "pointcloud_classifier/msg/ClusterResult";
}

template<>
struct has_fixed_size<pointcloud_classifier::msg::ClusterResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pointcloud_classifier::msg::ClusterResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pointcloud_classifier::msg::ClusterResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // POINTCLOUD_CLASSIFIER__MSG__DETAIL__CLUSTER_RESULT__TRAITS_HPP_
