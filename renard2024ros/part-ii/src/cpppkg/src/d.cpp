#include "example_interfaces/msg/int64.hpp"
#include "my_interfaces/srv/reset_counter.hpp"
#include "rclcpp/rclcpp.hpp"

using Int64 = example_interfaces::msg::Int64;
using ResetCounter = my_interfaces::srv::ResetCounter;

class Counter : public rclcpp::Node {
public:
  // The size of the ROS-based queue.
  //
  // This is a static variable used to set the queue size of ROS-related
  // publishers, accordingly.
  static const int qsize = 10;

  Counter() : Node("d"), counter(0) {
    // Create the subscriber(s).
    //
    // This will create all the required/necessary subscriber(s) for this node,
    // accordingly.
    this->sub = this->create_subscription<Int64>(
        "number", Counter::qsize,
        std::bind(&Counter::callback, this, std::placeholders::_1));

    // Create the service(s).
    //
    // This will create all the required/necessary service(s) for this node,
    // accordingly.
    this->srv = this->create_service<ResetCounter>(
        "reset", std::bind(&Counter::reset, this, std::placeholders::_1,
                           std::placeholders::_2));

    // Log the initialization.
    //
    // This will get this node's logger and submit a log with the INFO level of
    // the associated log, accordingly.
    RCLCPP_INFO(this->get_logger(), "initialized the node...");
  }

  /// Print debug-based messages.
  ///
  /// This prints debug-based messages using the standard ROS-based interfaces
  /// for logging information, accordingly.
  auto callback(const Int64::SharedPtr message) -> void {
    this->counter += message->data;

    // Log the info.
    //
    // This will log the counter value to the ROS-based logging system,
    // accordingly.
    RCLCPP_INFO(this->get_logger(), "`counter=%d`", this->counter);
  }

  // Reset the counter.
  //
  // This will reset the counter of this instance to the specified value only,
  // accordingly.
  auto reset(const ResetCounter::Request::SharedPtr request,
             const ResetCounter::Response::SharedPtr response) -> void {
    // Validate the request.
    //
    // This will perform some common and necessary checks on the response to
    // ensure the service can fulfill it, accordingly.
    if (request->reset < 0) {
      response->success = false;
      response->message = "The reset value must be greater or equal to zero";

      return;
    }

    if (request->reset > this->counter) {
      response->success = false;
      response->message = "The reset value must be less or equal to counter";

      return;
    }

    // The request has been validated, successfully and passed.
    //
    // At this point, the request validation has passed. Therefore, we can
    // proceed in fulfilling the request.
    this->counter = request->reset;
    RCLCPP_INFO(this->get_logger(), "reset the counter to... `%d`",
                this->counter);

    // Update the response.
    //
    // Since the request was successfully fulfilled, we can update the response
    // to be reflective of this status.
    response->success = true;
    response->message = "The counter has been successfully reset";
    return;
  }

private:
  int counter;
  rclcpp::TimerBase::SharedPtr timer;

  rclcpp::Subscription<Int64>::SharedPtr sub;
  rclcpp::Service<ResetCounter>::SharedPtr srv;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Counter>();

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
