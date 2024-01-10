#include "Serializer.hpp"

int main()
{
    Data data;
    
    uintptr_t i = Serializer::serialize(&data);
    Data *newData = Serializer::deserialize(i);

    std::cout << &data << std::endl;
    std::cout << newData << std::endl;
    
    return 0;
}