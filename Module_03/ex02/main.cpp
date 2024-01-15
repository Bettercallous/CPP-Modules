#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap t("alaoui");
    FragTrap t2(t);
    FragTrap t3 = t2;

    ScavTrap a("aaaa");
    ScavTrap b(a);

    a.printStats();
    b.printStats();
    t3.attack("alaoui 2");
    t3.printStats();

    t3.takeDamage(2);
    t3.beRepaired(1);
    t3.printStats();
    t3.highFivesGuys();
    t3.highFivesGuys();
}