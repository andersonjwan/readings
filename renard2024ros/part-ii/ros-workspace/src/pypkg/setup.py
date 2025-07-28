from setuptools import find_packages, setup

package_name = 'pypkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ubuntu',
    maintainer_email='ubuntu@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "a = pypkg.a:main",
            "b = pypkg.b:main",
            "c = pypkg.c:main",
            "d = pypkg.d:main",
            "e = pypkg.e:main",
            "f = pypkg.f:main",
            "g = pypkg.g:main",
            "h = pypkg.h:main",
        ],
    },
)
