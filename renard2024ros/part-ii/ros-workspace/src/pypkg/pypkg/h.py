import rclpy

from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle, GoalStatus
from rclpy.node import Node
from typing import Optional

from my_interfaces.action import CountUntil

class CountAction(Node):
    """A node to that is a client for an action server.
    """

    def __init__(self):
        """
        """

        super().__init__("h")

        self.logger = self.get_logger()
        self.goalhandle: Optional[ClientGoalHandle] = None

        # Create client.
        #
        # Here, we create all client(s) that this node is responsible for
        # handling.
        self.client = ActionClient(self, CountUntil, "count")
        return

    def goal(self, target: int, step: float):
        """Send a goal to the server.
        """

        self.client.wait_for_server()
        goal = CountUntil.Goal()

        # Set the goal.
        #
        # This fills in the [`CountUntil.Goal`] with the appropriate arguments
        # besides the default values.
        goal.target = target
        goal.step = step

        self.client.send_goal_async(goal, feedback_callback=self.feedback).add_done_callback(self.response)
        return

    def response(self, future):
        """The callback from the action server responds to a goal request.
        """

        self.goalhandle = future.result()

        if self.goalhandle.accepted:
            self.logger.info("goal accepted...")
            self.goalhandle.get_result_async().add_done_callback(self.result)

            return

        self.logger.info("goal rejected...")
        return


    def cancel(self):
        self.logger.info("sending cancellation request...")
        self.goalhandle.cancel_goal_async()
    
    def feedback(self, message):
        """Process the feedback from the server.
        """

        current = message.feedback.current        
        self.logger.info(f"feedback: `current={current}`")

        # This is a test.
        #
        # Here, we are testing the cancel request mechanism by checking if the
        # current is greater than some number.
        if current >= 5:
            self.cancel()

    def result(self, future):
        """The callback when the action server is done.
        """

        match future.result().status:
            case GoalStatus.STATUS_SUCCEEDED:
                self.logger.info("the goal request was successful...")
            case GoalStatus.STATUS_ABORTED:
                self.logger.error("the goal request was aborted...")
            case GoalStatus.STATUS_CANCELED:
                self.logger.warn("the goal request was canceled...")

        self.logger.info(f"`reached={future.result().result.reached}`")
        return

def main(args=None):
    """The main function.
    """

    rclpy.init(args=args)

    node = CountAction()
    node.goal(100, 0.25)

    # Spin-up the node.
    #
    # This will start the node up, accordingly. This function call is also thread
    # blocking until a signal stop is sent to it, accordingly.
    rclpy.spin(node)

    # Shut this node down, gracefully.
    #
    # This will shut the node down from the ROS communication statck without
    # causing any major hiccups, assumingly.
    rclpy.shutdown()
