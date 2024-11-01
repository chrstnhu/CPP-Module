/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:26:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 12:42:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Unamed") {
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << GREEN << "Default ScavTrap constructor" << DEF << std::endl;
}

// Constructor with parameters
ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	this->_hitPoint = 100;
	this->_energyPoint = 50;z
	this->_attackDamage = 20;
	std::cout << GREEN << "ScavTrap constructor with parameter" << DEF << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {
	std::cout << GREEN << "ScavTrap copy constructor " << DEF << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << GREEN << "Destruct ScavTrap" << DEF << std::endl;
}

// Copy assignement
ScavTrap &ScavTrap::operator=( const ScavTrap &other ) {
	std::cout << GREEN << "ScavTrap copy assignement " << DEF << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}


// Attack someone
void ScavTrap::attack(const std::string& target){
	if (this->_energyPoint > 0 && this->_hitPoint > 0) {
		std::cout << std::endl <<"ScavTrap " << _name << " causing "
			<< YELLOW << this->_attackDamage << DEF
			<< " points of damage to " << target << std::endl;
		this->_energyPoint--;
	}
	else
		std::cout << RED << _name << " can't attack!" << DEF << std::endl;
}

// Guard keeper mode
void ScavTrap::guardGate() {
	std::cout << YELLOW << _name << " is in guard gate keeper mode" << DEF << std::endl << std::endl;
}
