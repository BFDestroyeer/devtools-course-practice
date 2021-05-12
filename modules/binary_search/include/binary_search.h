// Copyright 2021 Makarov Alexander

#ifndef MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
#define MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_

#include <stdexcept>
#include <string>
#include <vector>

namespace BinarySearch {

    template <typename T>
    int Search(const T& key, const std::vector<T>& array, int left, int right) {
        if (left < 0 || left >= static_cast<int>(array.size())) {
            throw std::runtime_error("Left border out of range");
        }
        if (right < 0 || right >= static_cast<int>(array.size())) {
            throw std::runtime_error("Right border out of range");
        }
        if (right < left) {
            throw std::runtime_error(
                    "Right border must be greater than left border");
        }
        int middle;
        bool is_founded = false;
        while (left <= right && !is_founded) {
            middle = (left + right) / 2;
            if (array[middle] == key)
                is_founded = true;
            else if (array[middle] > key)
                right = middle - 1;
            else
                left = middle + 1;
        }
        return is_founded ? middle : -1;
    }

}  // namespace BinarySearch

#endif  // MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
