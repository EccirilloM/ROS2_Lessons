#include "pubsub/command_processor_node.hpp"
#include <algorithm>
#include <cctype>

namespace pubsub {

CommandProcessorNode::CommandProcessorNode() 
: Node("command_processor_node") 
{
  publisher_ = this->create_publisher<std_msgs::msg::String>("robot_status", 10);
  
  subscription_ = this->create_subscription<std_msgs::msg::String>(
    "robot_command", 10, 
    std::bind(&CommandProcessorNode::command_callback, this, std::placeholders::_1));

  RCLCPP_INFO(this->get_logger(), "CommandProcessorNode pronto.");
}

void CommandProcessorNode::command_callback(const std_msgs::msg::String::SharedPtr msg) {
  const std::string command = msg->data;
  std_msgs::msg::String response;

  if (command == "start") {
    response.data = "Stato: IN NAVIGAZIONE";
  } else if (command == "stop") {
    response.data = "Stato: FERMO";
  } else if (command == "dock") {
    response.data = "Stato: IN FASE DI ATTRACCO";
  } else {
    std::string upper = command;
    std::transform(upper.begin(), upper.end(), upper.begin(), 
      [](unsigned char c) { return std::toupper(c); });
    response.data = "ERRORE SCONOSCIUTO -> " + upper;
  }

  RCLCPP_INFO(this->get_logger(), "Ricevuto: '%s' | Rispondo: '%s'", 
              command.c_str(), response.data.c_str());
  publisher_->publish(response);
}

} // namespace pubsub