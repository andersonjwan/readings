import rclpy
from rclpy.node import Node

class MyNode(Node):
    """My customized ROS-based node.
    """

    def __init__(self):
        """Initialize the node.
        """

        super().__init__("b")
        self.logger = self.get_logger()

        # Log something.
        #
        # This will log something using the ROS-based interfaces derived from
        # [`Node`] at the INFO level.
        self.logger.info("Hello, Robot Operating System World.")

        self.counter = 0
        self.timer = self.create_timer(1.0, self.printit)


    def printit(self):
        """Print some information to the log.
        """

        self.logger.info(f"printit(b): `counter={self.counter}`")
        self.counter += 1

def main(args=None):
    """The main function to run.
    """

    rclpy.init(args=args)
    node = MyNode()

    # Spin-up the node.
    #
    # This will start the node up, accordingly. This function call is also thread
    # blocking until a signal stop is sent to it, accordingly.
    rclpy.spin(node)

    # Shut this node down, gracefully.
    #
    # This will shut the node down from the ROS communication stack without
    # causing any major hiccups, assumingly.
    rlcpy.shutdown()

if __name__ == r"__main__":
    main()
