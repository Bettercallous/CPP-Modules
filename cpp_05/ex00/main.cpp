#include "Bureaucrat.hpp"

void invalidGradeToConstructor() {
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << "------------  Test 1 : passing invalid grade to constructor  ------------" << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	
	try {
		Bureaucrat a(0, "Juan");
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}

void incrementHighestGrade() {
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << "----------  Test 2 : incrementing the highest possible grade  -----------" << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;

	Bureaucrat a(2, "Juan");
	std::cout << "- Bureaucrat info: ";
	std::cout << a;

	std::cout << ">> Incrementing grade 2 : " << std::endl;
	
	a.incrementGrade();
	
	std::cout << "- Bureaucrat info: ";
	std::cout << a;

	try {
		std::cout << ">> Incrementing grade 1 : " << std::endl;

		a.incrementGrade();

	}
	catch (std::exception & e) {
		std::cerr << "* caught the exception : " << e.what() << std::endl;
	}

	std::cout << "- Bureaucrat info: ";
	std::cout << a;

	std::cout << std::endl;
}

void decrementLowestGrade() {
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << "-----------  Test 3 : decrementing the lowest possible grade  -----------" << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	
	Bureaucrat c(150, "Oz");

	try {
		std::cout << ">> Decrementing grade 150 : " << std::endl;

		c.decrementGrade();

	}
	catch (std::exception & e) {
		std::cerr << "* caught the exception : " << e.what() << std::endl;
	}
	
	std::cout << "-------------------------------------------------------------------------" << std::endl;
}

int main() 
{
	invalidGradeToConstructor();
	incrementHighestGrade();
	decrementLowestGrade();
}