#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename U>
void iter(T* arr, U len, void (*funcPtr)(T&))
{
    if (len <= 0)
        return;
    for (int i = 0; i < len; i++) {
        funcPtr(arr[i]);
    }
}

#endif