# ros2_ws/src/pubsub_custom/launch/custom_status.launch.py
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    pkg_dir = get_package_share_directory('pubsub_custom')

    return LaunchDescription([
        Node(
            package='pubsub_custom',
            executable='status_publisher_node',
            name='status_publisher_node',
            output='screen',
            parameters=[]
        ),
        Node(
            package='pubsub_custom',
            executable='status_subscriber_node',
            name='status_subscriber_node',
            output='screen',
            parameters=[]
        )
    ])