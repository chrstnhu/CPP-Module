/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:03:27 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 16:51:41 by chrhu            ###   ########.fr       */
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

}

AMateria *MateriaSource::createMateria(const std::string &type) {

}
