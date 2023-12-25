#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat b(6, "Juan");
	// PresidentialPardonForm form("contract");
	
	// std::cout << "---------------------------------------" << std::endl;
	// std::cout << form;
	// std::cout << "---------------------------------------" << std::endl;
	
	// try {

	// 	b.signForm(form);

	// 	b.executeForm(form);

	// 	b.incrementGrade();

	// 	b.executeForm(form);

	// 	for (int i = 0; i < 5; i++) {
	// 		b.incrementGrade();
	// 	}
	// 	// std::cout << "---------------------------------------" << std::endl;
	// 	// std::cout << form;
	// 	// std::cout << "---------------------------------------" << std::endl;
	// }
	// catch (std::exception& e) {
	// 	std::cout << e.what() << std::endl;
	// }
	// std::cout << "---------------------------------------" << std::endl;
	// std::cout << form;
	// std::cout << "---------------------------------------" << std::endl;

	ShrubberyCreationForm f("target");
	b.signForm(f);
	b.executeForm(f);
}
