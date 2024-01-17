#include "iter.hpp"

template <typename V>
void fnc(V& c) {
    c += 1;
}

int main()
{
    char str[] = "abcde";
    iter(str, 5, fnc);
    std::cout << str << std::endl;

    int arr[] = {1, 2 , 3, 4};
    iter(arr, 4, fnc);
    for (int i = 0; i < 4; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    float arr2[] = {1.5, 2.3, 5.2};
    iter(arr2, 3, fnc);
    for (int i = 0; i < 3; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
