#include "testfile.h"

#include "CoreModule/src/Log/Logs.h"

MAKE_LOG_CATEGORY(RenderLog);

void function()
{
    INFO(RenderLog, "Ay");
}
