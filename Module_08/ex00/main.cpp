#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec(3);

    vec.insert(vec.begin(), 3);
    vec.insert(vec.begin() + 1, 2);

    vec.push_back(3);

    std::list<int> lst(3);

    lst.push_back(3);
    lst.push_back(6);
    lst.push_back(4);

    std::list<int>::iterator it = easyfind(lst, 6);
    if (it != lst.end())
        std::cout << "Element found: "<< *it << std::endl;
    else
        std::cout << "Element not found" << std::endl;
    return 0;
}