// ros2_ws/src/demo_parameters/src/wind_publisher_main.cpp
#include "demo_parameters/wind_publisher_node.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<demo_parameters::WindPublisherNode>());
  rclcpp::shutdown();
  return 0;
}