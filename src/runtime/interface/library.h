// Copyright (c) 2025, AgiBot Inc.
// All rights reserved.

#pragma once

#include "src/dynamic_lib/dynamic_lib.h"
#include "src/runtime/base/base.h"

namespace aimrte::runtime
{
class Library
{
 public:
  /**
   * @brief 将强制加载 AimRT 框架，如果加载失败，将报错
   */
  Library();

  /**
   * @brief 卸载框架动态库
   */
  ~Library();

  ICore* operator->()
  {
    return ptr_;
  }

  [[nodiscard]] ICore& Ref()
  {
    return *ptr_;
  }

  [[nodiscard]] const ICore& Ref() const
  {
    return *ptr_;
  }

 private:
  // DynamicLib lib_;
  ICore* ptr_{nullptr};
};
}  // namespace aimrte::runtime
