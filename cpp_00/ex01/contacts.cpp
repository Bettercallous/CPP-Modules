#include "contacts.hpp"

Contacts::Contacts(std::string first, std::string last, std::string nick, std::string secret, std::string num)
{
	FirstName = first;
	LastName = last;
	Nickname = nick;
	DarkestSecret = secret;
	PhoneNumber = num;
}

std::string Contacts::GetFirstName() {
	return FirstName;
}

std::string Contacts::GetLastName() {
	return LastName;
}

std::string Contacts::GetNickname() {
	return Nickname;
}

std::string Contacts::GetSecret() {
	return DarkestSecret;
}

std::string Contacts::GetPhoneNum() {
	return PhoneNumber;
}
