#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <iomanip>

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
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetNickname();
		std::string GetSecret();
		std::string GetPhoneNum();
};

int	CheckNumber(std::string number);
int	CheckName(std::string name);

#endif