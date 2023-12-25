#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery creation", 145, 137), _target("Unnamed") {
	// std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery creation", 145, 137), _target(target) {
	// std::cout << "ShrubberyCreationForm parametrized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
	// std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	AForm::operator=(other);
	// std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getSignature() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();

	std::string filename = _target + "_shrubbery"; 
	std::ofstream outfile(filename.c_str());

	if (outfile.is_open()) {
		outfile << "                                              .         ;   " << std::endl
		<< "                 .              .              ;%     ;;    " << std::endl
		<< "                   ,           ,                :;%  %;    " << std::endl
		<< "                    :         ;                   :;%;'     .,    " << std::endl
		<< "           ,.        %;     %;            ;        %;'    ,; " << std::endl
		<< "             ;       ;%;  %%;        ,     %;    ;%;    ,%' " << std::endl
		<< "              %;       %;%;      ,  ;       %;  ;%;   ,%;'  " << std::endl
		<< "               ;%;      %;        ;%;        % ;%;  ,%;' " << std::endl
		<< "                `%;.     ;%;     %;'         `;%%;.%;' " << std::endl
		<< "                 `:;%.    ;%%. %@;        %; ;@%;%' " << std::endl
		<< "                    `:%;.  :;bd%;          %;@%;' " << std::endl
		<< "                      `@%:.  :;%.         ;@@%;'    " << std::endl
		<< "                        `@%.  `;@%.      ;@@%;          " << std::endl
		<< "                          `@%%. `@%%    ;@@%;         " << std::endl
		<< "                            ;@%. :@%%  %@@%;        " << std::endl
		<< "                              %@bd%%%bd%%:;      " << std::endl
		<< "                                #@%%%%%:;; " << std::endl
		<< "                                %@@%%%::;                                       ,@@@@@@@," << std::endl
		<< "                                %@@@%(o);  . '                          ,,,.   ,@@@@@@/@@, .oo8888o." << std::endl
		<< "                                %@@@o%;:(.,'                        ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
		<< "                            `.. %@@@o%::;                          ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
		<< "                               `)@@@o%::;                          %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
		<< "                                %@@(o)::;                          %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
		<< "                               .%@@@@%::;                          `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
		<< "                               ;%@@@@%::;.                             |o|        | |         | |" << std::endl
		<< "                              ;%@@@@%%:;;;.                            |.|        | |         | |" << std::endl
		<< "                          ...;%@@@@@%%:;;;;,..                       \\/ ._\\//_/__/  ,\\_//__ \\/.  \\_//__/_ " << std::endl;
		outfile.close();
	}
	else
		std::cout << "Error: cannot open the file " << filename << std::endl;
}