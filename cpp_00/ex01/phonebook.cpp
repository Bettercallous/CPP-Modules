#include "phonebook.hpp"

int	main(void)
{
    std::string first, last, nick, secret, num;
    std::cout << "Enter your first name :\n";
	getline(std::cin, first);
    std::cout << "Enter your last name :\n";
    getline(std::cin, last);
    std::cout << "Enter your nickname :\n";
    getline(std::cin, nick);
    std::cout << "Enter your darkest secret :\n";
    getline(std::cin, secret);
    std::cout << "Enter your phone number :\n";
    getline(std::cin, num);

    Contacts contacts = Contacts(first, last, nick, secret, num);
    contacts.PrintContacts();
}