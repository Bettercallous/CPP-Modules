#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec(3);

    vec.insert(vec.begin(), 3);
    vec.insert(vec.begin() + 1, 2);

    vec.push_back(3);

    const std::vector<int> vec2(vec) ;

    std::vector<int>::const_iterator it = easyfind(vec2, 3);
    if (it != vec2.end())
        std::cout << "Element found: "<< *it << std::endl;
    else
        std::cout << "Element not found" << std::endl;


    std::list<int> lst(3);

    lst.push_back(3);
    lst.push_back(6);
    lst.push_back(4);

    std::list<int>::const_iterator it2 = easyfind(lst, 6);
    if (it2 != lst.end())
        std::cout << "Element found: "<< *it2 << std::endl;
    else
        std::cout << "Element not found" << std::endl;
    return 0;

}