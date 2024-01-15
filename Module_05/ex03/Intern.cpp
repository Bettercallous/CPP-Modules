#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	// std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern & other) {
	// std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern & other) {
	// std::cout << "Intern copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern() {
	// std::cout << "Intern destructor called" << std::endl;
}

AForm* createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target) {

	std::string fnames[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation",
	};

	AForm* (*forms[])(const std::string&) = {
		&createPresidentialPardonForm,
		&createRobotomyRequestForm,
		&createShrubberyCreationForm
	};

	for (int i = 0; i < 3; ++i) {
		if (name == fnames[i]) {
			std::cout << "Intern creates " << fnames[i] << std::endl;
			return forms[i](target);
		}
	}

	std::cerr << "Intern cannot create " << name << std::endl;
	throw FormDoesNotExistException();
}

const char* Intern::FormDoesNotExistException::what() const throw() {
	return ("Form not found.");
}