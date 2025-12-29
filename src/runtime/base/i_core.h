// Copyright (c) 2025, AgiBot Inc.
// All rights reserved.

#pragma once

#include "src/interface/aimrt_module_c_interface/module_base.h"
#include <cstdint>
#include <functional>
#include <string>

namespace aimrte::runtime
{
enum class State : std::uint32_t {
  kPreInit,

  kPreInitConfigurator,
  kPostInitConfigurator,

  kPreInitPlugin,
  kPostInitPlugin,

  kPreInitMainThread,
  kPostInitMainThread,

  kPreInitGuardThread,
  kPostInitGuardThread,

  kPreInitExecutor,
  kPostInitExecutor,

  kPreInitLog,
  kPostInitLog,

  kPreInitAllocator,
  kPostInitAllocator,

  kPreInitRpc,
  kPostInitRpc,

  kPreInitChannel,
  kPostInitChannel,

  kPreInitParameter,
  kPostInitParameter,

  kPreInitModules,
  kPostInitModules,

  kPostInit,

  kPreStart,

  kPreStartConfigurator,
  kPostStartConfigurator,

  kPreStartPlugin,
  kPostStartPlugin,

  kPreStartMainThread,
  kPostStartMainThread,

  kPreStartGuardThread,
  kPostStartGuardThread,

  kPreStartExecutor,
  kPostStartExecutor,

  kPreStartLog,
  kPostStartLog,

  kPreStartAllocator,
  kPostStartAllocator,

  kPreStartRpc,
  kPostStartRpc,

  kPreStartChannel,
  kPostStartChannel,

  kPreStartParameter,
  kPostStartParameter,

  kPreStartModules,
  kPostStartModules,

  kPostStart,

  kPreShutdown,

  kPreShutdownModules,
  kPostShutdownModules,

  kPreShutdownParameter,
  kPostShutdownParameter,

  kPreShutdownChannel,
  kPostShutdownChannel,

  kPreShutdownRpc,
  kPostShutdownRpc,

  kPreShutdownAllocator,
  kPostShutdownAllocator,

  kPreShutdownLog,
  kPostShutdownLog,

  kPreShutdownExecutor,
  kPostShutdownExecutor,

  kPreShutdownGuardThread,
  kPostShutdownGuardThread,

  kPreShutdownMainThread,
  kPostShutdownMainThread,

  kPreShutdownPlugin,
  kPostShutdownPlugin,

  kPreShutdownConfigurator,
  kPostShutdownConfigurator,

  kPostShutdown,
};

class ICore
{
 public:
  virtual ~ICore() = default;

  /**
   * @brief 注册钩子
   */
  virtual void RegisterHook(State state, std::function<void()> func) = 0;

  /**
   * @brief 注册一个模块
   */
  virtual void RegisterModule(const aimrt_module_base_t* module) = 0;

  /**
   * @brief 初始化 AimRT 框架
   * @param cfg_file_path 配置文件路径
   */
  virtual void Initialize(std::string cfg_file_path) = 0;

  /**
   * @brief 启动框架
   */
  virtual void Start() = 0;

  /**
   * @brief 等待框架已经完全启动，仅用于 test controller
   */
  virtual void WaitStarted() = 0;

  /**
   * @return 获取框架状态
   */
  [[nodiscard]] virtual State GetState() const = 0;

  /**
   * @brief 关闭框架
   */
  virtual void Shutdown() = 0;
};
}  // namespace aimrte::runtime
