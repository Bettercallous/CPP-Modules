#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>

class Contacts {
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string	Nickname;
		std::string DarkestSecret;
		std::string	PhoneNumber;
	public:
		Contacts() {};
		Contacts(std::string first, std::string last, std::string nick,
			std::string secret, std::string num);
};

#endif