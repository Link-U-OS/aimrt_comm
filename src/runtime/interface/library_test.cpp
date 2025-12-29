// Copyright (c) 2025, AgiBot Inc.
// All rights reserved.

#include "src/runtime/interface/interface.h"
#include <gtest/gtest.h>

namespace aimrte::runtime
{
class LibraryTest : public ::testing::Test
{
};

TEST_F(LibraryTest, BasicUsage)
{
  Library lib;
  GTEST_ASSERT_EQ(lib->GetState(), State::kPreInit);
}
}  // namespace aimrte::runtime
