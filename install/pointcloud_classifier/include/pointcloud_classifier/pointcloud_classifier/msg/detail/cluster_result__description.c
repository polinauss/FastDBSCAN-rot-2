// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from pointcloud_classifier:msg/ClusterResult.idl
// generated code does not contain a copyright notice

#include "pointcloud_classifier/msg/detail/cluster_result__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
const rosidl_type_hash_t *
pointcloud_classifier__msg__ClusterResult__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc5, 0x33, 0x87, 0x6a, 0x38, 0x99, 0x71, 0x03,
      0x1d, 0x82, 0xc6, 0x7d, 0xb6, 0x04, 0x1c, 0x5d,
      0x99, 0xb0, 0xad, 0xdc, 0x70, 0x93, 0x0e, 0x4b,
      0xd6, 0x5d, 0x41, 0xfa, 0x3b, 0x42, 0x64, 0xf7,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char pointcloud_classifier__msg__ClusterResult__TYPE_NAME[] = "pointcloud_classifier/msg/ClusterResult";

// Define type names, field names, and default values
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__id[] = "id";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__type_name[] = "type_name";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__type_code[] = "type_code";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__center_x[] = "center_x";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__center_y[] = "center_y";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__center_z[] = "center_z";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__num_points[] = "num_points";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__width[] = "width";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__height[] = "height";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__depth[] = "depth";
static char pointcloud_classifier__msg__ClusterResult__FIELD_NAME__density[] = "density";

static rosidl_runtime_c__type_description__Field pointcloud_classifier__msg__ClusterResult__FIELDS[] = {
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__type_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__type_code, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__center_x, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__center_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__center_z, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__num_points, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__depth, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {pointcloud_classifier__msg__ClusterResult__FIELD_NAME__density, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
pointcloud_classifier__msg__ClusterResult__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pointcloud_classifier__msg__ClusterResult__TYPE_NAME, 39, 39},
      {pointcloud_classifier__msg__ClusterResult__FIELDS, 11, 11},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 id\n"
  "string type_name\n"
  "int32 type_code\n"
  "float32 center_x\n"
  "float32 center_y\n"
  "float32 center_z\n"
  "int32 num_points\n"
  "float32 width\n"
  "float32 height\n"
  "float32 depth\n"
  "float32 density";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
pointcloud_classifier__msg__ClusterResult__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pointcloud_classifier__msg__ClusterResult__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 169, 169},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pointcloud_classifier__msg__ClusterResult__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pointcloud_classifier__msg__ClusterResult__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
