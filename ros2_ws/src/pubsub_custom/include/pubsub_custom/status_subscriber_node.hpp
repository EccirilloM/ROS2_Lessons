// ros2_ws/src/pubsub_custom/include/pubsub_custom/status_subscriber_node.hpp
#ifndef PUBSUB_CUSTOM__STATUS_SUBSCRIBER_NODE_HPP_
#define PUBSUB_CUSTOM__STATUS_SUBSCRIBER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "custom_msgs/msg/boat_status.hpp" // IMPORTIAMO IL NOSTRO MESSAGGIO CUSTOM!

namespace pubsub_custom {

class StatusSubscriberNode : public rclcpp::Node {
public:
  StatusSubscriberNode();

private:
  void status_callback(const custom_msgs::msg::BoatStatus::SharedPtr msg);

  std::string topic_name_;
  rclcpp::Subscription<custom_msgs::msg::BoatStatus>::SharedPtr subscription_;
};

}
#endif