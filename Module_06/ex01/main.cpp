#include "Serializer.hpp"

int main() {

	Data originalData = {42, 99, 3.14f, 'A'};

	uintptr_t serializedData = Serializer::serialize(&originalData);

	Data* deserializedData = Serializer::deserialize(serializedData);

	std::cout << "Original Data    : x = " << originalData.x << ", y = " << originalData.y << ", b = "
			  << originalData.b << ", c = " << originalData.c << ", Address: " << &originalData << std::endl;

	std::cout << "Deserialized Data: x = " << deserializedData->x << ", y = " << deserializedData->y << ", b = "
			  << deserializedData->b << ", c = " << deserializedData->c<< ", Address: " << deserializedData << std::endl;

	return 0;
}
