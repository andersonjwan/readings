add_executable(a a.cpp)
ament_target_dependencies(a rclcpp)

add_executable(b b.cpp)
ament_target_dependencies(b rclcpp)

add_executable(c c.cpp)
ament_target_dependencies(c rclcpp example_interfaces)

add_executable(d d.cpp)
ament_target_dependencies(d rclcpp example_interfaces my_interfaces)

add_executable(e e.cpp)
ament_target_dependencies(e rclcpp my_interfaces)

add_executable(f f.cpp)
ament_target_dependencies(f rclcpp my_interfaces)

add_executable(g g.cpp)
ament_target_dependencies(g rclcpp rclcpp_action my_interfaces)

add_executable(h h.cpp)
ament_target_dependencies(h rclcpp rclcpp_action my_interfaces)

install(TARGETS a b c d e f g h
  DESTINATION lib/${PROJECT_NAME}
)
