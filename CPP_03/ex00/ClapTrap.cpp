/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:21:42 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/18 12:52:24 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name(0), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << GREEN << "Default ClapTrap constructor" << DEF << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << GREEN << "Copy constructor ClapTrap" << DEF << std::endl;
	*this = other;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << GREEN << "Destruct ClapTrap" << DEF << std::endl;
}

// Copy assignement operator =
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << GREEN << "Copy assignement ClapTrap" << DEF << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

/*
aattack function()
print : ClapTrap <name> attacks <target>, causing <damage> points of damage!
*/