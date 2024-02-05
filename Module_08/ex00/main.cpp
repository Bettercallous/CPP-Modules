#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec(3);
    vec.push_back(1);
    vec.push_back(69);
    vec.push_back(88);
    vec.push_back(-45);

    std::vector<int>::iterator it = easyfind(vec, 69);
    if (it != vec.end())
        std::cout << "Element found: "<< *it << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    std::list<int> lst(vec.begin(), vec.end());
    std::list<int>::iterator it2 = easyfind(lst, -5);
    if (it2 != lst.end())
        std::cout << "Element found: "<< *it2 << std::endl;
    else
        std::cout << "Element not found" << std::endl;
    return 0;
}