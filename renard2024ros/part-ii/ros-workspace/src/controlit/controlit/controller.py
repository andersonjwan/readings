import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist, Vector3
from my_interfaces.srv import ActivateTurtle
from turtlesim.msg import Pose
from turtlesim.srv import SetPen

class Controller(Node):
    """A simple controller for the turtlesim package.
    """

    # The size the ROS-based queue.
    #
    # This is the queue size for ROS-based publishers that publish messages to
    # a topic and require a set queue size.
    qsize = 10
    initpos = 5.5

    def __init__(self):
        """Initialize the node.
        """

        super().__init__("controller")
        self.logger = self.get_logger()

        # Add paramter(s).
        #
        # Here, we will add parameters to this node to be used during runtime
        # and startup.
        self.declare_parameter("lcolor", [255, 0, 0])
        self.declare_parameter("rcolor", [0, 255, 0])
        self.declare_parameter("lvelocity", 1.0)
        self.declare_parameter("rvelocity", 2.0)

        self.lcolor = self.get_parameter("lcolor").value
        self.rcolor = self.get_parameter("rcolor").value
        self.lvelocity = self.get_parameter("lvelocity").value
        self.rvelocity = self.get_parameter("rvelocity").value

        self.previous = Controller.initpos
        self.on = True

        # Create the publisher.
        #
        # This publisher is responsible for publishing commands to the turtlebot
        # velocity topic, accordingly.
        self.publisher = self.create_publisher(Twist, "/turtle1/cmd_vel", Controller.qsize)

        # Create the subscriber.
        #
        # This subscriber is responsible for recieving the pose information from
        # the turtlebot, accordingly.
        self.subscriber = self.create_subscription(Pose, "/turtle1/pose", self.callback, Controller.qsize)

        # Create the client.
        #
        # This client is responsible for sending a request to change the color
        # of the pen, accordingly.
        self.client = self.create_client(SetPen, "/turtle1/set_pen")

        # Create the server.
        #
        # This server is responsible for activating or deactivating the turtle
        # depending on the requests made.
        self.server = self.create_service(ActivateTurtle, "activate", self.activate)

        # Log initialization.
        #
        # This will log if the node successfully creates the publisher and
        # subscriber, accordingly.
        self.logger.info("initialized node...")

    def callback(self, message: Pose):
        """The callback for the subscriber.
        """

        if not self.on:
            return

        # This is the command to send to the turtlebot.
        #
        # In this case, the turtlebot accepts a [`Twist`] that sets its linear and
        # angular velocities, accordingly.
        command = Twist()

        # Process the pose.
        #
        # In this case, we want to check the x-position of the turtlebot in the
        # simulator. There are two cases to consider: (1) left of center, and (2)
        # right of center, accordingly.
        if message.x < Controller.initpos:
            # The turtlebot is to the left of the center.
            #
            # This will set the linear and angular velocity of the [`Twist`]
            # before publishing it, accordingly.
            command.linear.x = self.lvelocity
            command.angular.z = self.lvelocity

            # Publish the message.
            #
            # This send the message to the topic set by the publisher set up
            # previously.
            self.publisher.publish(command)

            # This is an optimzation.
            #
            # Here, we know that the current position is to the left of
            # Controller.initpos. Therefore, we only change the color if this is the
            # first time it is to the left of Controller.initpos.
            if self.previous >= Controller.initpos:
                self.previous = message.x
                self.request(r=self.lcolor[0], g=self.lcolor[1], b=self.lcolor[2])
                

            return

        # The turtlebot is not to the left of the center (i.e., right).
        #
        # Therefore, we want to set the velocity of the turtlebot to 2 in this
        # case, accordingly.
        command.linear.x = self.rvelocity
        command.angular.z = self.rvelocity

        # Publish the message.
        #
        # This send the message to the topic set by the publisher set up
        # previously.
        self.publisher.publish(command)

        # This is an optimzation.
        #
        # Here, we know that the current position is to the right of
        # Controller.initpos. Therefore, we only change the color if this is the
        # first time it is to the right of Controller.initpos.
        if self.previous < Controller.initpos:
            self.previous = message.x
            self.request(r=self.rcolor[0], g=self.rcolor[1], b=self.rcolor[2])

        return

    def request(self, r: int, g: int, b: int, width: int = 5, off: int = 0):
        """Submit a request from the client to the server.
        """

        while not self.client.wait_for_service(1.0):
            self.logger.info("waiting for `set_pen` service...")

        # Create the request.
        #
        # Here, we create the request interface that is needed for the service
        # that this client is linked to.
        request = SetPen.Request()

        request.r = r
        request.g = g
        request.b = b
        request.width = width
        request.off = off

        # Submit request.
        #
        # After the request is created, we want to submit the request to the
        # service.
        future = self.client.call_async(request)

        # Post-process the request.
        #
        # Here, we determine if the request made by the client was successful or
        # not, accordingly.
        future.add_done_callback(self.postprocess)

    def postprocess(self, future):
        """A callback for responses from the service.
        """

        response = future.result()

        # Log the result.
        #
        # This will send the results of the request to the logger for validation
        # and book-keeping.
        self.logger.info("the request was processed successfully...")
        return

    def activate(self, request: ActivateTurtle.Request, response: ActivateTurtle.Response):
        """Activate the turtlebot.
        """

        # Set the state.
        #
        # This will set the turtle state to the specified on/off configuration
        # from the request, accordingly.
        self.on = request.on

        if request.on:
            response.status = True
            response.message = "the turtle state has been set to `on`"

            return response


        # Turn the turtle off (i.e., deactivate).
        #
        # This will set the turtle `on` to false which will in-turn disable any
        # publications to its `cmd_vel` topic, accordingly.
        response.status = True
        response.message = "the turtle state has been set to `off`"

        return response

        

        

def main(args=None):
    """The main function.
    """

    rclpy.init(args=args)
    node = Controller()

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
