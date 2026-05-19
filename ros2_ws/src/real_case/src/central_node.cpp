#include "real_case/central_node.hpp"
#include "real_case/ros_endpoints.hpp" 
#include <cmath>

using namespace std::chrono_literals;

namespace real_case {

CentralNode::CentralNode() : Node("central_node"), time_counter_(0.0) {
  
  imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>(
    ros_endpoints::CENTRAL_NODE::PUB::IMU_DATA, 10);
    
  pot_pub_ = this->create_publisher<std_msgs::msg::Float64>(
    ros_endpoints::CENTRAL_NODE::PUB::WAND_ANGLE, 10);
    
  // Publisher custom
  windex_pub_ = this->create_publisher<custom_msgs::msg::WindexDataMsg>(
    ros_endpoints::CENTRAL_NODE::PUB::WINDEX_DATA, 10);
    
  ultrasound_pub_ = this->create_publisher<std_msgs::msg::Float64>(
    ros_endpoints::CENTRAL_NODE::PUB::ULTRASOUND_DATA, 10);

  int loop_freq_hz = 50;
  loop_period_sec_ = 1.0 / loop_freq_hz;
  
  timer_ = this->create_wall_timer(
    std::chrono::milliseconds(20), 
    std::bind(&CentralNode::timer_callback, this));

  RCLCPP_INFO(this->get_logger(), "Mock Central Node avviato a 50Hz con custom msgs!");
}

void CentralNode::timer_callback() {
  time_counter_ += loop_period_sec_;
  auto current_time = this->now();

  // --- 1. IMU ---
  sensor_msgs::msg::Imu imu_msg;
  imu_msg.header.stamp = current_time;
  imu_msg.header.frame_id = "imu_link";
  double roll_rad = 15.0 * (M_PI / 180.0) * std::sin(time_counter_ * 0.5); 
  imu_msg.orientation.x = roll_rad;
  imu_msg.orientation.w = 1.0; 
  imu_msg.linear_acceleration.z = 9.81; 
  imu_pub_->publish(imu_msg);

  // --- 2. WAND ANGLE ---
  std_msgs::msg::Float64 pot_msg;
  pot_msg.data = 0.75 + 0.75 * std::sin(time_counter_ * 2.0); 
  pot_pub_->publish(pot_msg);

  // --- 3. WINDEX (Ora usiamo WindexDataMsg!) ---
  custom_msgs::msg::WindexDataMsg windex_msg;
  windex_msg.stamp = current_time; // rclcpp::Time si converte in automatico in builtin_interfaces/Time
  windex_msg.aws = 10.0 + 5.0 * std::sin(time_counter_ * 0.1);  // Vento varia da 5 a 15 nodi
  windex_msg.awa = 180.0 * std::sin(time_counter_ * 0.05);      // Angolo da -180 a +180 gradi
  windex_pub_->publish(windex_msg);

  // --- 4. ULTRASUONI ---
  std_msgs::msg::Float64 ultra_msg;
  ultra_msg.data = 1.0 + 0.2 * std::sin(time_counter_ * 1.5);
  ultrasound_pub_->publish(ultra_msg);

  // --- 5. DEBUG PRINT (Throttled) ---
  // Stampa i dati a schermo SOLO 1 volta al secondo (1000 millisecondi)
  // RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
  //   "Dati: Roll(%.2f rad) | Wand(%.2f rad) | Vento(%.1f kn, %.1f°) | Ultrasuoni(%.2f m)",
  //   roll_rad, pot_msg.data, windex_msg.aws, windex_msg.awa, ultra_msg.data);
}

} // namespace real_case

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<real_case::CentralNode>());
  rclcpp::shutdown();
  return 0;
}