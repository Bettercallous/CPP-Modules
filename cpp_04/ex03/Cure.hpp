#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	protected:
		std::string type;
	public:
		Cure();
		Cure(std::string const& type);
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		std::string const& getType() const;
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif