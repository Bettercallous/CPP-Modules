#include "easyfind.hpp"

int main()
{
    std::vector<int> vec(3);

    vec.insert(vec.begin(), 3);
    vec.insert(vec.begin() + 1, 2);

    vec.push_back(3);

    std::vector<int>::const_iterator it = easyfind(vec, 3);
    if (it != vec.end())
        std::cout << "Element found: "<< *it << std::endl;
    else
        std::cout << "Element not found" << std::endl;
    return 0;

}