#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	count = 0;
}

void PhoneBook::saveContact(Contacts contact) {
	if (count < 8) {
		contacts[count] = contact;
		count++;
		std::cout << ">>> Contact added successfully! <<<" << std::endl;
	} else {
		for (int i = 0; i < 7; ++i) {
			contacts[i] = contacts[i + 1];
		}
		contacts[7] = contact;
		std::cout << ">>> Contact added successfully! <<<" << std::endl;
	}
}

Contacts PhoneBook::getContact(int index) {
	return contacts[index];
}

int	PhoneBook::getCount() {
	return count;
}

void	PhoneBook::displayAllContacts()
{
	std::cout << std::setw(10) << "Index" << " | "
			  << std::setw(10) << "First Name" << " | "
			  << std::setw(10) << "Last Name" << " | " 
			  << std::setw(10) << "Nickname" << " | " << std::endl;

	Contacts contact;
	for (int i = 0; i < getCount(); ++i) {
		contact = getContact(i);
		std::cout << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << (contact.getFirstName().length() > 10 ?
			contact.getFirstName().substr(0, 9) + "." : contact.getFirstName()) << " | ";
		std::cout << std::setw(10) << (contact.getLastName().length() > 10 ?
			contact.getLastName().substr(0, 9) + "." : contact.getLastName()) << " | ";
		std::cout << std::setw(10) << (contact.getNickname().length() > 10 ?
			contact.getNickname().substr(0, 9) + "." : contact.getNickname()) << " | ";
		std::cout << std::endl;
	}
}

void	PhoneBook::displayContactInfo()
{
	std::cout << "Enter the index of the contact to display: ";
	std::string input;
	getline(std::cin, input);

	if (std::cin.eof()) {
		std::cout << std::endl;
		exit(0);
	}
	for (int i = 0; input[i]; i++)	{
		if (!isdigit(input[i])) {
			std::cout << "Invalid index. Please enter a valid index." << std::endl;
			return;
		}
	}
	const char *indexStr = input.c_str();
	int indexToDisplay = std::atoi(indexStr);
	if (indexToDisplay > getCount() && indexToDisplay <= 8) {
		std::cout << "No current contact with the given index." << std::endl;
	} else if (indexToDisplay > 0 && indexToDisplay <= 8) {
		Contacts selectedContact = getContact(indexToDisplay - 1);
		std::cout << "- Index: " << indexToDisplay << std::endl;
		std::cout << "- First Name: " << selectedContact.getFirstName() << std::endl;
		std::cout << "- Last Name: " << selectedContact.getLastName() << std::endl;
		std::cout << "- Nickname: " << selectedContact.getNickname() << std::endl;
		std::cout << "- Darkest Secret: " << selectedContact.getSecret() << std::endl;
		std::cout << "- Phone Number: " << selectedContact.getPhoneNum() << std::endl;
	} else {
		std::cout << "Invalid index. Returning to main page.." << std::endl;
	}
}

void	PhoneBook::addContact()
{
	std::string prompts[] = {"first name", "last name", "Nickname", "darkest secret"};
	std::string values[5];

	for (int i = 0; i < 4; ++i) {
		std::cout << "* Enter your " << prompts[i] << " : ";
		getline(std::cin, values[i]);
		
		if (std::cin.eof()) {
			std::cout << std::endl;
			exit(0);
		}

		while (!checkName(values[i])) {
			std::cout << "Please enter a valid " << prompts[i] << " : ";
			getline(std::cin, values[i]);
			
			if (std::cin.eof()) {
				std::cout << std::endl;
				exit(0);
			}
		}
	}
		std::cout << "* Enter your phone number : ";
		getline(std::cin, values[4]);
		
		if (std::cin.eof()) {
			std::cout << std::endl;
			exit(0);
		}

		while (!checkNumber(values[4])) {
			std::cout << "Please enter a valid phone number : ";
			getline(std::cin, values[4]);
			
			if (std::cin.eof()) {
				std::cout << std::endl;
				exit(0);
			}
		}

	Contacts contact = Contacts(values[0], values[1], values[2], values[3], values[4]);
	saveContact(contact);
}
