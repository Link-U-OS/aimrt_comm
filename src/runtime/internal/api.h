// Copyright (c) 2025, AgiBot Inc.
// All rights reserved.

#pragma once

#include "src/runtime/base/base.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define AIMRTE_SYMBOL_EXPORT __attribute__((dllexport))
  #else
    #define AIMRTE_SYMBOL_EXPORT __declspec(dllexport)
  #endif
#else
  #define AIMRTE_SYMBOL_EXPORT __attribute__((visibility("default")))
#endif

/**
 * @return 创建并初始化一个 AimRT core 的实例
 */
AIMRTE_SYMBOL_EXPORT aimrte::runtime::ICore* AimRTeCreateRuntimeCore();

/**
 * @brief 销毁 AimRT core 示例
 */
AIMRTE_SYMBOL_EXPORT void AimRTeDestroyRuntimeCore(const aimrte::runtime::ICore* ptr);

#ifdef __cplusplus
}
#endif
