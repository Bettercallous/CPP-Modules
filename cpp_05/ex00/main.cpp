#include "Bureaucrat.hpp"

int main() 
{
	Bureaucrat a(2, "Juan");
	std::cout << "-------------------------------------------------------------------------" << std::endl;

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

}