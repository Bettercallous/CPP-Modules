#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// ClapTrap a("alaoui");
    ScavTrap b("alaoui2");
	// a.attack("alaoui2");
	// a.attack("alaoui2");
	// a.takeDamage(2);
	// a.beRepaired(1);
    b.attack("alaoui");
    b.takeDamage(1);
    b.beRepaired(1);
    for (int i = 0; i < 5; ++i)
    {
	    // a.attack("alaoui2");
        b.attack("alaoui");
    }
    b.guardGate();
}