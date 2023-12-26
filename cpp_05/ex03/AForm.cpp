#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unnamed"), _isSigned(false), _signGrade(150), _execGrade(150) {
	// std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, const int signGrade, const int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	// std::cout << "AForm parametrized constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1) {
		throw GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm & other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	// std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm & other) {
	// std::cout << "AForm copy assignment operator called" << std::endl;
	_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {
	// std::cout << "AForm destructor called" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("grade is too low.");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("form is not signed.");
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

const std::string AForm::getName() const {
	return _name;
}

bool AForm::getSignature() const {
	return _isSigned;
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
	out << "Form name:                    " << f.getName() << std::endl;
	out << "Form is signed:               " << f.getSignature() << std::endl;
	out << "Required grade to sign it:    " << f.getSignGrade() << std::endl;
	out << "Required grade to execute it: " << f.getExecGrade() << std::endl;
	return out;
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	this->_isSigned = true;
}
