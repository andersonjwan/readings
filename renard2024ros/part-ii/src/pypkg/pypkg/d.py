import rclpy

from example_interfaces.msg import Int64
from my_interfaces.srv import ResetCounter
from rclpy.node import Node

class Counter(Node):
    """A node for subscriber to numbers from topics.
    """

    # The size the ROS-based queue.
    #
    # This is the queue size for ROS-based publishers that publish messages to
    # a topic and require a set queue size.
    qsize = 10

    def __init__(self):
        """Initialize the node.
        """

        super().__init__("d")
        self.logger = self.get_logger()
        self.counter: int = 0

        # Create subscriber(s).
        #
        # This will create the set of subscriber(s) that this node is responsible
        # for, accordingly.
        self.subs = [
            self.create_subscription(Int64, "number", self.callback, Counter.qsize)
        ]

        # Create service(s).
        #
        # This will create the set of service(s) that this node is responsible
        # for, accordingly.
        self.srvs = [
            self.create_service(ResetCounter, "reset", self.resetit)
        ]

        # Log something.
        #
        # This will log something using the ROS-based interfaces derived from the
        # [`Node`] at the INFO level.
        self.logger.info("initialized the node...")

    def callback(self, message: Int64):
        """The callback function.
        """

        self.counter += message.data
        self.logger.info(f"`counter={self.counter}`")

    def resetit(self, request: ResetCounter.Request, response: ResetCounter.Response):
        """Reset the counter to a specified value.
        """

        # Validate the request.
        #
        # This is a common and often necessary step to ensure that the request
        # being made can be properly fulfilled by the server.
        if request.reset < 0:
            response.success = False
            response.message = "The reset value must be greater than or equal to zero"

            return response

        if request.reset > self.counter:
            response.success = False
            response.message = "The reset value must be less than or equal to the counter"

            return response

        self.counter = request.reset
        self.logger.info(f"reset counter to... `{self.counter}`")

        # Set the response.
        #
        # This mutates the interface passed and replaces the default values of
        # the response, accordingly.
        response.success = True
        response.message = f"The counter has been successfully reset to `{self.counter}`"

        return response
        

def main(args=None):
    """The main function to run.
    """

    rclpy.init(args=args)
    node = Counter()

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
