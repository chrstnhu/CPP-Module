/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:20:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/30 16:47:44 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default constructor
Character::Character() : _name("unamed") {
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

// Constructor with parameters
Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < MAX_MATERIA; i++)
		_inventory[i] = NULL;
}

// Copy constructor
Character::Character(Character const &other) {
	delete[] this->_name.c_str();
	*this = other;
}

// Destructor
Character::~Character() {
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

// Copy assignement
Character &Character::operator=(Character const &other) {
	if (this != &other) {
		delete[] this->_name.c_str();
		this->_name = other._name;
	}
	return *this;
}

// Getter
std::string const &Character::getName() const {
	return this->_name;
}

// Function
void Character::equip(AMateria *m) {
    if (!m) {
		std::cout << RED << "Can't equip anything"<< DEF << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_MATERIA; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			std::cout << "Equip " << m->getType() << " to slot " << i << std::endl;
			return ;
		}
	}
	std::cout << RED << "Inventory is full, cannot learn more Materia!" << DEF << std::endl;
	delete m;
}

void Character::unequip(int idx) {
	if (_inventory[idx] == NULL) {
		std::cout << RED << "Can't unequip a empty slot " << DEF << std::endl;
		return ;
	}
	else if (idx < 4) {
		std::cout << "Unequip " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target) {
	AMateria *m = _inventory[idx];
	if (m == NULL) {
		std::cout << RED << "Can't use a empty Materia " << DEF << std::endl;
		return ;
	}
	else {
		std::cout << "Using materia on : " << target.getName() << std::endl;  
		m->use(target);
		return ;
	}
}