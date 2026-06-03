from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='pointcloud_classifier',
            executable='classifier_node',
            name='classifier',
            parameters=[{
                'fastdbscan_K': 80,
                'fastdbscan_t': 0.12,
                'fastdbscan_eps': 0.5,
                'fastdbscan_minPts': 40,
                'filter_mean_k': 50,
                'filter_stddev_mult': 1.0,
                'output_file': '/home/polinaus/classification_results.txt',
                'save_to_file': True
            }]
        )
    ])
