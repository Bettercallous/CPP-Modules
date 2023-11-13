#include "phonebook.hpp"

int	CheckName(std::string name)
{
	int	i = 0;
	if (name.empty())
		return (0);
	while (name[i]) {
		if (!isalpha(name[i]) && name[i] != ' ' && name[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int	CheckNumber(std::string number)
{
	int	i = 0;
	if (number.empty())
		return (0);
	while (number[i]) {
		if (!isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int	i = 0;
	std::string input, first, last, nick, secret, num;
	PhoneBook phonebook;
	while (1)
	{
		std::cout << "Enter a command : \n> ";
		getline(std::cin, input);
		if (!input.compare("EXIT")) {
			std::cout << "Exiting...\n";
			exit(0);
		}
		else if (!input.compare("ADD"))
		{
			std::cout << "Enter your first name : ";
			getline(std::cin, first);
			while (!CheckName(first))
			{
				std::cout << "Please enter a valid name : ";
				getline(std::cin, first);
			}
			std::cout << "Enter your last name : ";
			getline(std::cin, last);
			while (!CheckName(last))
			{
				std::cout << "Please enter a valid name : ";
				getline(std::cin, last);
			}
			std::cout << "Enter your Nickname : ";
			getline(std::cin, nick);
			while (!CheckName(nick))
			{
				std::cout << "Please enter a valid name : ";
				getline(std::cin, nick);
			}
			std::cout << "Enter your phone number : ";
			getline(std::cin, num);
			if (!CheckNumber(num))
			{
				std::cout << "Please enter a valid phone number : ";
				getline(std::cin, num);
			}
			std::cout << "Enter your darkest secret : ";
			getline(std::cin, secret);
			if (!CheckName(secret))
			{
				std::cout << "Please enter a valid secret : ";
				getline(std::cin, secret);
			}
			Contacts Contacts(first, last, nick, secret, num);
			phonebook.AddContact(Contacts);
		}
		else if (!input.compare("SEARCH"))
		{
			////
		}
	}

	// contacts.PrintContacts();
}