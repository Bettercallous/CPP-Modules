#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
	public:
		class GradeTooHighException;
		class GradeTooLowException;

		Form();
		Form(std::string name, const int signGrade, const int execGrade);
		Form(const Form & other);
		Form& operator=(const Form & other);
		~Form();

		const int getSignGrade() const;
		const int getExecGrade() const;
		const std::string getName() const;
		bool getSignature() const;

		void beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif