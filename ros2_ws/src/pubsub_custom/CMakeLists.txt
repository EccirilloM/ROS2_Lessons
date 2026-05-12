cmake_minimum_required(VERSION 3.8)
project(pubsub_custom)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_msgs REQUIRED) # DIPENDENZA DAL NOSTRO PACCHETTO

include_directories(include)

add_executable(status_publisher_node src/status_publisher_node.cpp src/status_publisher_main.cpp)
ament_target_dependencies(status_publisher_node rclcpp custom_msgs)

add_executable(status_subscriber_node src/status_subscriber_node.cpp src/status_subscriber_main.cpp)
ament_target_dependencies(status_subscriber_node rclcpp custom_msgs)

install(TARGETS status_publisher_node status_subscriber_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME})

ament_package()