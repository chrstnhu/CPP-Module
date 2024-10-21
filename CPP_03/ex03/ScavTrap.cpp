/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:26:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/18 18:39:18 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Unamed", 100, 50, 20) {
	std::cout << GREEN << "Default ScavTrap constructor" << DEF << std::endl;
}

// Constructor with parameters
ScavTrap::ScavTrap( std::string name ) : ClapTrap(name, 100, 50, 20) {
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

// Guard keeper mode
void ScavTrap::guardGate() {
	std::cout << YELLOW << getName() << " is in guard gate keeper mode" << DEF << std::endl << std::endl;
}
