import rclpy

from my_interfaces.srv import ResetCounter
from rclpy.node import Node

class Client(Node):
    """A node to represent a client for resetting the counter.
    """

    def __init__(self):
        """Initialize the node.
        """

        super().__init__("f")
        self.logger = self.get_logger()

        # Create client(s).
        #
        # This is where all the client(s) of this node are created and managed,
        # accordingly.
        self.clt = self.create_client(ResetCounter, "reset")

    def request(self, value: int):
        """Make a request to the service.
        """

        while not self.clt.wait_for_service(1.0):
            self.logger.info("waiting for service...")

        # Create the request.
        #
        # At this point, we can create the interface needed for the service to
        # be called, accordingly.
        request = ResetCounter.Request()
        request.reset = value

        # Make request.
        #
        # This will make an asynchronous call to the service and wait for a
        # response.
        future = self.clt.call_async(request)

        # Add a callback to the request.
        #
        # This callback is responsible for being ran when the response gets
        # fulfilled, accordingly.
        future.add_done_callback(self.callback)

    def callback(self, future):
        """A callback for responses from the service.
        """

        # Retrieve the result.
        #
        # The result (i.e., the data) of the response is retrieved by calling the
        # `result` on the value.
        response = future.result()

        self.logger.info(f"reponse: `success={response.success}`")
        self.logger.info(f"reponse: `message={response.message}`")
        

def main(args=None):
    """The main function.
    """

    rclpy.init(args=args)
    node = Client()

    node.request(10)

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
