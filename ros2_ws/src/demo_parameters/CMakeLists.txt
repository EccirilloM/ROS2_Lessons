cmake_minimum_required(VERSION 3.8)
project(demo_parameters)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

# Eseguibile Publisher
add_executable(wind_publisher_node
  src/wind_publisher_node.cpp 
  src/wind_publisher_main.cpp)
ament_target_dependencies(wind_publisher_node rclcpp std_msgs)

# Eseguibile Monitor
add_executable(wind_monitor_node
  src/wind_monitor_node.cpp 
  src/wind_monitor_main.cpp)
ament_target_dependencies(wind_monitor_node rclcpp std_msgs)

# Installazione binari
install(TARGETS wind_publisher_node wind_monitor_node
  DESTINATION lib/${PROJECT_NAME})

# Installazione directory config e launch
install(DIRECTORY launch config
  DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()