#include "example_interfaces/msg/int64.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace example_interfaces;

class Number : public rclcpp::Node {
public:
  // The size of the ROS-based queue.
  //
  // This is a static variable used to set the queue size of ROS-related
  // publishers, accordingly.
  static const int qsize = 10;

  Number() : Node("c") {
    // Declare parameter(s).
    //
    // Here, we will create the parameter(s) that can be set at runtime for this
    // node, accordingly.
    this->declare_parameter("number", 2);
    this->declare_parameter("period", 1.0);

    this->number = this->get_parameter("number").as_int();

    // Bind parameter(s) callback.
    //
    // Here, we bind a callback function when parameter(s) of this node are
    // requested to be mutated.
    this->phandle = this->add_post_set_parameters_callback(
        std::bind(&Number::parameters, this, std::placeholders::_1));

    // Initialize the timer.
    //
    // This will initialize a ROS-based timer for
    this->timer =
        this->create_wall_timer(std::chrono::duration<double>(
                                    this->get_parameter("period").as_double()),
                                std::bind(&Number::callback, this));

    // Create the publisher(s).
    //
    // This will create all the required/necessary publisher(s) for this node,
    // accordingly.
    this->pub = this->create_publisher<msg::Int64>("number", Number::qsize);

    // Log the initialization.
    //
    // This will get this node's logger and submit a log with the INFO level of
    // the associated log, accordingly.
    RCLCPP_INFO(this->get_logger(), "initialize the node...");
  }

  auto parameters(const std::vector<rclcpp::Parameter> &parameters) -> void {
    for (const auto &parameter : parameters) {
      if (parameter.get_name() == "number") {
        this->number = parameter.as_int();
      }
    }
  }

  /// Print debug-based messages.
  ///
  /// This prints debug-based messages using the standard ROS-based interfaces
  /// for logging information, accordingly.
  auto callback() -> void {
    auto message = msg::Int64();
    message.data = number;

    // Publish the message.
    //
    // This will use the appropriate publisher that requires the specific
    // msg::Int64 interface to publish the message to its topic.
    this->pub->publish(message);
  }

private:
  int number;

  rclcpp::TimerBase::SharedPtr timer;
  rclcpp::Publisher<msg::Int64>::SharedPtr pub;
  PostSetParametersCallbackHandle::SharedPtr phandle;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Number>();

  // Spin-up the ROS-based node.
  //
  // This will run the ROS-styled node infinitely until the signal to stop the
  // program is received, accordingly.
  rclcpp::spin(node);

  // Shut the node down, gracefully.
  //
  // This will close and exit the node execution without disrupting the ROS
  // communication network, assumingly.
  rclcpp::shutdown();

  // The final return.
  //
  // This is required for the main function of a program within the C++
  // programming language.
  return 0;
}
