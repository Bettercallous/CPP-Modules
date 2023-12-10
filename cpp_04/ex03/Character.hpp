#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria *materias[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character & other);
		Character& operator=(const Character & other);
		~Character();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

};

#endif