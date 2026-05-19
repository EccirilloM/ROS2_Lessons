// ros2_ws/src/real_case/include/real_case/dashboard_elaboration_node.hpp
#ifndef REAL_CASE__DASHBOARD_ELABORATION_NODE_HPP_
#define REAL_CASE__DASHBOARD_ELABORATION_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "std_msgs/msg/float64.hpp"
#include "custom_msgs/msg/windex_data_msg.hpp"

namespace real_case {

class DashboardElaborationNode : public rclcpp::Node {
public:
// COSTRUTTORE
  DashboardElaborationNode();

private:

//VARIABILI UTILIZZATE
  double wand_angle_porcessed_;
  double aws_calibrate_;
  double awa_calibrate_;
  double ultrasound_calibrate_;
  double roll_calibrate_;
  double pitch_calibrate_;
  double yaw_calibrate_;

// FUNZIONE PER PUBBLICARE I DATI ELABORATI
  void publish_dashboard_data();

// CALLBACK PER RICEVERE I DATI GREZZI
  void wand_callback(const std_msgs::msg::Float64::SharedPtr msg);
  void ultrasound_callback(const std_msgs::msg::Float64::SharedPtr msg);
  void windex_callback(const custom_msgs::msg::WindexDataMsg::SharedPtr msg);
  void imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg);

// SUBSCRIPTIONS
  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr wand_subscriber_;
  rclcpp::Subscription<custom_msgs::msg::WindexDataMsg>::SharedPtr windex_subscriber_;
  rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr ultrasound_subscriber_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscriber_;

// PUBLISHER
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr wand_publisher_;
  rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr ultrasound_publisher_;
  rclcpp::Publisher<custom_msgs::msg::WindexDataMsg>::SharedPtr windex_publisher_;
  rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr imu_publisher_;

// TIMER PER PUBBLICARE I DATI ELABORATI A INTERVALLI REGOLARI
  rclcpp::TimerBase::SharedPtr timer_;

};

} // namespace real_case

#endif