load("@integration//rules/utils:header_utils.bzl", "cc_library_with_top_header")

package(default_visibility = ["//visibility:public"])

cc_library_with_top_header(
    name = "aimrte_runtime",
    srcs = [
        "impl.cpp",
    ],
    hdrs = [],
    linkopts = [
    ],
    deps = [
        "//src/runtime/internal",
        "@aimrt//:libaimrt",
    ],
)
