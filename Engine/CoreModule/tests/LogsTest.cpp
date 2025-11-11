//
// Created by kolya on 9/14/2021.
//
#include "CoreModule/src/Log/Logs.h"
#include "gtest/gtest.h"

MAKE_LOG_CATEGORY(Logtesttest);
MAKE_LOG_CATEGORY(LogSecTest);

TEST(suite, test)
{
    INFO(Logtesttest, "wha");
    INFO(Logtesttest, "what");
    INFO(LogSecTest, "whatt");
    WARN(Logtesttest, "wha");
    WARN(Logtesttest, "what");
    WARN(LogSecTest, "whatt");
    ERROR(Logtesttest, "wha");
    ERROR(Logtesttest, "what");
    ERROR(LogSecTest, "whatt");

    // verbose
    VINFO(Logtesttest, "whatt {}", 1);
    VWARN(Logtesttest, "whatt {}", 2);
    VERROR(Logtesttest, "wha {}", 4);

    ASSERT_TRUE(true);
}
