#include <cmath>
#include <string>
#include <memory>

#include "nav2_util/node_utils.hpp"
#include "straight_line_global_planner/straight_line_global_planner.hpp"

namespace nav2_straight_line_global_planner
{
    void StraightLine::configure(
                const rclcpp_lifecycle::LifecycleNode::WeakPtr & parent,
                std::string name,
                std::shared_ptr<tf2_ros::Buffer> tf,
                std::shared_ptr<nav2_costmap_2d::Costmap2DROS> costmap_ros) 
    {
        node_ = parent.lock();
        name_ = name;
        tf_ = tf;
        costmap_ = costmap_ros->getCostmap();
        global_frame_ = costmap_ros->getGlobalFrameID();

        nav2_util::declare_parameter_if_not_declared(
            node_, 
            name_ + ".interpolation_resolution", 
            rclcpp::ParameterValue(0.1)
        );

        node_->get_parameter(name_ + ".interpolation_resolution", interpolation_resolution_);

    }

    void StraightLine::cleanup() 
    {
        RCLCPP_INFO(
            node_->get_logger(), 
            "Cleaning up plugin %s of type StraightLine", 
            name_.c_str()
        );
    }

    void StraightLine::activate() 
    {
        RCLCPP_INFO(
            node_->get_logger(), 
            "Activating plugin %s of type StraightLine", 
            name_.c_str()
        );
    }

    void StraightLine::deactivate() 
    {
        RCLCPP_INFO(
            node_->get_logger(), 
            "Deactivating plugin %s of type StraightLine", 
            name_.c_str()
        );
    }

    nav_msgs::msg::Path StraightLine::createPlan(
        const geometry_msgs::msg::PoseStamped & start,
        const geometry_msgs::msg::PoseStamped & goal)
    {
        nav_msgs::msg::Path global_path;

        if(start.header.frame_id != global_frame_)
        {
            RCLCPP_ERROR(
                node_->get_logger(), 
                "This planner will only accept start poses in the %s frame, but a pose was sent in the %s frame.", 
                global_frame_.c_str(), 
                start.header.frame_id.c_str()
            );
            return global_path;
        }

        if(goal.header.frame_id != global_frame_)
        {
            RCLCPP_ERROR(
                node_->get_logger(), 
                "This planner will only accept goal poses in the %s frame, but a pose was sent in the %s frame.", 
                global_frame_.c_str(), 
                goal.header.frame_id.c_str()
            );
            return global_path;
        }

        

    }
    

}