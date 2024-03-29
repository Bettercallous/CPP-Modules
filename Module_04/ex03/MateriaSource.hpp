#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_materials[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource & other);
		MateriaSource& operator=(const MateriaSource & other);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif