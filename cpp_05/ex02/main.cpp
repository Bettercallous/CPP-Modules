#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
	try {

		Bureaucrat b(6, "Juan");
		PresidentialPardonForm form("contract");

		// b.signForm(form);

		// b.incrementGrade();

		b.signForm(form);

		b.executeForm(form);

	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
