#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& c, const int toFind) {
    return std::find(c.begin(), c.end(), toFind);
}

#endif