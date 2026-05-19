// ros2_ws/src/real_case/include/real_case/central_node.hpp
#ifndef REAL_CASE__CENTRAL_NODE_HPP_
#define REAL_CASE__CENTRAL_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "std_msgs/msg/float64.hpp"
#include "custom_msgs/msg/windex_data_msg.hpp" // <-- IL TUO MESSAGGIO CUSTOM

namespace real_case {

class CentralNode : public rclcpp::Node {
public:
  CentralNode();

private:
  void timer_callback();

  // Publishers aggiornati
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr pot_pub_;
  rclcpp::Publisher<custom_msgs::msg::WindexDataMsg>::SharedPtr windex_pub_; // <--
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr ultrasound_pub_;

  // Timer principale
  rclcpp::TimerBase::SharedPtr timer_;

  // Variabili di stato
  double time_counter_;
  double loop_period_sec_;
};

} // namespace real_case

#endif