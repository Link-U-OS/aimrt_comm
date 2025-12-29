load("@integration//rules/utils:ros.bzl", "ros_utils")

package(default_visibility = ["//visibility:public"])

ros_utils(
    name = "record_playback_msg_utils",
    interface_name = "record_playback_msgs",
    msgs = [
        "@aima_protocol//ros2/record_playback/msg:RecordUpload.msg",
        "@aima_protocol//ros2/record_playback/msg:ActionInfo.msg",
        "@aima_protocol//ros2/record_playback/msg:BagInfo.msg",
        "@aima_protocol//ros2/record_playback/msg:TopicMeta.msg",
    ],
    type_support_name = "ros2_record_playback_msgs",
    deps = [
        "@ros2_rcl_interfaces//:builtin_interfaces",
    ],
)
