#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	// ScavTrap a;
    FragTrap b("alaoui2");
	// a.attack("alaoui2");
	// a.attack("alaoui2");
	// a.takeDamage(2);
	// a.beRepaired(1);
    // b.attack("alaoui");
    // b.attack("alaoui");
    // b.takeDamage(1);
    // b.beRepaired(1);
    for (int i = 0; i < 5; ++i)
    {
	    // a.attack("alaoui2");
        b.attack("alaoui");
    }
    b.highFivesGuys();
}