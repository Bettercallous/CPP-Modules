#include "phonebook.hpp"

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
			return  0;
		} else if (!input.compare("ADD")) {
			std::string prompts[] = {"first name", "last name", "Nickname", "darkest secret"};
			std::string values[5];

			for (int i = 0; i < 4; ++i) {
				std::cout << "Enter your " << prompts[i] << " : ";
				getline(std::cin, values[i]);
				
				if (std::cin.eof()) {
					std::cout << std::endl;
					return (0);
				}

				while (!CheckName(values[i])) {
					std::cout << "Please enter a valid " << prompts[i] << " : ";
					getline(std::cin, values[i]);
					
					if (std::cin.eof()) {
						std::cout << std::endl;
						return (0);
					}
				}
			}
				std::cout << "Enter your phone number : ";
				getline(std::cin, values[4]);
				
				if (std::cin.eof()) {
					std::cout << std::endl;
					return (0);
				}

				while (!CheckNumber(values[4])) {
					std::cout << "Please enter a valid phone number : ";
					getline(std::cin, values[4]);
					
					if (std::cin.eof()) {
						std::cout << std::endl;
						return (0);
					}
				}

			Contacts contact = Contacts(values[0], values[1], values[2], values[3], values[4]);
			phonebook.AddContact(contact);
		} else if (!input.compare("SEARCH")) {
			std::cout << std::setw(10) << "Index" << " | "
					  << std::setw(10) << "First Name" << " | "
					  << std::setw(10) << "Last Name" << " | " 
					  << std::setw(10) << "Nickname" << " | " << std::endl;

			for (int i = 0; i < phonebook.GetIndex(); ++i) {
				Contacts contact = phonebook.getContact(i);
				std::cout << std::setw(10) << i + 1 << " | ";
				std::cout << std::setw(10) << (contact.GetFirstName().length() > 10 ?
					contact.GetFirstName().substr(0, 9) + "." : contact.GetFirstName()) << " | ";
				std::cout << std::setw(10) << (contact.GetLastName().length() > 10 ?
					contact.GetLastName().substr(0, 9) + "." : contact.GetLastName()) << " | ";
				std::cout << std::setw(10) << (contact.GetNickname().length() > 10 ?
					contact.GetNickname().substr(0, 9) + "." : contact.GetNickname()) << " | ";
				std::cout << std::endl;
			}

			std::cout << "Enter the index of the contact to display: ";
			std::string input;
			getline(std::cin, input);

			if (std::cin.eof()) {
				std::cout << std::endl;
				return (0);
			}

			const char *indexStr = input.c_str();
			int indexToDisplay = std::atoi(indexStr);
			if (indexToDisplay > phonebook.GetIndex() && indexToDisplay <= 8) {
				std::cout << "No current contact with the given index." << std::endl;
			} else if (indexToDisplay > 0 && indexToDisplay <= 8) {
				Contacts selectedContact = phonebook.getContact(indexToDisplay - 1);
				std::cout << "- Index: " << indexToDisplay << std::endl;
				std::cout << "- First Name: " << selectedContact.GetFirstName() << std::endl;
				std::cout << "- Last Name: " << selectedContact.GetLastName() << std::endl;
				std::cout << "- Nickname: " << selectedContact.GetNickname() << std::endl;
				std::cout << "- Darkest Secret: " << selectedContact.GetSecret() << std::endl;
				std::cout << "- Phone Number: " << selectedContact.GetPhoneNum() << std::endl;
			} else {
				std::cout << "Invalid index. Please enter a valid index." << std::endl;
			}
		}
	}
}
