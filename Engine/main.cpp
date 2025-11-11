#include "CoreModule/src/Log/Logs.h"

MAKE_LOG_CATEGORY(CoreModuleLog);

int main()
{
    INFO(CoreModuleLog, "======================= Start Engine =======================");
#if STOMP_EDITOR
    INFO(CoreModuleLog, "======================= Start Editor =======================");
#endif

    INFO(CoreModuleLog, "======================= Close Engine =======================");
    return 0;
}
