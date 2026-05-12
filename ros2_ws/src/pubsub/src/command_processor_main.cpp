#include "pubsub/command_processor_node.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<pubsub::CommandProcessorNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}