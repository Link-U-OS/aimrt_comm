// Copyright (c) 2025, AgiBot Inc.
// All rights reserved.

#include "src/runtime/core/aimrt_core.h"
#include "src/runtime/internal/internal.h"
#include <chrono>
#include <thread>

namespace aimrte::runtime
{
class Core final : public ICore
{
 public:
  void RegisterHook(State state, std::function<void()> func) override
  {
    impl_.RegisterHookFunc(static_cast<aimrt::runtime::core::AimRTCore::State>(state), std::move(func));
  }

  void RegisterModule(const aimrt_module_base_t* module) override
  {
    impl_.GetModuleManager().RegisterModule(module);
  }

  void Initialize(std::string cfg_file_path) override
  {
    impl_.Initialize({.cfg_file_path = std::move(cfg_file_path)});
  }

  void Start() override
  {
    impl_.Start();
  }

  void WaitStarted() override
  {
    while (impl_.GetState() < aimrt::runtime::core::AimRTCore::State::kPostStart or
           impl_.GetMainThreadExecutor().GetState() < aimrt::runtime::core::executor::MainThreadExecutor::State::kStart)
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  State GetState() const override
  {
    return static_cast<State>(impl_.GetState());
  }

  void Shutdown() override
  {
    impl_.Shutdown();
  }

 private:
  aimrt::runtime::core::AimRTCore impl_;
};
}  // namespace aimrte::runtime

extern "C" {
AIMRTE_SYMBOL_EXPORT aimrte::runtime::ICore* AimRTeCreateRuntimeCore()
{
  return new aimrte::runtime::Core{};
}

AIMRTE_SYMBOL_EXPORT void AimRTeDestroyRuntimeCore(const aimrte::runtime::ICore* ptr)
{
  delete ptr;
}
}
