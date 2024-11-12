/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/12 10:37:15 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << GREEN << "WrongAnimal Default constructor" << DEF << std::endl;
}

// Constructor with parameters
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << GREEN << "WrongAnimal Constructor" << DEF << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << GREEN << "WrongAnimal Copy constructor" << DEF << std::endl;
	_type = other._type;
}
		
// Destructor
WrongAnimal::~WrongAnimal() {
	std::cout << GREEN << "WrongAnimal Destructor" << DEF << std::endl;
}

// Copy assignement
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << GREEN << "WrongAnimal Copy assignement" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

// Getter
std::string WrongAnimal::getType() const {
	return _type;
}

// Function
void WrongAnimal::makeSound() const{
	std::cout << _type <<": Animaaaaals" << std::endl;
}
