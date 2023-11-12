#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contacts.hpp"

class PhoneBook {
	private:
		Contacts contacts[8];
	public:
		PhoneBook();
};

#endif