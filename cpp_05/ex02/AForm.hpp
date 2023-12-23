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
		class GradeTooHighException;
		class GradeTooLowException;

		AForm();
		AForm(std::string name, const int signGrade, const int execGrade);
		AForm(const AForm & other);
		AForm& operator=(const AForm & other);
		~AForm();

		int getSignGrade() const;
		int getExecGrade() const;
		const std::string getName() const;
		bool getSignature() const;

		void beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif