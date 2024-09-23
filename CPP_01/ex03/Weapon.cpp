/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:37 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/23 17:59:28 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	std::cout << GREEN << "Construct Weapon" << DEF << std::endl;
	return ;
};

Weapon::Weapon(const std::string type) : _type(type) {
	std::cout << GREEN << "Construct Weapon with type: " << _type << DEF << std::endl;
	return ;
};

Weapon::~Weapon() {
	std::cout << GREEN << "Destruct Weapon" << DEF << std::endl;
	return ;
};

void Weapon::setType(const std::string type) {
	_type = type;
	return ;
}

std::string Weapon::getType() const {
	return _type;
}