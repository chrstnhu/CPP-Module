/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:20:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/12 13:37:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

// Default constructor
Character::Character() : _name("unamed") {
	for (int i = 0; i < MAX_MATERIA; i++) {
		_inventory[i] = NULL;
	}
}

// Constructor with parameters
Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < MAX_MATERIA; i++) {
		_inventory[i] = NULL;
	}
}

// Copy constructor
Character::Character(Character const &other) {
	this->_name = other._name;
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (other._inventory[i] != NULL) {
			_inventory[i] = other._inventory[i]->clone();
		}
		else {
			_inventory[i] = NULL;
		}
	}
}

// Destructor
Character::~Character() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_inventory[i] != NULL) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

// Copy assignement
Character& Character::operator=(Character const &other) {
    if (this != &other) {
        this->_name = other._name;
        // Delete the old inventory
		for (int i = 0; i < MAX_MATERIA; i++) {
            if (this->_inventory[i] != NULL) {
                delete this->_inventory[i];
				this->_inventory[i] = NULL;
            }
        }
		// Copy the new inventory
        for (int i = 0; i < MAX_MATERIA; i++) {
            if (other._inventory[i] != NULL) {
                this->_inventory[i] = other._inventory[i]->clone();
            } else {
                this->_inventory[i] = NULL;
            }
        }
    }
    return *this;
}

// Getter
std::string const &Character::getName() const {
	return _name;
}

// Functions
// Equip the materia to the inventory
void Character::equip(AMateria *m) {
    if (!m) {
		std::cout << RED << "Need to create Materia before equip" << DEF << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			printTwoBlocs("Equip '", m->getType(), "' to inventory ", i, GREEN);
			return ;
		}
	}
	printColor("Inventory is full, cannot learn more Materia!", RED);
}

// Unequip the materia from the inventory
void Character::unequip(int idx) {
	if (idx >= 0 && idx < MAX_MATERIA && _inventory[idx] != NULL) {
		printTwoBlocs("Unequip '", _inventory[idx]->getType(), "' from slot ", idx, GREEN);
		_inventory[idx] = NULL;
	}
	else {
		printColor("Invalid slot or empty slot", RED);
	}
}

// Use the materia from the inventory
void Character::use(int idx, ICharacter &target) {
	if (idx <= 0 || idx >= MAX_MATERIA)
		return ;
	AMateria *m = _inventory[idx];
	if (m == NULL) {
		printOneBloc(RED "Can't use a empty inventory slot ", idx, RED);
	}
	else {
		printTwoBlocs("Using " + m->getType() + " on: '", target.getName(), "' from slot ", idx, GREEN);
		m->use(target);
	}
}

// Return the pointer adress of materia
AMateria *Character::getMateria(int idx) const {
	if (idx >= 0 && idx < MAX_MATERIA) {
		return _inventory[idx];
	}
	return NULL;
}