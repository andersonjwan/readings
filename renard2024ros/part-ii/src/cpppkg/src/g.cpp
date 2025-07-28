#include "my_interfaces/action/count_until.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

using namespace std::placeholders;

using CountUntil = my_interfaces::action::CountUntil;
using CountUntilGoalHandle = rclcpp_action::ServerGoalHandle<CountUntil>;

class Counter : public rclcpp::Node {
  // The size of the ROS-based queue.
  //
  // This is a static variable used to set the queue size of ROS-related
  // publishers, accordingly.
  static const int qsize = 10;

public:
  Counter() : Node("g") {
    // Create callback group(s).
    //
    // These are used to execute the callbacks in parallel and to avoid any
    // blocking during callback execution.
    this->group =
        this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);

    // Create the action server(s).
    //
    // This will create the set of action server(s) that this node is
    // responsible for handling, accordingly.
    this->srv = rclcpp_action::create_server<CountUntil>(
        this, "count", std::bind(&Counter::goal, this, _1, _2),
        std::bind(&Counter::cancel, this, _1),
        std::bind(&Counter::execute, this, _1),
        rcl_action_server_get_default_options(), this->group);
  }

  // Validate the goal.
  //
  // Here, we take incoming goal requests and either accept or reject them based
  // on the provided goal.
  auto goal(const rclcpp_action::GoalUUID &uuid,
            std::shared_ptr<const CountUntil::Goal> goal)
      -> rclcpp_action::GoalResponse {
    // Ignore the parameter.
    //
    // This is set to avoid any compiler warnings upon compiling this
    // translation file, accordingly
    (void)uuid;

    RCLCPP_INFO(this->get_logger(), "received goal...");

    // Validate the goal.
    //
    // This determines whether the goal is accepted or rejected based on the
    // target value, accordingly.
    if (goal->target <= 0) {
      RCLCPP_INFO(this->get_logger(),
                  "rejecting... `target` must be greater than zero");

      // The goal is not satisfied.
      //
      // In this case, we want to return the rejection status as the provided
      // goal did not satisfy the constraint.
      return rclcpp_action::GoalResponse::REJECT;
    }

    RCLCPP_INFO(this->get_logger(), "accepting... `target=%ld`", goal->target);
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

private:
  // Cancel the goal.
  //
  // This is the request to cancel the current in-progress goal from the server,
  // accordingly.
  auto cancel(const std::shared_ptr<CountUntilGoalHandle> handle)
      -> rclcpp_action::CancelResponse {
    // Ignore the parameter.
    //
    // This is set to avoid any compiler warnings upon compiling this
    // translation file, accordingly
    (void)handle;

    RCLCPP_INFO(this->get_logger(), "request to cancel received...");
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  // Execute the goal.
  //
  // This is the execution procedure to run iff the goal is accepted to run,
  // accordingly.
  auto execute(const std::shared_ptr<CountUntilGoalHandle> handle) -> void {
    int target = handle->get_goal()->target;
    double step = handle->get_goal()->step;

    // Initialize the result.
    //
    // This will be what is eventually returned by this procedure after
    // termination.
    auto result = std::make_shared<CountUntil::Result>();
    auto feedback = std::make_shared<CountUntil::Feedback>();

    int current = 0;

    // Count.
    //
    // From here, we can begin the core "algorithm" of this server which is to
    // incrementally count up to the target at the rate of the step. But first,
    // we compute the rate to determine this frequency.
    rclcpp::Rate rate(1.0 / step);
    RCLCPP_INFO(this->get_logger(), "executing... counting up to %d", target);

    for (int i = 0; i < target; ++i) {
      // Check for cancellation.
      //
      // Here, we check if a cancellation request from the client has been made,
      // accordingly.
      if (handle->is_canceling()) {
        RCLCPP_INFO(this->get_logger(), "canceling goal...");

        result->reached = current;
        handle->canceled(result);
        return;
      }

      ++current;
      RCLCPP_INFO(this->get_logger(), "`current=%d`", current);

      // Send feedback.
      //
      // At this point, the state of the goal progress has changed. Therefore,
      // we send feedback to the client.
      feedback->current = current;
      handle->publish_feedback(feedback);

      rate.sleep();
    }

    // Terminate.
    //
    // Here, we terminate the execution gracefully by setting the handle to
    // success and setting the result, accordingly.
    result->reached = current;
    handle->succeed(result);
  }

  rclcpp_action::Server<CountUntil>::SharedPtr srv;
  rclcpp::CallbackGroup::SharedPtr group;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Counter>();

  // Spin-up the ROS-based node.
  //
  // This will run the ROS-styled node infinitely until the signal to stop the
  // program is received, accordingly.
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node);
  executor.spin();

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
