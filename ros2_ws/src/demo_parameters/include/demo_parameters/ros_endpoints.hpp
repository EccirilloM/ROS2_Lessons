// AUTO-GENERATED FILE. DO NOT EDIT.
#ifndef DEMO_PARAMETERS_ROS_ENDPOINTS_HPP
#define DEMO_PARAMETERS_ROS_ENDPOINTS_HPP

namespace ros_endpoints {

struct SharedTopics {
  static constexpr const char* WIND_SPEED = "/wind_speed";
};

struct SharedServices {
};

using Shared = SharedTopics;

struct WIND_PUBLISHER_NODE {
  struct PUB {
    static constexpr const char* WIND_SPEED = "/wind_speed";
  };
};

struct WIND_MONITOR_NODE {
  struct SUB {
    static constexpr const char* WIND_SPEED = "/wind_speed";
  };
};

} // namespace ros_endpoints

#endif // DEMO_PARAMETERS_ROS_ENDPOINTS_HPP
