// Copyright 2021 Zoreev Mikhail
#include <gtest/gtest.h>

#include <vector>

#include "include/radix_sort.h"

#include <iostream>

TEST(RadixSort_Test, Test_Sort) {
    std::vector<int64_t> vector = {10, 5, 4, 8, 16, 1, 32, 0};
    RadixSort::radixSort(vector.begin(), vector.end());

    for(size_t i = 0; i < 8; i++) {
        std::cout << vector[i] << " ";
    }
}
