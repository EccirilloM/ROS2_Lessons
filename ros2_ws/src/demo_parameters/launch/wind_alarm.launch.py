# ros2_ws/src/demo_parameters/launch/wind.alarm.launch.py
import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    pkg_dir = get_package_share_directory('demo_parameters')
    
    # Percorsi ai due file YAML
    params_file = os.path.join(pkg_dir, 'config', 'params.yaml')

    return LaunchDescription([
        Node(
            package='demo_parameters',
            executable='wind_publisher_node',
            name='wind_publisher_node',
            output='screen',
            parameters=[] # Passiamo gli endpoints
        ),
        Node(
            package='demo_parameters',
            executable='wind_monitor_node',
            name='wind_monitor_node',
            output='screen',
            parameters=[params_file] # Passiamo solo i parametri
        )
    ])