from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Nodo che processa i comandi
        Node(
            package='pubsub',
            executable='command_processor_node',
            name='command_processor_node',
            output='screen'
        ),
        # Nodo che genera i comandi
        Node(
            package='pubsub',
            executable='command_generator_node',
            name='command_generator_node',
            output='screen'
        )
    ])