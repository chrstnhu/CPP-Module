/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:21:42 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/06 12:10:21 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("Unnamed_clap_name", FragTrap::_defaultHitPoint,
	ScavTrap::_defaultEnergyPoint, FragTrap::_defaultAttackDamage),
	ScavTrap("Unnamed"), FragTrap("Unnamed"), _name("Unnamed") {
	std::cout << GREEN << "Default DiamondTrap constructor" << DEF << std::endl;
}

// Constructor with parameters
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", FragTrap::_defaultHitPoint,
	ScavTrap::_defaultEnergyPoint, FragTrap::_defaultAttackDamage),
	ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << GREEN << "DiamondTrap constructor with parameters" << DEF << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ScavTrap(other), FragTrap(other) {
	std::cout << GREEN << "Copy constructor DiamondTrap" << DEF << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << GREEN << "Destruct DiamondTrap" << DEF << std::endl;
}

// Copy assignement
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << GREEN << "DiamondTrap copy assignement" << DEF << std::endl;
	if (this != &other) {
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
	}
	return *this;
}


// Getter
std::string DiamondTrap::getName() const {
	return _name;
}


// Function
void DiamondTrap::whoAmI() {
	std::cout << "My name: " << _name
		<< ", my ClapTrap name: " << ClapTrap::_name << std::endl;
}