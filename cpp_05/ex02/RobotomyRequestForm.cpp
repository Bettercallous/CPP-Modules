#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy request", 72, 45), _target("Unnamed") {
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request", 72, 45), _target(target) {
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
	
	std::srand(std::time(0)); // Seed the random number generator
	// Since std::rand() generates numbers from 0 to RAND_MAX and checks if they're even, it effectively creates a 50% chance for the condition
	// to be true (success) or false (failure). Half of the numbers in that range are even.

	if (std::rand() % 2 == 0) // Robotomization success is determined by a 50% chance
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy of " << _target << " has failed." << std::endl;
}