from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    a = Node(
        package="pypkg",
        executable="c"
    )

    b = Node(
        package="cpppkg",
        executable="d"
    )

    ld.add_action(a)
    ld.add_action(b)

    return ld
