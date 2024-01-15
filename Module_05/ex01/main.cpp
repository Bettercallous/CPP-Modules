#include "Bureaucrat.hpp"

void gradeOutOfBoundsTest()
{
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "-------------------  Test 1 -------------------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	// passing an out of bounds grade to form :
	try {
		Form f("contract", 0, 5);
	}
	catch (std::exception& e) {
		std::cerr << "caught the exception : " << e.what() << std::endl;
	}

	try {
		Form f2("contract2", 20, 151);
	}
	catch (std::exception& e) {
		std::cerr << "caught the exception : " << e.what() << std::endl;
	}
	std::cout << "-----------------------------------------------" << std::endl;
}

void beSignedTest()
{

	std::cout << "-------------------  Test 2 -------------------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	Bureaucrat b(10, "Juan");
	Bureaucrat b2(1, "Joe");
	Form f("someForm", 5, 5);

	try {
		// this is fine, b2's grade is high enough
		f.beSigned(b2);
		std::cout << f;
		// this is not fine, b's grade is too low
		f.beSigned(b);
	}
	catch (std::exception& e) {
		std::cerr << "Caught the exception : " << e.what() << std::endl;
	}
	std::cout << "-----------------------------------------------" << std::endl;
}

void signFormTest()
{
	std::cout << "-------------------  Test 3 -------------------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	
	Bureaucrat b(10, "Juan");
	Bureaucrat b2(11, "Joe");
	Form f("someForm", 10, 5);

	// this is fine, b's grade is high enough to sign f
	b.signForm(f);
	std::cout << f;
	// this is not fine, an exception will be thrown and handled inside signForm
	b2.signForm(f);
	std::cout << "-----------------------------------------------" << std::endl;
}

int main()
{
	gradeOutOfBoundsTest();
	beSignedTest();
	signFormTest();
}
