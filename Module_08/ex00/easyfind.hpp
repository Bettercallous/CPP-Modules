#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& c, const int toFind)
{
    typename T::iterator it = std::find(c.begin(), c.end(), toFind);
    return it != c.end() ? it : c.end();
}

template <typename T>
typename T::const_iterator easyfind(const T& c, const int toFind)
{
    typename T::const_iterator it = std::find(c.begin(), c.end(), toFind);
    return it != c.end() ? it : c.end();
}

#endif