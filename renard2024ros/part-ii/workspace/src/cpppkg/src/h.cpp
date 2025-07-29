#include "my_interfaces/action/count_until.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

using CountUntil = my_interfaces::action::CountUntil;
using CountUntilGoalHandle = rclcpp_action::ClientGoalHandle<CountUntil>;

class CountClient : public rclcpp::Node {
public:
  CountClient() : Node("h") {
    this->client = rclcpp_action::create_client<CountUntil>(this, "count");
  }

  auto goal(int target, double step) -> void {
    // Wait for the server.
    //
    // If this client makes a goal request and the server is not online, then we
    // shall wait indefinitely until the server is online.
    this->client->wait_for_action_server();

    auto goal = CountUntil::Goal();
    goal.target = target;
    goal.step = step;

    // Set the callbacks.
    //
    // This is different compared to the Python-based API for ROS as we need to
    // register the callbacks before sending the request.
    auto options = rclcpp_action::Client<CountUntil>::SendGoalOptions();

    options.goal_response_callback =
        std::bind(&CountClient::response, this, std::placeholders::_1);

    options.result_callback =
        std::bind(&CountClient::result, this, std::placeholders::_1);

    options.feedback_callback =
        std::bind(&CountClient::feedback, this, std::placeholders::_1,
                  std::placeholders::_2);

    // Submit goal request.
    //
    // This is the request made to the server for the goal from this client,
    // accordingly.
    this->client->async_send_goal(goal, options);
  }

  auto feedback(const CountUntilGoalHandle::SharedPtr &handle,
                const std::shared_ptr<const CountUntil::Feedback> feedback)
      -> void {
    // Ignore the parameter.
    //
    // This is set to avoid any compiler warnings upon compiling this
    // translation file, accordingly
    (void)handle;

    RCLCPP_INFO(this->get_logger(), "feedback: `counter=%ld`",
                feedback->current);

    if (feedback->current >= 5) {
      this->cancel();
    }
  }

  auto cancel() -> void {
    RCLCPP_INFO(this->get_logger(), "sending cancellation request...");
    this->client->async_cancel_all_goals();
  }

  // The callback for the response.
  //
  // This is the callback that gets called when the server responds to this
  // client's goal request.
  auto response(const CountUntilGoalHandle::SharedPtr &handle) -> void {
    if (!handle) {
      RCLCPP_INFO(this->get_logger(), "goal rejected...");
      return;
    }

    RCLCPP_INFO(this->get_logger(), "goal accepted...");
  }

  auto result(const CountUntilGoalHandle::WrappedResult &result) -> void {
    auto status = result.code;

    if (status == rclcpp_action::ResultCode::SUCCEEDED) {
      // The server processed the goal.
      //
      // This means that the goal request sent by this client was successfully
      // completed and returned.
      RCLCPP_INFO(this->get_logger(), "the goal request was successful...");
    } else if (status == rclcpp_action::ResultCode::ABORTED) {
      // The server terminated early.
      //
      // This can be due to multiple reasons. However, it should be known that
      // the server originally accepted the request but found an issues that
      // prevented the goal from being reached.
      RCLCPP_WARN(this->get_logger(), "the goal request was aborted...");
    } else if (status == rclcpp_action::ResultCode::CANCELED) {
      // The server goal request was canceled.
      //
      // This indicates that the goal was sent, accepted, and proceeded.
      // However, the client sent a request that was accepted to cancel the
      // current in-progress goal.
      RCLCPP_INFO(this->get_logger(), "the goal request was canceled...");
    }

    // Print the result.
    //
    // This is a temporary next-step that allows us to debug and ensure that the
    // goal was indeed met, accordingly.
    RCLCPP_INFO(this->get_logger(), "`reached=%ld`", result.result->reached);
  }

  rclcpp_action::Client<CountUntil>::SharedPtr client;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<CountClient>();
  node->goal(10, 0.5);

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
