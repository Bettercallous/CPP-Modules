#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string level;
	std::cout << "Enter level: ";
	getline(std::cin, level);
	harl.complain(level);
	// tests //
	std::cout << "------- Testing -------" << std::endl;
	std::cout << "DEBUG level: " << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO level: " << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING level: " << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR level: " << std::endl;
	harl.complain("ERROR");
	std::cout << "------------------------" << std::endl;
	return 0;
}