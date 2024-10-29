/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:20:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 16:49:54 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Default constructor
Character::Character() : _name("unamed") {
	std::cout << GREEN << "Default constructor Character" << DEF << std::endl;
}

// Constructor with parameters
Character::Character(std::string type) : _name(name) {
	std::cout << GREEN << "Constructor with parameters Character" << DEF << std::endl;
}

// Copy constructor
Character::Character(Character const &other) {
	std::cout << GREEN << "Copy constructor Character" << DEF << std::endl;
	delete[] this->_name.c_str();
	*this = other;
}

// Destructor
Character::~Character() {
	std::cout << RED << "Destructor Character" << DEF << std::endl;
	delete[] this->_name.c_str();
}

// Copy assignement
Character &Character::operator=(Character const &other) {
	std::cout << GREEN << "Copy assignment Character" << DEF << std::endl;
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
    
}

void Character::unequip(int idx) {
    
}

void Character::use(int idx, ICharacter &target) {
    
}