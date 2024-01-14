#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {

	std::srand(time(0));
	int randomNum = std::rand() % 3;

	switch (randomNum) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			std::cerr << "Error" << std::endl;
	}
	return NULL;
}

void identify(Base* p) {

	if (dynamic_cast<A*>(p))
		std::cout << "Actual type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Actual type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Actual type is C" << std::endl;
	else
		std::cerr << "Unknown type" << std::endl;
}

void identify(Base& p) {

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Actual type is A" << std::endl;
	} catch (const std::exception&) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "Actual type is B" << std::endl;
		} catch (const std::exception&) {
			try {
				(void)dynamic_cast<C&>(p);
				std::cout << "Actual type is C" << std::endl;
			} catch (const std::exception&) {
				std::cerr << "Unknown type" << std::endl;
			}
		}
	}
}

int main()
{
	Base* generatedObject = generate();

	if (generatedObject) {
		identify(generatedObject);
		identify(*generatedObject);

		delete generatedObject;
	}

	return 0;
}