#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Error: grade is too high.");
		}
};

class Bureaucrat::GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Error: grade is too low.");
		}
};

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {
	// std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name) {
	// std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & other) : _name(other._name), _grade(other._grade) {
	// std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat & other) {
	// std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	// std::cout << "Bureaucrat destructor called" << std::endl;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

const std::string Bureaucrat::getName() const{
	return _name;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}
