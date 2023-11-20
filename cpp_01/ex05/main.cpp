#include "Harl.hpp"

int main()
{
	Harl harl;
	std::string level;
	std::cout << "Enter level: ";
	getline(std::cin, level);
	harl.complain(level);
	return 0;
}