// AUTO-GENERATED FILE. DO NOT EDIT.
#ifndef PUBSUB_CUSTOM_ROS_ENDPOINTS_HPP
#define PUBSUB_CUSTOM_ROS_ENDPOINTS_HPP

namespace ros_endpoints {

struct SharedTopics {
  static constexpr const char* BOAT_STATUS = "/boat/status";
};

struct SharedServices {
};

using Shared = SharedTopics;

struct STATUS_PUBLISHER_NODE {
  struct PUB {
    static constexpr const char* BOAT_STATUS = "/boat/status";
  };
};

struct STATUS_SUBSCRIBER_NODE {
  struct SUB {
    static constexpr const char* BOAT_STATUS = "/boat/status";
  };
};

} // namespace ros_endpoints

#endif // PUBSUB_CUSTOM_ROS_ENDPOINTS_HPP
