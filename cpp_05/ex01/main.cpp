#include "Bureaucrat.hpp"

int main() 
{
	try {

		Bureaucrat b(2, "Juan");
		Form f("Contract", 1, 1);

		b.signForm(f);

		b.incrementGrade();

		b.signForm(f);

	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
