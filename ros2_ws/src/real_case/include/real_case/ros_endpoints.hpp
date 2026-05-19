// AUTO-GENERATED FILE. DO NOT EDIT.
#ifndef REAL_CASE_ROS_ENDPOINTS_HPP
#define REAL_CASE_ROS_ENDPOINTS_HPP

namespace ros_endpoints {

struct SharedTopics {
  static constexpr const char* IMU_DATA = "/imu_data";
  static constexpr const char* WAND_ANGLE = "/wand_angle";
  static constexpr const char* WINDEX_DATA = "/windex_data";
  static constexpr const char* ULTRASOUND_DATA = "/ultrasound_data";
  static constexpr const char* PROCESSED_IMU_DATA = "/processed/imu_data";
  static constexpr const char* PROCESSED_WAND_ANGLE = "/processed/wand_angle";
  static constexpr const char* PROCESSED_WINDEX_DATA = "/processed/windex_data";
  static constexpr const char* PROCESSED_ULTRASOUND_DATA = "/processed/ultrasound_data";
};

struct SharedServices {
};

using Shared = SharedTopics;

struct CENTRAL_NODE {
  struct PUB {
    static constexpr const char* IMU_DATA = "/imu_data";
    static constexpr const char* WAND_ANGLE = "/wand_angle";
    static constexpr const char* WINDEX_DATA = "/windex_data";
    static constexpr const char* ULTRASOUND_DATA = "/ultrasound_data";
  };
};

struct DASHBOARD_ELABORATION_NODE {
  struct SUB {
    static constexpr const char* IMU_DATA = "/imu_data";
    static constexpr const char* WAND_ANGLE = "/wand_angle";
    static constexpr const char* WINDEX_DATA = "/windex_data";
    static constexpr const char* ULTRASOUND_DATA = "/ultrasound_data";
  };
  struct PUB {
    static constexpr const char* PROCESSED_IMU_DATA = "/processed/imu_data";
    static constexpr const char* PROCESSED_WAND_ANGLE = "/processed/wand_angle";
    static constexpr const char* PROCESSED_WINDEX_DATA = "/processed/windex_data";
    static constexpr const char* PROCESSED_ULTRASOUND_DATA = "/processed/ultrasound_data";
  };
};

} // namespace ros_endpoints

#endif // REAL_CASE_ROS_ENDPOINTS_HPP
