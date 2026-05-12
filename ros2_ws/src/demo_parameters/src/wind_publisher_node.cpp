// ros2_ws/src/demo_parameters/src/wind_publisher_node.cpp
#include "demo_parameters/wind_publisher_node.hpp"
#include "demo_parameters/ros_endpoints.hpp"
#include <chrono>

using namespace std::chrono_literals;

namespace demo_parameters {

WindPublisherNode::WindPublisherNode() : Node("wind_publisher_node"), current_wind_(10.0) {
  // Ora peschiamo il topic esplicitamente dalla sezione "pub" di questo nodo
  wind_topic_ = ros_endpoints::WIND_PUBLISHER_NODE::PUB::WIND_SPEED;

  publisher_ = this->create_publisher<std_msgs::msg::Float32>(wind_topic_, 10);
  timer_ = this->create_wall_timer(
    1000ms, std::bind(&WindPublisherNode::timer_callback, this));

  RCLCPP_INFO(this->get_logger(), "Publisher avviato sul topic: %s", wind_topic_.c_str());
}

void WindPublisherNode::timer_callback() {
  std_msgs::msg::Float32 msg;
  msg.data = current_wind_;
  publisher_->publish(msg);

  current_wind_ += 1.5;
  if (current_wind_ > 25.0) {
    current_wind_ = 10.0;
  }

  RCLCPP_INFO(this->get_logger(), "Pubblicato vento: %.1f nodi", msg.data);
}

} // namespace demo_parameters