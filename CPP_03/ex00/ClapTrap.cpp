/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:21:42 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/06 12:07:07 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap(): _name("Unnamed"), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap Default constructor" << DEF << std::endl;
}

// ClapTrap constructor with parameter
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << GREEN << "ClapTrap constructor with parameter" << DEF << std::endl;
}
// Copy constructor
ClapTrap::ClapTrap( const ClapTrap &other ) {
	std::cout << GREEN << "ClapTrap Copy constructor" << DEF << std::endl;
	this->_name = other._name;
	this->_hitPoint = other._hitPoint;
	this->_energyPoint = other._energyPoint;
	this->_attackDamage = other._attackDamage;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << GREEN << "ClapTrap Destructor" << DEF << std::endl;
}

// Copy assignement operator =
ClapTrap &ClapTrap::operator=( const ClapTrap &other ) {
	std::cout << GREEN << "ClapTrap Copy assignement" << DEF << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Setters and getters
std::string ClapTrap::getName(void) const {
	return this->_name;
}

int		ClapTrap::getAttackDamage( void ) const {
	return this->_attackDamage;
}
		
int		ClapTrap::getHitPoint( void ) const {
	return this->_hitPoint;
}

int		ClapTrap::getEnergyPoint( void ) const {
	return this->_energyPoint;
}
		
// Attack someone
void ClapTrap::attack(const std::string& target) {
	if (_energyPoint > 0 && _hitPoint > 0) {
		std::cout << std::endl <<"ClapTrap " <<_name << " attacks "
			<< target << " causing "
			<< YELLOW << _attackDamage << DEF
			<< " points of damage!" << std::endl;
		_energyPoint--;
	}
	else
		std::cout << RED << _name << " can't attack!" << DEF << std::endl;
}

// Take damage of hit point
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoint < 0) {
        std::cout << RED << "Can't attack "
			<< _name << ", he is defeated!" << DEF << std::endl;
    }
	else if (_hitPoint - amount > _hitPoint) {
		std::cout << std::endl << RED << "Attack damage : "
			<< _attackDamage + amount
			<< ", ennemy can't attack more than 10 energy points" << DEF << std::endl;
	}
	else
	{
		if (amount >= _hitPoint) {
            _hitPoint = 0;
        } else {
            _hitPoint -= amount;
        }
		std::cout << std::endl << _name << " take " << YELLOW << amount << DEF 
			<< " damage(s), hit point(s) remaining: " 
			<< YELLOW << _hitPoint << DEF << std::endl;
	}

}

// Repair hitpoint
void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoint == 0 ) {
		std::cout << std::endl << RED << _name 
			<< " can't be repaired. "<< DEF << std::endl;
	}
	else if ((_energyPoint > 0) && (amount <= _energyPoint)) {
		
		_hitPoint += amount;
		_energyPoint -= amount;
		std::cout << std::endl << "Current hit point(s): " << YELLOW << (_hitPoint - amount) << DEF
				<< ", repaired: " << YELLOW << amount << DEF
				<< ", after repaired: " << YELLOW << _hitPoint << DEF << std::endl;
	}
	else {
		std::cout << std::endl << RED << _name 
			<< " can't be repaired with "<< amount << ", max " << _energyPoint << " energy point(s)" << DEF << std::endl;
	}
}
