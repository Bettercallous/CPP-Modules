#include <iostream>
#include "Array.hpp"

int main()
{
	Array<std::string>* a = new Array<std::string>(2);

	try {
		(*a)[0] = "Hello";
		(*a)[1] = "World";
	    std::cout << (*a)[0] << " " << (*a)[1] << std::endl;
	    std::cout << a->size() << std::endl;
	    std::cout << (*a)[3] << std::endl;
	} catch (std::exception& e) {
	    std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Array<std::string> b;
	std::cout << b.size() << std::endl;
	try {
		std::cout << b[0] << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	b = *a;
	delete a;
	try {
		std::cout << b.size() << std::endl;
		std::cout << b[0] << " " << b[1] << std::endl;
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
