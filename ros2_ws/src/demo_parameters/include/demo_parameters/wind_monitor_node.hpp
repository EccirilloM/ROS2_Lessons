// ros2_ws/src/demo_parameters/include/demo_parameters/wind_monitor_node.hpp
#ifndef DEMO_PARAMETERS__WIND_MONITOR_NODE_HPP_
#define DEMO_PARAMETERS__WIND_MONITOR_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

namespace demo_parameters {

class WindMonitorNode : public rclcpp::Node {
public:
  WindMonitorNode();

private:
  void wind_callback(const std_msgs::msg::Float32::SharedPtr msg);

  // Variabili membro per memorizzare i parametri a runtime
  std::string wind_topic_;
  double max_wind_speed_;
  std::string warning_message_;

  // Oggetti ROS
  rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

} // namespace demo_parameters
#endif