#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

class PhoneBook {
	private:
		Contacts contacts[8];
		int	count;
	public:
		PhoneBook();
		void saveContact(Contacts contact);
		Contacts getContact(int index);
		int	getCount();
		void addContact();
		void displayAllContacts();
		void displayContactInfo();
};

#endif