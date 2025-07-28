#include "my_interfaces/srv/reset_counter.hpp"
#include "rclcpp/rclcpp.hpp"

using ResetCounter = my_interfaces::srv::ResetCounter;

class Client : public rclcpp::Node {
  // The size of the ROS-based queue.
  //
  // This is a static variable used to set the queue size of ROS-related
  // publishers, accordingly.
  static const int qsize = 10;

public:
  Client() : Node("f") {
    // Create the client(s).
    //
    // This will create the set of client(s) that this node is responsible for
    // handling, accordingly.
    this->clt = this->create_client<ResetCounter>("reset");
  }

  // Make a request.
  //
  // This sends a request to the service to set the counter value to a specified
  // amount, accordingly.
  auto request(int value) -> void {
    while (!this->clt->wait_for_service(std::chrono::seconds(1))) {
      RCLCPP_WARN(this->get_logger(), "waiting for server...");
    }

    auto request = std::make_shared<ResetCounter::Request>();
    request->reset = value;

    // Send the request.
    //
    // This will send an asynchronous call to the server to have its request
    // fulfilled.
    this->clt->async_send_request(
        request, std::bind(&Client::callback, this, std::placeholders::_1));
  }

  auto callback(rclcpp::Client<ResetCounter>::SharedFuture future) -> void {
    // Retrieve the result.
    //
    // The result (i.e., the data) of the response is retrieved by calling the
    // `get` method on the value, accordingly.
    auto response = future.get();

    RCLCPP_INFO(this->get_logger(), "response: `success=%d`",
                response->success);
    RCLCPP_INFO(this->get_logger(), "response: `message=%s`",
                response->message.c_str());
  }

private:
  rclcpp::Client<ResetCounter>::SharedPtr clt;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Client>();

  // Submit request.
  //
  // This submits the request a single time after the node has been successfully
  // created.
  node->request(10);

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
