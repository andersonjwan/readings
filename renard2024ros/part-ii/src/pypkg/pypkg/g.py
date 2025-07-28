import rclpy
import time

from my_interfaces.action import CountUntil

from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.action.server import ServerGoalHandle
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node

class Counter(Node):
    """A node for handling counting actions.
    """

    def __init__(self):
        """Initialize the node.
        """

        super().__init__("g")
        self.logger = self.get_logger()

        # Create the action(s).
        #
        # Here, we create the action server(s) that this node is responsible for,
        # accordingly.
        self.server = ActionServer(
            self,
            CountUntil,
            "count",
            goal_callback=self.goal,
            cancel_callback=self.cancel,
            execute_callback=self.execute,
            callback_group=ReentrantCallbackGroup()
        )

    def goal(self, goal: CountUntil.Goal):
        """The callback called when a goal is recieved.
        """

        self.logger.info("received goal...")

        # Validate the goal.
        #
        # This is an important step in this callback as here we re deciding
        # whether or not the goal should be accepted/rejected.
        if goal.target <= 0:
            self.logger.info("rejecting... `target` must be greater than zero")
            return GoalResponse.REJECT

        # The goal is accepted.
        #
        # In this case, the target is above zero and is non-negative. Therefore,
        # we return an accept.
        self.logger.info(f"accepting... `target={goal.target}`")
        return GoalResponse.ACCEPT

    def cancel(self, handle: ServerGoalHandle):
        self.logger.info("received cancellation request...")
        return CancelResponse.ACCEPT

    def execute(self, handle: ServerGoalHandle):
        """Execute the goal.
        """

        target = handle.request.target
        step = handle.request.step

        # Initialize the result.
        #
        # This will be what is eventually returned by this procedure after
        # termination.
        result = CountUntil.Result()
        feedback = CountUntil.Feedback()

        current = 0

        # Count.
        #
        # From here, we can begin the core "algorithm" of this server which is
        # to incrementally count up to the target at the rate of the step.
        self.logger.info(f"executing... counting up to {target}")

        for i in range(target):
            # Check for cancellation request.
            #
            # This is the first thing that is done before proceeding with the
            # rest of the execution, accordingly.
            if handle.is_cancel_requested:
                self.logger.info("canceling goal...")
                handle.canceled()

                result.reached = current
                return result

            current += 1
            self.logger.info(f"`current={current}`")

            # Send feedback.
            #
            # Here, we place the feedback as something within the goal state has
            # changed (i.e., we incremented the counter).
            feedback.current = current
            handle.publish_feedback(feedback)

            time.sleep(step)


        # Terminate.
        #
        # Here, we terminate the execution gracefully by setting the handle to
        # success and setting the result.
        handle.succeed()
        result.reached = current

        return result
        
def main(args=None):
    """The main function.
    """

    rclpy.init(args=args)
    node = Counter()

    # Spin-up the node.
    #
    # This will start the node up, accordingly. This function call is also thread
    # blocking until a signal stop is sent to it, accordingly.
    rclpy.spin(node, MultiThreadedExecutor())

    # Shut this node down, gracefully.
    #
    # This will shut the node down from the ROS communication statck without
    # causing any major hiccups, assumingly.
    rclpy.shutdown()
