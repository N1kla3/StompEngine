#include "CoreModule/src/Log/Logs.h"
#include "RenderModule/src/testfile.h"

MAKE_LOG_CATEGORY(CoreModuleLog);

int main()
{
    INFO(CoreModuleLog, "======================= Start Engine =======================");
#if STOMP_EDITOR
    INFO(CoreModuleLog, "======================= Start Editor =======================");
#endif

    function();

    INFO(CoreModuleLog, "======================= Close Engine =======================");
    return 0;
}
