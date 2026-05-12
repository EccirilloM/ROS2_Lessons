// ros2_ws/src/demo_parameters/src/wind_monitor_node.cpp
#include "demo_parameters/wind_monitor_node.hpp"
#include "demo_parameters/ros_endpoints.hpp"

namespace demo_parameters {

WindMonitorNode::WindMonitorNode() : Node("wind_monitor_node") {
  // Inizializzazione di tutti i parametri in riga e assegnazione alle variabili
  wind_topic_      = ros_endpoints::WIND_MONITOR_NODE::SUB::WIND_SPEED;
  max_wind_speed_  = this->declare_parameter<double>("max_wind_speed", 20.0);
  warning_message_ = this->declare_parameter<std::string>("warning_message", "Allarme base");

  subscription_ = this->create_subscription<std_msgs::msg::Float32>(
    wind_topic_, 10, std::bind(&WindMonitorNode::wind_callback, this, std::placeholders::_1));

  RCLCPP_INFO(this->get_logger(), "Monitor in ascolto sul topic: %s", wind_topic_.c_str());
}

void WindMonitorNode::wind_callback(const std_msgs::msg::Float32::SharedPtr msg) {
  // Lettura a runtime dei parametri di logica (non del topic, che si imposta solo all'avvio)
  max_wind_speed_  = this->get_parameter("max_wind_speed").as_double();
  warning_message_ = this->get_parameter("warning_message").as_string();

  if (msg->data > max_wind_speed_) {
    RCLCPP_WARN(this->get_logger(), "%s (Attuale: %.1f, Limite: %.1f)", 
                warning_message_.c_str(), msg->data, max_wind_speed_);
  } else {
    RCLCPP_INFO(this->get_logger(), "Vento regolare: %.1f nodi", msg->data);
  }
}

} // namespace demo_parameters