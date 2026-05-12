// ros2_ws/src/pubsub/include/pubsub/command_generator_node.hpp
#ifndef PUBSUB__COMMAND_GENERATOR_NODE_HPP_
#define PUBSUB__COMMAND_GENERATOR_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace pubsub {

class CommandGeneratorNode : public rclcpp::Node {
public:
  CommandGeneratorNode();

private:
  void timer_callback();

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  size_t counter_;
};

} // namespace pubsub

#endif // PUBSUB__COMMAND_GENERATOR_NODE_HPP_