#include "Serializer.hpp"

/*
	Serialization is the process of converting an object or data structure into a format that can be easily stored or transmitted,
	typically for the purpose of saving it to a file or sending it over a network. Deserialization is the reverse process, where
	the serialized data is converted back into its original form.
*/

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
