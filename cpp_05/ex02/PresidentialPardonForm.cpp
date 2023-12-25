#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("Unnamed") {
	// std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target) {
	// std::cout << "PresidentialPardonForm parametrized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	AForm::operator=(other);
	// std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getSignature() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}