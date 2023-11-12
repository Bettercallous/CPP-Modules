#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>

class Contacts {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string darkest_secret;
		std::string	phone_number;
	public:
		Contacts(std::string first, std::string last, std::string nick,
			std::string secret, std::string num);
		void PrintContacts();
};

#endif