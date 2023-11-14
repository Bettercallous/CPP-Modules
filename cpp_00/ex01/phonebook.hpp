#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

class PhoneBook {
	private:
		Contacts contacts[8];
		int	index;
	public:
		PhoneBook();
		void saveContact(Contacts contact);
		Contacts getContact(int index);
		int	GetIndex();
		void addContact();
		void displayAllContacts();
		void displayContactInfo();
};

#endif