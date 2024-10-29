/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:03:27 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 16:59:41 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource() : _type("Unamed") {
	std::cout << GREEN << "Default constructor MateriaSource" << DEF << std::endl;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << GREEN << "Copy constructor MateriaSource" << DEF << std::endl;
	*this = other;
}

// Destructor
MateriaSource::~MateriaSource() {
	std::cout << GREEN << "Destructor MateriaSource" << DEF << std::endl;
}

// Copy assignement operator
MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << GREEN << "Copy assignement operator MateriaSource" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Functions
void MateriaSource::learnMateria(AMateria *materia) {
	if (materia == NULL)
		return ;
	for (int i = 0; i < 4; i++) {
		if (_materia[i] == NULL) {
			_materia[i] = materia;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (_materia[i] != NULL && _materia[i]->getType() == type) {
		    AMateria *materia = _materia[i]->clone();
			return materia;
		}
	}
	return 0;
}
