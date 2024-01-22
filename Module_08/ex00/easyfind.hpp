#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
typename T::const_iterator easyfind(const T& c, int toFind)
{
    for (typename T::const_iterator it = c.begin(); it != c.end(); it++) {
        if (*it == toFind)
            return it;
    }
    return c.end();
}

#endif