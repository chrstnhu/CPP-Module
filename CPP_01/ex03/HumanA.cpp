/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:41 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/23 17:58:56 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << GREEN << "Construct HumanA" << std::endl;
	std::cout << YELLOW << "- name: " << _name << std::endl;
	std::cout << "- weapon: " << _weapon.getType() << DEF << std::endl;
	return ;
}

HumanA::~HumanA() {
	std::cout << GREEN << "Destruct HumanA" << DEF << std::endl;
	return ;
}

void HumanA::attack(void) {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
	return ;
}