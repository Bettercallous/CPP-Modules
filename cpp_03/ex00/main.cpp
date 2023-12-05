#include "ClapTrap.hpp"

int main()
{
    ClapTrap t("alaoui");
    ClapTrap t2(t);
    ClapTrap t3 = t2;


    t3.attack("alaoui 2");

    t3.takeDamage(2);
    t3.beRepaired(1);
}