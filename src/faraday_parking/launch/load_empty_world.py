import os
import launch_ros
import launch



def generate_launch_description():
    project_dir = launch_ros.substitutions.FindPackageShare(package='faraday_parking').find('faraday_parking')
    world_path=os.path.join(project_dir, 'worlds/empty_world.world')
    use_sim_time = launch.substitutions.LaunchConfiguration('use_sim_time')


    namespace = launch.substitutions.LaunchConfiguration('namespace')
    use_namespace = launch.substitutions.LaunchConfiguration('use_namespace')
    world = launch.substitutions.LaunchConfiguration('world')



    declare_namespace_cmd = launch.actions.DeclareLaunchArgument(
        'namespace',
        default_value='wworld',
        description='Top-level namespace')
    
    declare_use_namespace_cmd = launch.actions.DeclareLaunchArgument(
        'use_namespace',
        default_value='false',
        description='Whether to apply a namespace to the navigation stack')
    
    declare_world_cmd = launch.actions.DeclareLaunchArgument(
        'world',
        default_value=world_path,
        description='Full path to world model file to load')
    
    declare_use_sim_time_cmd = launch.actions.DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true')
    
    start_gazebo_server_cmd = launch.actions.ExecuteProcess(
        cmd=['gzserver', '--verbose', '-s', 'libgazebo_ros_init.so', world],
        output='screen')
    
    start_gazebo_client_cmd = launch.actions.ExecuteProcess(
        cmd=['gzclient'],
        output='screen')
    
    ld = launch.LaunchDescription()

    ld.add_action(declare_namespace_cmd)
    ld.add_action(declare_use_namespace_cmd)
    ld.add_action(declare_world_cmd)
    ld.add_action(declare_use_sim_time_cmd)
    ld.add_action(start_gazebo_server_cmd)
    ld.add_action(start_gazebo_client_cmd)
    return ld

