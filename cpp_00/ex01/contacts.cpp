#include "contacts.hpp"

Contacts::Contacts(std::string first, std::string last, std::string nick, std::string secret, std::string num)
{
    this->FirstName = first;
    this->LastName = last;
    this->Nickname = nick;
    this->DarkestSecret = secret;
    this->PhoneNumber = num;
}
