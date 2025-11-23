#pragma once
#include <memory>

namespace omp
{
    template<typename T>
    using SharedPtr = std::shared_ptr<T>;

    template<typename T>
    using WeakPtr = std::weak_ptr<T>;
} // namespace omp
