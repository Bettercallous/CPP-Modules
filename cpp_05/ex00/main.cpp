#include "Bureaucrat.hpp"

int main() 
{
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << "------------  Test 1 : passing invalid grade to constructor  ------------" << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	try {
		Bureaucrat a(0, "Juan");
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << "----------  Test 2 : incrementing the highest possible grade  -----------" << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;

	Bureaucrat a(2, "Juan");
	std::cout << "- Bureaucrat info: ";
	std::cout << a;

	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << ">> Incrementing grade 2 (this is fine, grade will be 1): " << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	a.incrementGrade();
	std::cout << "- Bureaucrat info: ";
	std::cout << a;
	std::cout << "-------------------------------------------------------------------------" << std::endl;

	try {
		std::cout << ">> Incrementing grade 1 (this is not fine, an exception will be thrown): " << std::endl;
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		a.incrementGrade();
		// the folowing two lines will not be shown
		std::cout << "- Bureaucrat info: ";
		std::cout << a;
		std::cout << "-------------------------------------------------------------------------" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "* caught the exception : " << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << "- Bureaucrat info: ";
	std::cout << a;
	std::cout << "-------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << "-----------  Test 3 : decrementing the lowest possible grade  -----------" << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	Bureaucrat c(150, "Oz");

	try {
		std::cout << ">> Incrementing grade 150 will throw an exception: " << std::endl;
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		c.decrementGrade();
		std::cout << "-------------------------------------------------------------------------" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "* caught the exception : " << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------" << std::endl;

}