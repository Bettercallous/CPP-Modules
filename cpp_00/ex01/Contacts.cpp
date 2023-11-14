#include "Contacts.hpp"

Contacts::Contacts() {};

Contacts::Contacts(std::string first, std::string last, std::string nick, std::string secret, std::string num)
{
	FirstName = first;
	LastName = last;
	Nickname = nick;
	DarkestSecret = secret;
	PhoneNumber = num;
}

std::string Contacts::getFirstName() {
	return FirstName;
}

std::string Contacts::getLastName() {
	return LastName;
}

std::string Contacts::getNickname() {
	return Nickname;
}

std::string Contacts::getSecret() {
	return DarkestSecret;
}

std::string Contacts::getPhoneNum() {
	return PhoneNumber;
}
