/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:37 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 17:22:45 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Default constructor
Weapon::Weapon() {
	std::cout << GREEN << "Construct Weapon" << DEF << std::endl;
	return ;
};

// Constructor : type
Weapon::Weapon(const std::string type) : _type(type) {
	std::cout << GREEN << "Construct Weapon with type: " << _type << DEF << std::endl;
	return ;
};

// Destructor
Weapon::~Weapon() {
	std::cout << GREEN << "Destruct Weapon" << DEF << std::endl;
	return ;
};

// Set type
void Weapon::setType(const std::string type) {
	_type = type;
}

// Get type
std::string Weapon::getType() const {
	return _type;
}