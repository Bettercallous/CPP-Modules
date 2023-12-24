#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return ("grade is too high.");
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return ("grade is too low.");
				}
		};

		AForm();
		AForm(std::string name, const int signGrade, const int execGrade);
		AForm(const AForm & other);
		AForm& operator=(const AForm & other);
		virtual ~AForm();

		int getSignGrade() const;
		int getExecGrade() const;
		const std::string getName() const;
		bool getSignature() const;

		void beSigned(Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif