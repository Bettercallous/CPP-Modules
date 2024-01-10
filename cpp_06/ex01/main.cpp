#include "Serializer.hpp"

int main()
{
    Data data = {5, 10, 3.5, 'A'};

    // int *p = reinterpret_cast<int*>(&data);

    // std::cout << *(reinterpret_cast<int*>(p++)) << std::endl;
    // std::cout << *(reinterpret_cast<int*>(p++)) << std::endl;
    // std::cout << *(reinterpret_cast<float*>(p++)) << std::endl;
    // std::cout << *(reinterpret_cast<char*>(p)) << std::endl;

    uintptr_t i = Serializer::serialize(&data);
    Data *newData = Serializer::deserialize(i);

    std::cout << &data << std::endl;
    std::cout << newData << std::endl;
    
    return 0;
}