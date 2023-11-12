#include "contacts.hpp"

Contacts::Contacts(std::string first, std::string last, std::string nick, std::string secret, std::string num)
{
    this->first_name = first;
    this->last_name = last;
    this->nickname = nick;
    this->darkest_secret = secret;
    this->phone_number = num;
}

void    Contacts::PrintContacts()
{
    std::cout << "first name     : " << first_name << "\n";
    std::cout << "last name      : " << last_name << "\n";
    std::cout << "nickname       : " << nickname << "\n";
    std::cout << "darkest secret : " << darkest_secret << "\n";
    std::cout << "phone number   : " << phone_number << "\n";
}