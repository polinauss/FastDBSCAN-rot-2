// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from pointcloud_classifier:msg/ClusterResultArray.idl
// generated code does not contain a copyright notice

#include "pointcloud_classifier/msg/detail/cluster_result_array__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_pointcloud_classifier
const rosidl_type_hash_t *
pointcloud_classifier__msg__ClusterResultArray__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfb, 0x45, 0x42, 0x85, 0xee, 0xe3, 0x34, 0x78,
      0xd1, 0x73, 0x0e, 0x9a, 0xb9, 0xcf, 0x35, 0xa6,
      0x03, 0xb5, 0x42, 0x47, 0x67, 0xb2, 0x8f, 0xf9,
      0xfb, 0x57, 0x40, 0x65, 0xe0, 0xab, 0x32, 0x8a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "pointcloud_classifier/msg/detail/cluster_result__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t pointcloud_classifier__msg__ClusterResult__EXPECTED_HASH = {1, {
    0xc5, 0x33, 0x87, 0x6a, 0x38, 0x99, 0x71, 0x03,
    0x1d, 0x82, 0xc6, 0x7d, 0xb6, 0x04, 0x1c, 0x5d,
    0x99, 0xb0, 0xad, 0xdc, 0x70, 0x93, 0x0e, 0x4b,
    0xd6, 0x5d, 0x41, 0xfa, 0x3b, 0x42, 0x64, 0xf7,
  }};
#endif

static char pointcloud_classifier__msg__ClusterResultArray__TYPE_NAME[] = "pointcloud_classifier/msg/ClusterResultArray";
static char pointcloud_classifier__msg__ClusterResult__TYPE_NAME[] = "pointcloud_classifier/msg/ClusterResult";

// Define type names, field names, and default values
static char pointcloud_classifier__msg__ClusterResultArray__FIELD_NAME__clusters[] = "clusters";

static rosidl_runtime_c__type_description__Field pointcloud_classifier__msg__ClusterResultArray__FIELDS[] = {
  {
    {pointcloud_classifier__msg__ClusterResultArray__FIELD_NAME__clusters, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {pointcloud_classifier__msg__ClusterResult__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription pointcloud_classifier__msg__ClusterResultArray__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {pointcloud_classifier__msg__ClusterResult__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
pointcloud_classifier__msg__ClusterResultArray__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {pointcloud_classifier__msg__ClusterResultArray__TYPE_NAME, 44, 44},
      {pointcloud_classifier__msg__ClusterResultArray__FIELDS, 1, 1},
    },
    {pointcloud_classifier__msg__ClusterResultArray__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&pointcloud_classifier__msg__ClusterResult__EXPECTED_HASH, pointcloud_classifier__msg__ClusterResult__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = pointcloud_classifier__msg__ClusterResult__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "pointcloud_classifier/ClusterResult[] clusters";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
pointcloud_classifier__msg__ClusterResultArray__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {pointcloud_classifier__msg__ClusterResultArray__TYPE_NAME, 44, 44},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 47, 47},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
pointcloud_classifier__msg__ClusterResultArray__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *pointcloud_classifier__msg__ClusterResultArray__get_individual_type_description_source(NULL),
    sources[1] = *pointcloud_classifier__msg__ClusterResult__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
