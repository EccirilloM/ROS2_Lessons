// ros2_ws/src/demo_parameters/include/demo_parameters/wind_publisher_node.hpp
#ifndef DEMO_PARAMETERS__WIND_PUBLISHER_NODE_HPP_
#define DEMO_PARAMETERS__WIND_PUBLISHER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

namespace demo_parameters {

class WindPublisherNode : public rclcpp::Node {
public:
  WindPublisherNode();

private:
  void timer_callback();

  // Variabili membro e parametri inizializzati in cima (come richiesto)
  std::string wind_topic_;
  double current_wind_;

  // Oggetti ROS
  rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

} // namespace demo_parameters
#endif