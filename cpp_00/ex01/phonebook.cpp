#include "phonebook.hpp"

PhoneBook::PhoneBook() : index(0) {}

void PhoneBook::AddContact(Contacts contact) {
    if (index < 8) {
        contacts[index] = contact;
        index++;
        std::cout << "Contact added successfully!\n";
    } else {
        std::cout << "PhoneBook is full. Cannot add more contacts.\n";
    }
}
