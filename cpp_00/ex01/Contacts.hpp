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
		Contacts();
		Contacts(std::string first, std::string last, std::string nick,
			std::string secret, std::string num);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getSecret();
		std::string getPhoneNum();
};

int	checkNumber(std::string number);
int	checkName(std::string name);

#endif