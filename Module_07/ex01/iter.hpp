#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename U>
void iter(T* arr, size_t len, U f)
{
    if (!arr || !f)
        return;
    for (size_t i = 0; i < len; i++) {
        f(arr[i]);
    }
}

#endif