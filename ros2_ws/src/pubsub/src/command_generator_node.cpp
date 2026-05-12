#include "pubsub/command_generator_node.hpp"
#include <chrono>

using namespace std::chrono_literals;

namespace pubsub {

CommandGeneratorNode::CommandGeneratorNode() 
: Node("command_generator_node"), counter_(0) 
{
  publisher_ = this->create_publisher<std_msgs::msg::String>("robot_command", 10);
  timer_ = this->create_wall_timer(
    2000ms, std::bind(&CommandGeneratorNode::timer_callback, this));
    
  RCLCPP_INFO(this->get_logger(), "CommandGeneratorNode avviato. Genero comandi...");
}

void CommandGeneratorNode::timer_callback() {
  std_msgs::msg::String msg;
  // Un array di comandi finti per testare il subscriber
  const char* comandi[] = {"start", "stop", "dock", "errore_voluto"};
  
  msg.data = comandi[counter_ % 4];
  counter_++;
  
  RCLCPP_INFO(this->get_logger(), "Invio comando: '%s'", msg.data.c_str());
  publisher_->publish(msg);
}

} // namespace pubsub