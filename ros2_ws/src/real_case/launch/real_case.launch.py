# ros2_ws/src/real_case/launch/real_case.launch.py
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    pkg_dir = get_package_share_directory('real_case')

    return LaunchDescription([
        Node(
            package='real_case',
            executable='central_node',
            name='central_node',
            output='screen',
            parameters=[]
        ),
        Node(
            package='real_case',
            executable='dashboard_elaboration_node',
            name='dashboard_elaboration_node',
            output='screen',
            parameters=[]
        )
    ])