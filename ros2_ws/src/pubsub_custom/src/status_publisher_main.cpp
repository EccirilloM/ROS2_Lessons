// ros2_ws/src/pubsub_custom/src/status_publisher_main.cpp
#include "pubsub_custom/status_publisher_node.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<pubsub_custom::StatusPublisherNode>());
  rclcpp::shutdown();
  return 0;
}