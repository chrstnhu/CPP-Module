/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:39 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/23 17:35:27 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB() {
	std::cout << GREEN << "Construct HumanB" << DEF << std::endl;
	return ;
}

HumanB::HumanB(const std::string name) {
	_name = name;
	std::cout << GREEN << "Construct HumanB" << std::endl;
	std::cout << YELLOW << "- name: " << _name << DEF << std::endl;
	return ;
}

HumanB::~HumanB() {
	std::cout << GREEN << "Destruct HumanB" << DEF << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
	std::cout << YELLOW << "- setWeapon: " <<  _weapon->getType()  << DEF << std::endl;
}

void HumanB::attack(void){
	std::cout << _name <<" attacks with their " << _weapon->getType() << std::endl;
}
