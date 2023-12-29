#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	{
	    Intern intern;
	    Bureaucrat Juan(5, "Juan");
	    std::cout << Juan << std::endl;

	    AForm   *rrf = intern.makeForm("presidential pardon", "president");
	    Juan.signForm(*rrf);
	    Juan.executeForm(*rrf);
	    delete rrf;
	}

	{
	    Intern intern;
	    Bureaucrat Juan(5, "Juan");
	    std::cout << Juan << std::endl;

	    AForm   *rrf = intern.makeForm("shrubbery creation", "home");
	    Juan.signForm(*rrf);
	    Juan.executeForm(*rrf);
	    delete rrf;
	}

	{
	    Intern intern;
	    Bureaucrat Juan(5, "Juan");
	    std::cout << Juan << std::endl;

	    AForm   *rrf = intern.makeForm("robotomy request", "Bender");
	    Juan.signForm(*rrf);
	    Juan.executeForm(*rrf);
	    delete rrf;
	}

	// fail case
	{
		Intern intern;
		Bureaucrat Juan(5, "Juan");
		std::cout << Juan << std::endl;

		AForm   *rrf = intern.makeForm("unexisting form", "target");
		delete rrf;
	}
	// system("leaks Intern");
	return 0;
}
