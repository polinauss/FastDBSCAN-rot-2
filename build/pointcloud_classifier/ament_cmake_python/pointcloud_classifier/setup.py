from setuptools import find_packages
from setuptools import setup

setup(
    name='pointcloud_classifier',
    version='0.0.1',
    packages=find_packages(
        include=('pointcloud_classifier', 'pointcloud_classifier.*')),
)
