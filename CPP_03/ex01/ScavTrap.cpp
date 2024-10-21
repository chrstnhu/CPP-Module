/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:26:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/21 15:29:01 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Unamed", 100, 50, 20) {
	std::cout << GREEN << "Default ScavTrap constructor" << DEF << std::endl;
}

// Constructor with parameters
ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	std::cout << GREEN << "ScavTrap constructor with parameter" << DEF << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {
	std::cout << GREEN << "ScavTrap copy constructor " << DEF << std::endl;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << GREEN << "ScavTrap destructor" << DEF << std::endl;
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
	if (getEnergyPoint() > 0 && getHitPoint() > 0) {
		std::cout << std::endl <<"ScavTrap causing "
			<< YELLOW << getAttackDamage() << DEF
			<< " points of damage to "
			<< target << std::endl;
		setEnergyPoint(getEnergyPoint() - 1);
	}
	else
		std::cout << RED << getName() << " can't attack!" << DEF << std::endl;
}

// Guard keeper mode
void ScavTrap::guardGate() {
	std::cout << YELLOW << getName() << " is in guard gate keeper mode" << DEF << std::endl << std::endl;
}
