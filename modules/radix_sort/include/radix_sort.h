// Copyright 2021 Zoreev Mikhail

#ifndef MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
#define MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_

#include <vector>
#include <stdexcept>
namespace RadixSort {
    /**
     * Sorts
     * @param begin
     * @param end
     */
    void radixSort(std::vector<int64_t>::iterator begin, std::vector<int64_t>::iterator end);
}  // namespace RadixSort


#endif //MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_H_
