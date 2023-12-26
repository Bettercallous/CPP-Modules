#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
	private:
	    AForm* createPresidentialPardonForm(const std::string& target);
    	AForm* createRobotomyRequestForm(const std::string& target);
    	AForm* createShrubberyCreationForm(const std::string& target);
	public:
		Intern();
		Intern(const Intern & other);
		Intern& operator=(const Intern & other);
		~Intern();

		AForm *makeForm(std::string name, std::string target);
};

#endif