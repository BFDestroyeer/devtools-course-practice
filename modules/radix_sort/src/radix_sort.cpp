// Copyright 2021 Zoreev Mikhail

#include "include/radix_sort.h"

namespace RadixSort {
    void radixSort(std::vector<int64_t>::iterator begin, std::vector<int64_t>::iterator end) {
        if (end < begin) {
            throw std::runtime_error("begin should be lower than end");
        }
        std::vector<int64_t> temp(std::distance(begin, end));
        for (size_t i = 0; i < sizeof(int64_t); i++) {
            size_t count[256] = {};
            for (auto j = begin; j < end; j++) {
                count[*((unsigned char*) &*j + i)]++;
            }
            size_t offset[256] = {};
            if (i != sizeof(int64_t) - 1) {
                for (size_t j = 1; j < 256; j++) {
                    offset[j] = offset[j - 1] + count[j - 1];
                }
            } else {
                for (size_t j = 129; j < 256; j++) {
                    offset[j] = offset[j - 1] + count[j - 1];
                }
                offset[0] = offset[255] + count[255];
                for (size_t j = 1; j < 128; j++) {
                    offset[j] = offset[j - 1] + count[j - 1];
                }
            }
            for (auto j = begin; j < end; j++) {
                temp[offset[*((unsigned char*) &*j + i)]++] = *j;
            }
            std::copy(temp.begin(), temp.end(), begin);
        }
    }
}  // namespace RadixSort
