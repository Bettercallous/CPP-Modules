#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void formsNotSignedTest()
{
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "-------------------  Test 1 -------------------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	Bureaucrat b(120, "Juan");
	PresidentialPardonForm pres("president");

	try {
		// attempting to execute a form that hasn't been signed yet
		pres.execute(b);
	}
	catch (std::exception& e) {
		std::cerr << "caught the exception: " << e.what() << std::endl;
	}

	Bureaucrat b2(1, "Joe");

	// attempting to execute the form but the form is not signed yet
	b2.executeForm(pres);
	// this is fine now
	b2.signForm(pres);
	b2.executeForm(pres);
	std::cout << "-----------------------------------------------" << std::endl;
}

void formsActionsTest()
{
	std::cout << "-------------------  Test 2 -------------------" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	Bureaucrat b(1, "Juan");

	ShrubberyCreationForm shrub("target1");
	RobotomyRequestForm rob("target2");
	PresidentialPardonForm pres("target3");

	b.signForm(shrub);
	b.signForm(rob);
	b.signForm(pres);

	std::cout << std::endl;
	b.executeForm(shrub);
	std::cout << std::endl;
	b.executeForm(rob);
	std::cout << std::endl;
	b.executeForm(pres);
	std::cout << "-----------------------------------------------" << std::endl;
}

int main()
{
	formsNotSignedTest();
	formsActionsTest();
}
