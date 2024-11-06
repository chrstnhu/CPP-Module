/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:15:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/06 12:10:01 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap("Unnamed", 100, 100, 30) {
	std::cout << GREEN << "Default FragTrap constructor" << DEF << std::endl;
}

// Constructor with parameters
FragTrap::FragTrap( std::string name) : ClapTrap (name, 100, 100, 30) {
	std::cout << GREEN << "FragTrap constructor with parameter" << DEF << std::endl;
}

// Copy constructor
FragTrap::FragTrap( const FragTrap &other) : ClapTrap(other) {
	std::cout << GREEN << "FragTrap copy constructor " << DEF << std::endl;
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << GREEN << "FragTrap Destruct" << DEF << std::endl;
}

// Copy assignement
FragTrap &FragTrap::operator=( const FragTrap &other) {
	std::cout << GREEN << "FragTrap copy assignement " << DEF << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}


// High fives
void FragTrap::highFivesGuys(void) {
	if (_hitPoint == 0 || _energyPoint == 0) {
		std::cout << RED << _name << " can't high five" << DEF << std::endl;
	}
	else {
		std::cout << YELLOW << _name << " display a positive high five!" << DEF << std::endl;
	}
}