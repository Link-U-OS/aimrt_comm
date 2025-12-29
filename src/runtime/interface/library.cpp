// Copyright (c) 2025, AgiBot Inc.
// All rights reserved.

#include "./library.h"
#include "src/panic/panic.h"
#include "src/runtime/internal/internal.h"
#include "src/utils/utils.h"

namespace aimrte::runtime
{
Library::Library()
{
  // if (const std::string lib_path = utils::Env("AIMRTE_RUNTIME_LIBRARY_PATH", "libaimrte_runtime.so"); not lib_.Load(lib_path))
  //   panic().wtf("Unable to load AimRTe runtime library at [{}] !", lib_path);

  // ptr_ = lib_.f<decltype(AimRTeCreateRuntimeCore)>("AimRTeCreateRuntimeCore")();
  ptr_ = AimRTeCreateRuntimeCore();
}

Library::~Library()
{
  // lib_.f<decltype(AimRTeDestroyRuntimeCore)>("AimRTeDestroyRuntimeCore")(ptr_);
  AimRTeDestroyRuntimeCore(ptr_);
}
}  // namespace aimrte::runtime
