cmake_minimum_required(VERSION 3.8)
project(pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. Trova le dipendenze ROS 2
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# 2. Dichiara dove si trovano i file header (.hpp)
include_directories(include)

# 3. Crea il primo eseguibile (Publisher)
add_executable(command_generator_node
  src/command_generator_node.cpp 
  src/command_generator_main.cpp
)
ament_target_dependencies(command_generator_node rclcpp std_msgs)

# 4. Crea il secondo eseguibile (Subscriber + Publisher)
add_executable(command_processor_node
  src/command_processor_node.cpp 
  src/command_processor_main.cpp
)
ament_target_dependencies(command_processor_node rclcpp std_msgs)

# 5. Regole di installazione per gli eseguibili
install(TARGETS
  command_generator_node
  command_processor_node
  DESTINATION lib/${PROJECT_NAME}
)

# 6. Regole di installazione per i launch file (NUOVO)
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()