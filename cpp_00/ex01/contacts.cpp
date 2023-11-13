#include "contacts.hpp"

Contacts::Contacts(std::string first, std::string last, std::string nick, std::string secret, std::string num)
{
    this->FirstName = first;
    this->LastName = last;
    this->Nickname = nick;
    this->DarkestSecret = secret;
    this->PhoneNumber = num;
}

std::string Contacts::GetFirstName()
{
    return this->FirstName;
}

std::string Contacts::GetLastName()
{
    return this->LastName;
}

std::string Contacts::GetNickname()
{
    return this->Nickname;
}

std::string Contacts::GetSecret()
{
    return this->DarkestSecret;
}

std::string Contacts::GetPhoneNum()
{
    return this->PhoneNumber;
}
