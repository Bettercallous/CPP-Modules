#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
	private:
		const std::string _name;
		int	_grade;
	public:

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(int grade, std::string name);
		Bureaucrat(const Bureaucrat & other);
		Bureaucrat& operator=(const Bureaucrat & other);
		~Bureaucrat();

		int	getGrade() const;
		const std::string getName() const;

		void incrementGrade();
		void decrementGrade();

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif