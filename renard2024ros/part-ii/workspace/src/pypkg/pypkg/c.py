import rclpy

from example_interfaces import msg
from rclpy.node import Node
from rclpy.parameter import Parameter
from typing import List

class Number(Node):
    """A node for publishing numbers to topics.
    """

    # The size the ROS-based queue.
    #
    # This is the queue size for ROS-based publishers that publish messages to
    # a topic and require a set queue size.
    qsize = 10

    def __init__(self):
        """Initialize the node.
        """

        super().__init__("c")
        self.logger = self.get_logger()

        # Declare parameter(s).
        #
        # Here, we declare that parameters for this node that can be used at
        # runtime.
        self.declare_parameter("number", 1)
        self.declare_parameter("period", 1.0)

        self.number = self.get_parameter("number").value
        self.period = self.get_parameter("period").value

        # Create parameter callback(s).
        #
        # This will register the callback(s) associated with a particular
        # parameter.
        self.add_post_set_parameters_callback(self.parameters)

        # Create publishers.
        #
        # This will create the set of publisher(s) that this node is responsible
        # for, accordingly.
        self.pubs = [
            self.create_publisher(msg.Int64, "number", Number.qsize)
        ]

        # Create timers.
        #
        # This will create the set of timer(s) that this node is responsible for
        # to handle, accordingly.
        self.tims = [
            self.create_timer(self.period, self.callback)
        ]

        # Log something.
        #
        # This will log something using the ROS-based interfaces derived from the
        # [`Node`] at the INFO level.
        self.logger.info("initialized the node...")

    def parameters(self, parameters: List[Parameter]):
        """The callback function for when a parameter is changed.
        """

        for parameter in parameters:
            match parameter.name:
                case "number":
                    self.number = parameter.value

    def callback(self):
        """The callback function.
        """

        message = msg.Int64()
        message.data = self.number

        # Publish the data.
        #
        # This will use the appropriate publisher that requires the specific
        # msg.Int64 interface to publish this message to its topic.
        self.pubs[0].publish(message)


def main(args=None):
    """The main function to run.
    """

    rclpy.init(args=args)
    node = Number()

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
