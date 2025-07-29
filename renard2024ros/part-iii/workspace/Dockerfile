# syntax=docker/dockerfile:1
FROM andersonjwan/ros:jazzy

# Set the username.
#
# This username was set in a previous layer which has the appropriate identifiers
# to be used for volume mounting filesystem ownership constraints.
ARG USERNAME=ubuntu

# Install additional packages.
#
# These are development packages for developing and creating ROS pacakges within
# the ROS environment.
RUN apt-get update && \
    apt-get install --assume-yes \
        tmux \
        ros-jazzy-urdf-tutorial \
        ros-jazzy-tf2-tools \
        ros-jazzy-ros-gz && \
    apt-get clean && \
    rm --recursive --force /var/lib/apt/lists/*

COPY .bashrc /tmp/.bashrc
RUN { echo ""; cat /tmp/.bashrc; } >> /home/${USERNAME}/.bashrc && \
    rm --force /tmp/.bashrc

USER ${USERNAME}
WORKDIR /home/${USERNAME}
