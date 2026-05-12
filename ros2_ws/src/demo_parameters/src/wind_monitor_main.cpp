// ros2_ws/src/demo_parameters/src/wind_monitor_main.cpp
#include "demo_parameters/wind_monitor_node.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<demo_parameters::WindMonitorNode>());
  rclcpp::shutdown();
  return 0;
}