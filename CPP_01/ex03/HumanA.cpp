/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:41 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 17:21:10 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

// Constructor
HumanA::HumanA(const std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << GREEN << "Construct HumanA" << std::endl;
	std::cout << YELLOW << "- Name: " << _name << std::endl;
	std::cout << "- Weapon: " << _weapon.getType() << DEF << std::endl;
	return ;
}

// Destructor
HumanA::~HumanA() {
	std::cout << GREEN << "Destruct HumanA" << DEF << std::endl;
	return ;
}

// Attack
void HumanA::attack(void) {
	if (_name.empty())
		std::cout << "Unamed attacks with their " << _weapon.getType() << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
	return ;
}