/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 13:23:43 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << GREEN << "Default constructor WrongAnimal" << DEF << std::endl;
}

// Constructor with parameters
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << GREEN << "Constructor WrongAnimal" << DEF << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	std::cout << GREEN << "Copy constructor WrongAnimal" << DEF << std::endl;
	*this = other;
}
		
// Destructor
WrongAnimal::~WrongAnimal() {
	std::cout << GREEN << "Destructor WrongAnimal" << DEF << std::endl;
}

// Copy assignement
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << GREEN << "Copy assignement WrongAnimal" << DEF << std::endl;
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
	std::cout << getType() <<": animaaaaals" << std::endl;
}
