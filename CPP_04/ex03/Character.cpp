/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:20:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 15:58:36 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _type("unamed") {
	std::cout << GREEN << "Default constructor Character" << DEF << std::endl;
}

Character::Character(std::string type) : _type(type) {
	std::cout << GREEN << "Constructor with parameters Character" << DEF << std::endl;
}

Character::Character(Character const &other) {
	std::cout << GREEN << "Copy constructor Character" << DEF << std::endl;
	delete[] this->_type.c_str();
	*this = other;
}

Character::~Character() {
	std::cout << RED << "Destructor Character" << DEF << std::endl;
	delete[] this->_type.c_str();
}

Character &Character::operator=(Character const &other) {
	std::cout << GREEN << "Copy assignment Character" << DEF << std::endl;
	if (this != &other) {
		delete[] this->_type.c_str();
		this->_type = other._type;
	}
	return (*this);
}
