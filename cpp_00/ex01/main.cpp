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
			while (!CheckNumber(num))
			{
				std::cout << "Please enter a valid phone number : ";
				getline(std::cin, num);
			}
			std::cout << "Enter your darkest secret : ";
			getline(std::cin, secret);
			while (!CheckName(secret))
			{
				std::cout << "Please enter a valid secret : ";
				getline(std::cin, secret);
			}
			Contacts contact = Contacts(first, last, nick, secret, num);
			phonebook.AddContact(contact);
		}
		else if (!input.compare("SEARCH"))
		{
			std::cout << std::setw(10) << "Index" << "| "
					  << std::setw(10) << "First Name" << "| "
			          << std::setw(10) << "Last Name" << "| " 
					  << std::setw(10) << "Nickname" << "| " << std::endl;
			for (int i = 0; i < phonebook.GetIndex(); ++i) {
			    Contacts contact = phonebook.getContact(i);
			    std::cout << std::setw(10) << i + 1 << " | ";
			    std::cout << std::setw(10) << (contact.GetFirstName().length() > 10 ? contact.GetFirstName().substr(0, 9) + "." : contact.GetFirstName()) << " | ";
			    std::cout << std::setw(10) << (contact.GetLastName().length() > 10 ? contact.GetLastName().substr(0, 9) + "." : contact.GetLastName()) << " | ";
			    std::cout << std::setw(10) << (contact.GetNickname().length() > 10 ? contact.GetNickname().substr(0, 9) + "." : contact.GetNickname()) << " | ";
			    std::cout << std::endl;
			}
			std::cout << "Enter the index of the contact to display: ";
			std::string input;
			getline(std::cin, input);
			const char *indexStr = input.c_str();
			int	indexToDisplay = std::atoi(indexStr);
			if (indexToDisplay > 0 && indexToDisplay <= 8)
			{
				Contacts selectedContact = phonebook.getContact(indexToDisplay - 1);
				std::cout << "Index: " << indexToDisplay - 1 << std::endl;
				std::cout << "First Name: " << selectedContact.GetFirstName() << std::endl;
				std::cout << "Last Name: " << selectedContact.GetLastName() << std::endl;
				std::cout << "Nickname: " << selectedContact.GetNickname() << std::endl;
				std::cout << "Darkest Secret: " << selectedContact.GetSecret() << std::endl;
				std::cout << "Phone Number: " << selectedContact.GetPhoneNum() << std::endl;
			}
			else
			{
				std::cout << "Invalid index. Please enter a valid index." << std::endl;
			}
		}
	}
}