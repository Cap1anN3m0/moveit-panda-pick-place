//include necesary libraries
#include <memory>
#include <utility>

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit_msgs/msg/display_trajectory.hpp>
#include <geometry_msgs/msg/pose.hpp>

int main(int argc, char* argv[]) {
  //Initialize ROS and create the Node
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("moveit_sequence");

  //Create a ROS logger
  auto logger = rclcpp::get_logger("moveit_sequence");

  //Create MoveIt MoveGroup Interfaces for arm and gripper
  moveit::planning_interface::MoveGroupInterface arm_move_group(node, "panda_arm");
  moveit::planning_interface::MoveGroupInterface gripper_move_group(node, "panda_hand");

  
  geometry_msgs::msg::Pose target_pose;
  target_pose.position.x = 0.56545;  //Adjust to desired x position
  target_pose.position.y = 0.11099;  //Adjust to desired y position
  target_pose.position.z = 0.8494;  //Adjust to desired z position
   //Define the orientation (for example, a straightforward orientation)
  target_pose.orientation.x = 0.877;
  target_pose.orientation.y = -0.206131;
  target_pose.orientation.z = 0.419747;
  target_pose.orientation.w = -0.104719;

    //Set the target pose for the arm move group
  arm_move_group.setPoseTarget(target_pose);
  moveit::planning_interface::MoveGroupInterface::Plan plan;
  if (arm_move_group.plan(plan) == moveit::core::MoveItErrorCode::SUCCESS) {
      if (arm_move_group.execute(plan) == moveit::core::MoveItErrorCode::SUCCESS) {
          RCLCPP_INFO(logger, "Moved to home_pose successfully.");
      } else {
          RCLCPP_ERROR(logger, "Execution to home_pose failed!");
          return 1; //Early exit due to failure
      }
  } else {
    RCLCPP_ERROR(logger, "Planning to home_pose failed!");
      return 1; //Early exit due to failure
  }
  
  
   // Set joint values manually for 'open_pos'
  std::map<std::string, double> target_joints_openn;
  target_joints_openn["panda_finger_joint1"] = 0.0122;
  target_joints_openn["panda_finger_joint2"] = 0.0122;

  gripper_move_group.setJointValueTarget(target_joints_openn);
  moveit::planning_interface::MoveGroupInterface::Plan open_plan0;

  if (gripper_move_group.plan(open_plan0) == moveit::core::MoveItErrorCode::SUCCESS) {
      gripper_move_group.execute(open_plan0);
  } else {
      RCLCPP_ERROR(node->get_logger(), "Planning to manually open gripper failed!");
      return 1;
  }
  

  //Move to goal state 1
  geometry_msgs::msg::Pose goal1_pose;
  goal1_pose.position.x = 0.26473;  //Adjust to desired x position
  goal1_pose.position.y = 0.61758;  //Adjust to desired y position
  goal1_pose.position.z = 0.74563;  //adjust to desired z position
   //Define the orientation 
  goal1_pose.orientation.x = -0.22954;
  goal1_pose.orientation.y = 0.86737;
  goal1_pose.orientation.z = 0.388;
  goal1_pose.orientation.w = 0.21078;

    //Set the target pose for the arm move group
  arm_move_group.setPoseTarget(goal1_pose);
  moveit::planning_interface::MoveGroupInterface::Plan goal1_plan;
  if (arm_move_group.plan(goal1_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
      if (arm_move_group.execute(goal1_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
          RCLCPP_INFO(logger, "Moved to goal1_plan successfully.");
      } else {
          RCLCPP_ERROR(logger, "Execution to goal1_plan failed!");
          return 1; //Early exit due to failure
      }
  } else {
    RCLCPP_ERROR(logger, "Planning to goal1_plan failed!");
      return 1; //Early exit due to failure
  }
  
//Set joint values manually for 'close_pos'
  std::map<std::string, double> target_joints_close;
  target_joints_close["panda_finger_joint1"] = 0;
  target_joints_close["panda_finger_joint2"] = 0;

  gripper_move_group.setJointValueTarget(target_joints_close);
  moveit::planning_interface::MoveGroupInterface::Plan close_plan;
  
  if (gripper_move_group.plan(close_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
      gripper_move_group.execute(close_plan);
  } else {
      RCLCPP_ERROR(node->get_logger(), "Planning to manually close gripper failed!");
      return 1;
  }
  

  //Move to goal state 1
  geometry_msgs::msg::Pose goal2_pose;
  goal2_pose.position.x = 0.14253;  //Adjust to desired x position
  goal2_pose.position.y = -0.56771;  //Adjust to desired y position
  goal2_pose.position.z = 0.3131;  //Adjust to desired z position
   //Define the orientation (for example, a straightforward orientation)
  goal2_pose.orientation.x = 0.85716;
  goal2_pose.orientation.y = 0.48818;
  goal2_pose.orientation.z = 0.15344;
  goal2_pose.orientation.w = 0.058455;

    //Set the target pose for the arm move group
  arm_move_group.setPoseTarget(goal2_pose);
  moveit::planning_interface::MoveGroupInterface::Plan goal2_plan;
  if (arm_move_group.plan(goal2_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
      if (arm_move_group.execute(goal2_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
          RCLCPP_INFO(logger, "Moved to goal2_pose successfully.");
      } else {
          RCLCPP_ERROR(logger, "Execution to goal2_pose failed!");
          return 1; //Early exit due to failure
      }
  } else {
    RCLCPP_ERROR(logger, "Planning to goal2_pose failed!");
      return 1; //Early exit due to failure
  }
  
  //Set joint values manually for 'open_pos'
  std::map<std::string, double> target_joints_open;
  target_joints_open["panda_finger_joint1"] = 0.0122;
  target_joints_open["panda_finger_joint2"] = 0.0122;

  gripper_move_group.setJointValueTarget(target_joints_open);
  moveit::planning_interface::MoveGroupInterface::Plan open_plan;

  if (gripper_move_group.plan(open_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
      gripper_move_group.execute(open_plan);
  } else {
      RCLCPP_ERROR(node->get_logger(), "Planning to manually open gripper failed!");
      return 1;
  }
  
    //Move to home position
  geometry_msgs::msg::Pose home_final;
  home_final.position.x = 0.56545;  //Adjust to desired x position
  home_final.position.y = 0.11099;  //Adjust to desired y position
  home_final.position.z = 0.8494;  //Adjust to desired z position
   //Define the orientation (for example, a straightforward orientation)
  home_final.orientation.x = 0.877;
  home_final.orientation.y = -0.206131;
  home_final.orientation.z = 0.419747;
  home_final.orientation.w = -0.104719;

    //Set the target pose for the arm move group
  arm_move_group.setPoseTarget(home_final);
  moveit::planning_interface::MoveGroupInterface::Plan final_plan;
  if (arm_move_group.plan(final_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
      if (arm_move_group.execute(final_plan) == moveit::core::MoveItErrorCode::SUCCESS) {
          RCLCPP_INFO(logger, "Moved to home_pose successfully.");
      } else {
          RCLCPP_ERROR(logger, "Execution to home_pose failed!");
          return 1; //Early exit due to failure
      }
  } else {
    RCLCPP_ERROR(logger, "Planning to home_pose failed!");
      return 1; //Early exit due to failure
  }
  

  //Shutdown ROS
  rclcpp::shutdown();
  return 0;
}
