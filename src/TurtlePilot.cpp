#include "turtle_pilot/TurtlePilot.hpp"

using namespace std::chrono_literals;

TurtlePilot::TurtlePilot()
  : Node("turtle_pilot")
  {
    // Pose callback for turtle1
    auto turtle1_cb =
      [this](turtlesim::msg::Pose::UniquePtr msg) -> void {
        RCLCPP_INFO(this->get_logger(), "Received turtle1 pose");
        this->turtle1_pose_ = *msg;
      };

    // Pose callback for turtle2
    auto turtle2_cb =
      [this](turtlesim::msg::Pose::UniquePtr msg) -> void {
        RCLCPP_INFO(this->get_logger(), "Received turtle2 pose");
        this->turtle2_pose_ = *msg;
      };
    
    // Timer callback that publishes a twist message periodically
    auto timer_callback =
      [this]() -> void {

        // Create empty twist message
        auto message = geometry_msgs::msg::Twist();

        // ToDo: Use the turtle1_pose_ and turtle2_pose_ to calculate the twist message to move turtle2 towards turtle1
        this->turtle1_pose_;
        this->turtle2_pose_;

        // Fill the twist message with some dummy values
        message.linear.x = 1.0;
        message.angular.z = 0.5;

        RCLCPP_INFO(this->get_logger(), "Publishing twist msg");
        this->publisher_->publish(message);
      };

    // Create subscriptions for turtle1 and turtle2 poses
    subscription_turtle1_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, turtle1_cb);
    subscription_turtle2_ = this->create_subscription<turtlesim::msg::Pose>("/turtle2/pose", 10, turtle2_cb);

    // Create publisher for turtle2 velocity commands
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle2/cmd_vel", 10);

    // Start timer to publish twist messages
    timer_ = this->create_wall_timer(100ms, timer_callback);
}