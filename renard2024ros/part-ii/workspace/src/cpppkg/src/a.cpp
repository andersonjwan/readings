#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node {
public:
  MyNode() : Node("a"), counter(0) {
    // Initialize the timer.
    //
    // This will initialize a ROS-based timer for
    timer = this->create_wall_timer(std::chrono::seconds(1),
                                    std::bind(&MyNode::printit, this));
  }

  /// Print debug-based messages.
  ///
  /// This prints debug-based messages using the standard ROS-based interfaces
  /// for logging information, accordingly.
  auto printit() -> void {
    RCLCPP_INFO(this->get_logger(), "printit(a): `counter=%d`", counter);
    this->counter++;
  }

private:
  int counter;
  rclcpp::TimerBase::SharedPtr timer;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MyNode>();

  // Spin-up the ROS-based node.
  //
  // This will run the ROS-styled node infinitely until the signal to stop the
  // program is received, accordingly.
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
