// ros2_ws/src/pubsub_custom/src/status_subscriber_node.cpp
#include "pubsub_custom/status_subscriber_node.hpp"
#include "pubsub_custom/ros_endpoints.hpp"

namespace pubsub_custom {

StatusSubscriberNode::StatusSubscriberNode() : Node("status_subscriber_node") {
  topic_name_ = ros_endpoints::STATUS_SUBSCRIBER_NODE::SUB::BOAT_STATUS;

  subscription_ = this->create_subscription<custom_msgs::msg::BoatStatus>(
    topic_name_, 10, std::bind(&StatusSubscriberNode::status_callback, this, std::placeholders::_1));

  RCLCPP_INFO(this->get_logger(), "Status Subscriber avviato su %s", topic_name_.c_str());
}

void StatusSubscriberNode::status_callback(const custom_msgs::msg::BoatStatus::SharedPtr msg) {
  std::string auto_mode = msg->is_autonomous ? "SI" : "NO";
  
  RCLCPP_INFO(this->get_logger(), 
    "\n--- STATO BARCA ---\n"
    "Stato: %s\n"
    "Batteria: %.1f%%\n"
    "Guida Autonoma: %s\n",
    msg->status.c_str(), msg->battery_level, auto_mode.c_str());
}

}