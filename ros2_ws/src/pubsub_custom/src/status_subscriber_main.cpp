// ros2_ws/src/pubsub_custom/src/status_subscriber_main.cpp
#include "pubsub_custom/status_subscriber_node.hpp"

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<pubsub_custom::StatusSubscriberNode>());
  rclcpp::shutdown();
  return 0;
}