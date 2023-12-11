#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	protected:
		std::string type;
	public:
		Ice();
		Ice(std::string const& type);
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();

		// std::string const& getType() const;
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif