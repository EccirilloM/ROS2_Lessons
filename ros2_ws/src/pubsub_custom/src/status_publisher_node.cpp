// ros2_ws/src/pubsub_custom/src/status_publisher_node.cpp
#include "pubsub_custom/status_publisher_node.hpp"
#include "pubsub_custom/ros_endpoints.hpp"
#include <chrono>

using namespace std::chrono_literals;

namespace pubsub_custom {

StatusPublisherNode::StatusPublisherNode() : Node("status_publisher_node"), fake_battery_(100.0) {
  topic_name_ = ros_endpoints::STATUS_PUBLISHER_NODE::PUB::BOAT_STATUS;

  publisher_ = this->create_publisher<custom_msgs::msg::BoatStatus>(topic_name_, 10);
  timer_ = this->create_wall_timer(
    2000ms, std::bind(&StatusPublisherNode::timer_callback, this));

  RCLCPP_INFO(this->get_logger(), "Status Publisher avviato su %s", topic_name_.c_str());
}

void StatusPublisherNode::timer_callback() {
  custom_msgs::msg::BoatStatus msg;
  
  // Riempiamo i campi del nostro messaggio custom
  msg.header.stamp = this->now();
  msg.status = "Navigating";
  msg.battery_level = fake_battery_;
  msg.is_autonomous = true;

  publisher_->publish(msg);

  // Scarichiamo un po' la finta batteria
  fake_battery_ -= 0.5;
  if (fake_battery_ < 0) fake_battery_ = 100.0;

  RCLCPP_INFO(this->get_logger(), "Pubblicato stato: %s, batteria: %.1f%%", msg.status.c_str(), msg.battery_level);
}

}