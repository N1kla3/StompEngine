#pragma once
#include <memory>

namespace omp
{
    template<typename T>
    using UniquePtr = std::unique_ptr<T>;
}
