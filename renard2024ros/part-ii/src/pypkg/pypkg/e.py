import rclpy

from my_interfaces import msg
from rclpy.node import Node

class Hardware(Node):
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

        super().__init__("e")
        self.logger = self.get_logger()

        self.version = 1
        self.temperature = 28.5
        self.online = True

        # Log something.
        #
        # This will log something using the ROS-based interfaces derived from the
        # [`Node`] at the INFO level.
        self.logger.info("initialized the node...")

        # Create publishers.
        #
        # This will create the set of publisher(s) that this node is responsible
        # for, accordingly.
        self.pubs = [
            self.create_publisher(msg.HardwareStatus, "hardware", Hardware.qsize)
        ]

        # Create timers.
        #
        # This will create the set of timer(s) that this node is responsible for
        # to handle, accordingly.
        self.tims = [
            self.create_timer(1.0, self.callback)
        ]

    def callback(self):
        """The callback function.
        """

        message = msg.HardwareStatus()

        message.version = self.version
        message.temperature = self.temperature
        message.online = self.online

        # Publish the data.
        #
        # This will use the appropriate publisher that requires the specific
        # msg.Int64 interface to publish this message to its topic.
        self.pubs[0].publish(message)


def main(args=None):
    """The main function to run.
    """

    rclpy.init(args=args)
    node = Hardware()

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
