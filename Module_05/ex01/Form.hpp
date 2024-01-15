#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
	public:

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		Form();
		Form(std::string name, const int signGrade, const int execGrade);
		Form(const Form & other);
		Form& operator=(const Form & other);
		~Form();

		int getSignGrade() const;
		int getExecGrade() const;
		const std::string getName() const;
		bool getSignature() const;

		void beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif