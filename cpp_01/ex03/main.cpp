#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
/*
	The setWeapon function currently creates a new Weapon object dynamically
	using new, which means weapon inside HumanB is a pointer to a dynamically allocated Weapon object.
	However, when you call setType on the original club object outside the HumanB class,
	you're modifying the original Weapon object, not the one pointed to by weapon inside HumanB.
	Therefore, the change made to club doesn't affect the weapon object held by HumanB.
*/