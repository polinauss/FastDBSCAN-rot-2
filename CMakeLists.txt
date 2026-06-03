cmake_minimum_required(VERSION 3.8)
project(pointcloud_classifier)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(PCL REQUIRED)
find_package(rosidl_default_generators REQUIRED)

include_directories(include ${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

set(MSG_FILES
  "msg/ClusterResult.msg"
  "msg/ClusterResultArray.msg"
)
rosidl_generate_interfaces(${PROJECT_NAME}
  ${MSG_FILES}
  DEPENDENCIES builtin_interfaces
)

# Узел классификатора
add_executable(classifier_node
  src/classifier_node.cpp
  src/pointcloud_processor.cpp
  src/utils.cpp
)

ament_target_dependencies(classifier_node
  rclcpp
  sensor_msgs
  pcl_conversions
  PCL
)

target_include_directories(classifier_node PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp
)

rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp"
)
target_link_libraries(classifier_node
  ${cpp_typesupport_target}
)

# Узел публикации PCD
add_executable(pcd_publisher
  src/pcd_publisher.cpp
)

ament_target_dependencies(pcd_publisher
  rclcpp
  sensor_msgs
  pcl_conversions
  PCL
)

install(TARGETS classifier_node pcd_publisher
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/ DESTINATION include)
install(DIRECTORY launch/ DESTINATION share/${PROJECT_NAME}/launch)
install(FILES
  msg/ClusterResult.msg
  msg/ClusterResultArray.msg
  DESTINATION share/${PROJECT_NAME}/msg
)

ament_package()
