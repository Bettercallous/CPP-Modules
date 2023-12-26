#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
    Bureaucrat Juan(5, "Juan");
    std::cout << Juan << std::endl ;

    AForm   *rrf = intern.makeForm("presidential pardon", "Juan") ;
    Juan.signForm(*rrf) ;
    Juan.executeForm(*rrf) ;
    delete rrf;
}
