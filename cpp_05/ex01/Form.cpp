#include "Form.hpp"

class Form::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return ("Error: grade too high.");
		}
};

class Form::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return ("Error: grade too low.");
		}
};

Form::Form() : _name("Unnamed"), _isSigned(false), _signGrade(150), _execGrade(150) {
	// std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, const int signGrade, const int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	// std::cout << "Form parametrized constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1) {
		throw GradeTooHighException();
	}
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form & other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	// std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form & other) {
	// std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {
	// std::cout << "Form destructor called" << std::endl;
}

const int Form::getSignGrade() const {
	return _signGrade;
}

const int Form::getExecGrade() const {
	return _execGrade;
}

const std::string Form::getName() const {
	return _name;
}

bool Form::getSignature() const {
	return _isSigned;
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
	out << "Form name: " << f.getName() << std::endl;
	out << "Form is signed: " << f.getSignature() << std::endl;
	out << "Required grade to sign it: " << f.getSignGrade() << std::endl;
	out << "Required grade to execute it: " << f.getExecGrade() << std::endl;
	return out;
}

void Form::beSigned(Bureaucrat& b) {

}
