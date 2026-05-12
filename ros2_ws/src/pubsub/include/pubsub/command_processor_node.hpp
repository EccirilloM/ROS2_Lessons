// ros2_ws/src/pubsub/include/pubsub/command_processor_node.hpp
#ifndef PUBSUB__COMMAND_PROCESSOR_NODE_HPP_
#define PUBSUB__COMMAND_PROCESSOR_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace pubsub {

class CommandProcessorNode : public rclcpp::Node {
public:
  CommandProcessorNode();

private:
  void command_callback(const std_msgs::msg::String::SharedPtr msg);

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

} // namespace pubsub

#endif // PUBSUB__COMMAND_PROCESSOR_NODE_HPP_