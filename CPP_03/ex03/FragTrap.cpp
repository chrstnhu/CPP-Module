/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:15:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/21 11:32:53 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap("Unamed", 100, 100, 30) {
	std::cout << GREEN << "Default FragTrap constructor" << DEF << std::endl;
}

// Constructor with parameters
FragTrap::FragTrap( std::string name) : ClapTrap (name, 100, 100, 30) {
	std::cout << GREEN << "FragTrap constructor with parameter" << DEF << std::endl;
}

// Copy constructor
FragTrap::FragTrap( const FragTrap &other) : ClapTrap(other) {
	std::cout << GREEN << "ScavTrap copy constructor " << DEF << std::endl;
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << GREEN << "Destruct FragTrap" << DEF << std::endl;
}

// Copy assignement
FragTrap &FragTrap::operator=( const FragTrap &other) {
	std::cout << GREEN << "ScavTrap copy assignement " << DEF << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// High fives
void FragTrap::highFivesGuys(void) {
	std::cout << YELLOW << getName() << "display a positive high five!" << DEF << std::endl;
}