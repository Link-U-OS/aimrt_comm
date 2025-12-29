load("@integration//rules/utils:header_utils.bzl", "cc_library_with_top_header")

package(default_visibility = ["//visibility:public"])

config_setting(
    name = "force_interface_mode",
    define_values = {
        "AIMRTE_FORCE_INTERFACE_MODE": "1",
    },
)

cc_library_with_top_header(
    name = "interface",
    srcs = [
        "library.cpp",
    ],
    hdrs = [
        "library.h",
    ],
    deps = [
        "//src/dynamic_lib",
        "//src/panic",
        "//src/runtime/base",
        "//src/runtime/internal",
        "//src/utils",
        
    ] + select({
        "//conditions:default": [
            "//src/runtime/impl:aimrte_runtime",
        ],
        ":force_interface_mode": [],
    }),
    data = [
    ]
)

cc_test(
    name = "library_test",
    srcs = [
        "library_test.cpp",
    ],
    deps = [
        ":interface",
        "//src/test",
    ],
)