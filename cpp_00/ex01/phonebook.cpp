#include "phonebook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::AddContact(Contacts contact) {
	if (index < 8) {
		contacts[index] = contact;
		index++;
		std::cout << "Contact added successfully!\n";
	} else {
		for (int i = 0; i < 7; ++i) {
			contacts[i] = contacts[i + 1];
		}
		contacts[7] = contact;
		std::cout << "Contact added successfully!\n";
	}
}

Contacts PhoneBook::getContact(int index) {
	return contacts[index];
}

int	PhoneBook::GetIndex() {
	return index;
}
