#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contacts.hpp"

class PhoneBook {
	private:
		Contacts contacts[8];
		int	index;
	public:
		PhoneBook();
		void AddContact(Contacts contact);
};

#endif