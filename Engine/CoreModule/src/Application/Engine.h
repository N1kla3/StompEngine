#pragma once
#include "Memory/UniquePtr.h"

namespace omp
{
    class Engine
    {
    public:
        void PreInit();
        void Init();
        void Deinitialize();

    private:
    };
} // namespace omp
