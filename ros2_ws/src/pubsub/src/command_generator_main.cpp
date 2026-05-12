#include "pubsub/command_generator_node.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<pubsub::CommandGeneratorNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}