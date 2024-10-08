/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:39 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 17:21:50 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

// Default constructor
HumanB::HumanB() {
	std::cout << GREEN << "Construct HumanB" << DEF << std::endl;
	return ;
}

// Constructor : name
HumanB::HumanB(const std::string name) : _name(name), _weapon(0) {
	std::cout << GREEN << "Construct HumanB" << std::endl;
	std::cout << YELLOW << "- Name: " << _name << DEF << std::endl;
	return ;
}

// Destructor
HumanB::~HumanB() {
	std::cout << GREEN << "Destruct HumanB" << DEF << std::endl;
	return ;
}

// Set Weapon
void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
	std::cout << YELLOW << "- SetWeapon: " <<  _weapon->getType()  << DEF << std::endl;
	return ;
}

// Attack
void HumanB::attack(void) {
	if (_weapon == 0)
	{
		if (_name.empty())
			std::cout << "Unamed doesn't have a Weapon." << std::endl;
		else
			std::cout << _name <<" doesn't have a Weapon." << std::endl;
	}
	else
	{
		if (_name.empty())
			std::cout << "Unamed attacks with their " << _weapon->getType() << std::endl;
		else
			std::cout << _name <<" attacks with their " << _weapon->getType() << std::endl;
	}
	return ;
}
