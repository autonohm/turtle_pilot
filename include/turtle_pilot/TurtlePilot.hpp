#pragma once

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"

class TurtlePilot : public rclcpp::Node
{
public:
  TurtlePilot();

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_turtle1_;
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_turtle2_;

  turtlesim::msg::Pose turtle1_pose_;
  turtlesim::msg::Pose turtle2_pose_;
};