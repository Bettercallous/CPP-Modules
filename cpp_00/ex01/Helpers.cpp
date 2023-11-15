#include "PhoneBook.hpp"

int	checkName(std::string name)
{
	int	i = 0;
	if (name.empty())
		return (0);
	while (name[i]) {
		if (!isalpha(name[i]) && name[i] != ' ' && name[i] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (name[i]) {
		if (name[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	checkName2(std::string name)
{
	int i = 0;
	if (name.empty())
		return (0);
	while (name[i] && isprint(name[i])) {
		if (name[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	checkNumber(std::string number)
{
	int	i = 0;
	if (number.empty())
		return (0);
	while (number[i]) {
		if (!isdigit(number[i]))
			return (0);
		i++;
	}
	if (number.length() > 15 || number.length() < 7)
		return (0);
	return (1);
}
