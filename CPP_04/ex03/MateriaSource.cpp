/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:03:27 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/30 14:58:32 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource() : _type("Unamed") {
	// std::cout << GREEN << "Default constructor MateriaSource" << DEF << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
	
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) {
	// std::cout << GREEN << "Copy constructor MateriaSource" << DEF << std::endl;
	*this = other;
}

// Destructor
MateriaSource::~MateriaSource() {
	// std::cout << GREEN << "Destructor MateriaSource" << DEF << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

// Copy assignement operator
MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	// std::cout << GREEN << "Copy assignement operator MateriaSource" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Functions
void MateriaSource::learnMateria(AMateria *m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_inventory[i] == NULL) {
			std::cout << "Learned: " << m->getType() << std::endl;
			_inventory[i] = m;
			return;
		}
	}
	std::cout << RED << "Inventory is full, cannot learn more than " << MAX_MATERIA << " Materia!" << DEF << std::endl;
	delete m ;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_inventory[i] != NULL && _inventory[i]->getType() == type) {
			std::cout << "Created: " << _inventory[i]->getType() << " on slot: " << i << std::endl;
		    AMateria *materia = _inventory[i]->clone();
			return materia;
		}
	}
	std::cout << RED << "Cannot create " << type << " because it is not a valid Materia !" << DEF << std::endl;
	return 0;
}
