// ros2_ws/src/real_case/src/dashboard_elaboration_node.cpp
#include "real_case/dashboard_elaboration_node.hpp"
#include "real_case/ros_endpoints.hpp"
#include <cmath>

using namespace std::chrono_literals;

namespace real_case {

DashboardElaborationNode::DashboardElaborationNode() : Node("dashboard_elaboration_node"),
    wand_angle_processed_(0.0),
    aws_calibrate_(0.0),
    ultrasound_calibrate_(0.0),
    roll_calibrate_(0.0),
    pitch_calibrate_(0.0),
    yaw_calibrate_(0.0)
 {

    // SUBSCRIPTIONS
    wand_subscriber_ = this->create_subscription<std_msgs::msg::Float64>(
        ros_endpoints::DASHBOARD_ELABORATION_NODE::SUB::WAND_ANGLE, 10,
        std::bind(&DashboardElaborationNode::wand_callback, this, std::placeholders::_1));

    ultrasound_subscriber_ = this->create_subscription<std_msgs::msg::Float64>(
        ros_endpoints::DASHBOARD_ELABORATION_NODE::SUB::ULTRASOUND_DATA, 10,
        std::bind(&DashboardElaborationNode::ultrasound_callback, this, std::placeholders::_1));

    windex_subscriber_ = this->create_subscription<custom_msgs::msg::WindexDataMsg>(
        ros_endpoints::DASHBOARD_ELABORATION_NODE::SUB::WINDEX_DATA, 10,
        std::bind(&DashboardElaborationNode::windex_callback, this, std::placeholders::_1));

    imu_subscriber_ = this->create_subscription<sensor_msgs::msg::Imu>(
        ros_endpoints::DASHBOARD_ELABORATION_NODE::SUB::IMU_DATA, 10,
        std::bind(&DashboardElaborationNode::imu_callback, this, std::placeholders::_1));

    // PUBLISHER
    wand_publisher_ = this->create_publisher<std_msgs::msg::Float64>(
        ros_endpoints::DASHBOARD_ELABORATION_NODE::PUB::PROCESSED_WAND_ANGLE, 10);

    ultrasound_publisher_ = this->create_publisher<std_msgs::msg::Float64>(
        ros_endpoints::DASHBOARD_ELABORATION_NODE::PUB::PROCESSED_ULTRASOUND_DATA, 10);

    windex_publisher_ = this->create_publisher<custom_msgs::msg::WindexDataMsg>(
        ros_endpoints::DASHBOARD_ELABORATION_NODE::PUB::PROCESSED_WINDEX_DATA, 10);

    imu_publisher_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        ros_endpoints::DASHBOARD_ELABORATION_NODE::PUB::PROCESSED_IMU_DATA, 10);

    // TIMER PER PUBBLICARE I DATI ELABORATI A INTERVALLI REGOLARI
    timer_ = this->create_wall_timer(
        1000ms, std::bind(&DashboardElaborationNode::publish_dashboard_data, this));

    RCLCPP_INFO(this->get_logger(), "Dashboard Elaboration Node avviato.");

}

void DashboardElaborationNode::wand_callback(const std_msgs::msg::Float64::SharedPtr msg) {
    wand_angle_processed_ = msg->data * (180.0 / M_PI);
}

void DashboardElaborationNode::ultrasound_callback(const std_msgs::msg::Float64::SharedPtr msg) {
    ultrasound_calibrate_ = msg->data * 0.8;
}

void DashboardElaborationNode::windex_callback(const custom_msgs::msg::WindexDataMsg::SharedPtr msg) {
    // Elaborazione dei dati del windex (esempio: calibrazione)
    awa_calibrate_ = msg->awa + 5.0;
    aws_calibrate_ = msg->aws * 1.8 / 3.6;
}

void DashboardElaborationNode::imu_callback(const sensor_msgs::msg::Imu::SharedPtr msg) {

    roll_calibrate_ = 2.0;
    pitch_calibrate_ = 3.0;
    yaw_calibrate_ = 4.0;
}

void DashboardElaborationNode::publish_dashboard_data() {
    
    std_msgs::msg::Float64 wand_msg;
    wand_msg.data = wand_angle_processed_;
    wand_publisher_->publish(wand_msg);

    std_msgs::msg::Float64 ultrasound_msg;
    ultrasound_msg.data = ultrasound_calibrate_;
    ultrasound_publisher_->publish(ultrasound_msg);

    custom_msgs::msg::WindexDataMsg windex_msg;
    windex_msg.awa = awa_calibrate_;
    windex_msg.aws = aws_calibrate_;
    windex_publisher_->publish(windex_msg);

    geometry_msgs::msg::Vector3 imu_msg;
    imu_msg.x = roll_calibrate_;
    imu_msg.y = pitch_calibrate_;
    imu_msg.z = yaw_calibrate_;
    imu_publisher_->publish(imu_msg);

    // --- LOG DI DEBUG (1 volta al secondo) ---
  RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
    "[PROCESSED] RPY(%.1f, %.1f, %.1f)° | Wand(%.1f°) | Windex(%.1f kn, %.1f°) | Ultra(%.2f)",
    roll_calibrate_, pitch_calibrate_, yaw_calibrate_,
    wand_angle_processed_,
    aws_calibrate_, awa_calibrate_,
    ultrasound_calibrate_);
}


} // namespace real_case


int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<real_case::DashboardElaborationNode>());
  rclcpp::shutdown();
  return 0;
}