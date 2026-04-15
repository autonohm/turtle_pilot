cmake_minimum_required(VERSION 3.8)
project(turtle_pilot)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

add_executable(turtle_pilot_node
  src/turtle_pilot_node.cpp
  src/TurtlePilot.cpp
)

target_include_directories(turtle_pilot_node PUBLIC
 ${PROJECT_SOURCE_DIR}/include
)

ament_target_dependencies(turtle_pilot_node
  rclcpp
  std_msgs
  geometry_msgs
  turtlesim
)

install(TARGETS
  turtle_pilot_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()