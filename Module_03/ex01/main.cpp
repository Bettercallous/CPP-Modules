#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap t("alaoui");
    ScavTrap t2(t);
    ScavTrap t3 = t2;

    t3.printStats();
    t3.attack("alaoui 2");
    t3.printStats();

    t3.takeDamage(2);
    t3.beRepaired(1);
    t3.printStats();
    t3.guardGate();
    t2.guardGate();
}