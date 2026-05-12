// ros2_ws/src/pubsub_custom/include/pubsub_custom/status_publisher_node.hpp
#ifndef PUBSUB_CUSTOM__STATUS_PUBLISHER_NODE_HPP_
#define PUBSUB_CUSTOM__STATUS_PUBLISHER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "custom_msgs/msg/boat_status.hpp" // IMPORTIAMO IL NOSTRO MESSAGGIO CUSTOM!

namespace pubsub_custom {

class StatusPublisherNode : public rclcpp::Node {
public:
  StatusPublisherNode();

private:
  void timer_callback();

  std::string topic_name_;
  float fake_battery_;

  rclcpp::Publisher<custom_msgs::msg::BoatStatus>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

}
#endif