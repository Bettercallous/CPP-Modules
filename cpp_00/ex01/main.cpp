#include "PhoneBook.hpp"

int main(void) {
	std::string input;
	PhoneBook phonebook;

	while (1) {
		std::cout << "** Enter one of the commands : ADD | SEARCH | EXIT **\n> ";
		getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << std::endl;
			return (0);
		}
		if (!input.compare("EXIT")) {
			std::cout << "Exiting...\n";
			return (0);
		} else if (!input.compare("ADD")) {
			phonebook.addContact();
		} else if (!input.compare("SEARCH")) {
			phonebook.displayAllContacts();
			phonebook.displayContactInfo();
		}
	}
}
