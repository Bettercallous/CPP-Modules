#include "SearchAndReplace.hpp"

int main() {
	std::string filename, s1, s2;
	std::cout << "Enter the file name: ";
	getline(std::cin, filename);
	inputCheck(filename);
	std::cout << "Enter the string you want to replace: ";
	getline(std::cin, s1);
	inputCheck(s1);
	std::cout << "Enter the replacement string: ";
	getline(std::cin, s2);
	inputCheck(s2);

	replaceOccurrence(filename, s1, s2);

	return 0;
}
