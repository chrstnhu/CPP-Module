/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:03:27 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/08 12:26:25 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource() : _type("Unamed") {
	for (int i = 0; i < MAX_MATERIA; i++) {
		_inventory[i] = NULL;
	}

}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (other._inventory[i] != NULL) {
			_inventory[i] = other._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}

// Destructor
MateriaSource::~MateriaSource() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
		}
	}
}

// Copy assignement operator
MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i= 0; i < MAX_MATERIA; i++) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		_type = other._type;
		for (int i = 0; i < MAX_MATERIA; i++) {
			if (other._inventory[i] != NULL) {
				_inventory[i] = other._inventory[i]->clone();
			}
			else {
				_inventory[i] = NULL;
			}
		}
	}
	return *this;
}

// Functions
void MateriaSource::learnMateria(AMateria *m) {
	if (m == NULL)
		return ;
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_inventory[i] == NULL) {
			printTwoBlocs("Learning: ", m->getType(), " on slot: ", i, GREEN);
			_inventory[i] = m;
			return;
		}
	}
	printOneBloc(RED"Inventory is full, cannot learn more Materia than ", MAX_MATERIA, RED);
	delete m ;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_inventory[i] != NULL && _inventory[i]->getType() == type) {
			printTwoBlocs("Creating: ", _inventory[i]->getType(), " on slot: ", i, GREEN);
			return _inventory[i]->clone();
		}
	}
	printColor("Cannot create " + type + " because it is not a valid Materia", RED);
	return NULL;
}
