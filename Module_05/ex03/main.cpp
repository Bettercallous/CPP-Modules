#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	{
		// executing presidential pardon
		try {
	    	Intern intern;
	    	Bureaucrat Juan(5, "Juan");
	    	std::cout << Juan;

	    	AForm *rrf = intern.makeForm("presidential pardon", "president");
	    	Juan.signForm(*rrf);
	    	Juan.executeForm(*rrf);
	    	delete rrf;
		}
		catch (std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		// executing shrubbery creation
		try {
	    	Intern intern;
	    	Bureaucrat Juan(5, "Juan");
	    	std::cout << Juan;

	    	AForm *rrf = intern.makeForm("shrubbery creation", "home");
	    	Juan.signForm(*rrf);
	    	Juan.executeForm(*rrf);
	    	delete rrf;
		}
		catch (std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		// executing robotomy request
		try {
	    	Intern intern;
	    	Bureaucrat Juan(5, "Juan");
	    	std::cout << Juan;

	    	AForm *rrf = intern.makeForm("robotomy request", "Bender");
	    	Juan.signForm(*rrf);
	    	Juan.executeForm(*rrf);
	    	delete rrf;
		}
		catch (std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	{
		// fail case
		try {
			Intern intern;
			Bureaucrat Juan(5, "Juan");
			std::cout << Juan;

			AForm *rrf = intern.makeForm("unexisting form", "target");
	    	Juan.signForm(*rrf);
	    	Juan.executeForm(*rrf);
			delete rrf;
		}
		catch (std::exception& e) {
			std::cerr << "Caught exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}
