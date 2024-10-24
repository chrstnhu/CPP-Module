/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/24 19:03:53 by chrhu            ###   ########.fr       */
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
	std::cout << GREEN << "Destructor animal" << DEF << std::endl;
}

// Copy assignement
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << GREEN << "Copy assignement WrongAnimal" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

// Function
void WrongAnimal::makeSound() const{
	std::cout << getType() <<": animaaaaals" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}


// Default constructor
WrongDog::WrongDog() : WrongAnimal("WrongDog") {
	std::cout << GREEN << "WrongDog Default constructor " << DEF << std::endl;
}

// Destructor
WrongDog::~WrongDog() {
	std::cout << GREEN << "WrongDog destructor " << DEF << std::endl;
}

// Functions
void WrongDog::makeSound() const{
	std::cout << getType() << ": my little doggy" << std::endl;
}



// Default constructor
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << GREEN << "WrongCat Default constructor " << DEF << std::endl;
}

// Destructor
WrongCat::~WrongCat() {
	std::cout << GREEN << "WrongCat destructor " << DEF << std::endl;
}

// Function
void WrongCat::makeSound() const{
	std::cout << getType() << ": my little cat" << std::endl;
}
