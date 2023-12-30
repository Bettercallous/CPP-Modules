#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45), _target("Unnamed") {
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45), _target(target) {
	// std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
	// std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	AForm::operator=(other);
	// std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getSignature() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();

	std::cout << "*...Drilling noises...*" << std::endl;

	std::srand(std::time(0));

	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy of " << _target << " has failed." << std::endl;
}