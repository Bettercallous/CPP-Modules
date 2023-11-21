#include "Sed.hpp"

int main(int ac, char **av) {
	
	if (ac != 4) {
		std::cout << "Invalid Number of arguments" << std::endl;
		return 1;
	}
	std::string filename(av[1]), s1(av[2]), s2(av[3]);
	if (filename.empty()) {
		std::cout << "Error: empty argument" << std::endl;
		return 1;
	}
	replaceOccurrence(filename, s1, s2);
	return 0;
}
