load("@integration//rules/utils:ros.bzl", "ros_utils")

package(default_visibility = ["//visibility:public"])

ros_utils(
    name = "pose_msgs_utils",
    interface_name = "pose_msgs",
    msgs = [
        "@aima_protocol//aimdk/protocol/hal/pose/msg:PoseCommand.msg",
        "@aima_protocol//aimdk/protocol/hal/pose/msg:PoseState.msg",
        "@aima_protocol//aimdk/protocol/hal/pose/msg:PoseCommands.msg",
        "@aima_protocol//aimdk/protocol/hal/pose/msg:PoseStates.msg",
        "@aima_protocol//aimdk/protocol/hal/pose/msg:TorqSensorState.msg",
    ],
    type_support_name = "aimdk_protocol_pose_msgs",
    deps = [
        "@ros2_common_interfaces//:std_msgs",
        "@ros2_rcl_interfaces//:builtin_interfaces",
    ],
)
