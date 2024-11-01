/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 13:31:53 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() : _type("Animal") {
	std::cout << GREEN << "Animal Default constructor" << DEF << std::endl;
}

// Constructor with parameters
Animal::Animal(std::string type) : _type(type) {
	std::cout << GREEN << "Animal Constructor with parameters" << DEF << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other) {
	std::cout << GREEN << "Animal Copy constructor" << DEF << std::endl;
	*this = other;
}
		
// Destructor
Animal::~Animal() {
	std::cout << GREEN << "Animal Destructor" << DEF << std::endl;
}

// Copy assignement
Animal &Animal::operator=(const Animal &other) {
	std::cout << GREEN << "Animal Copy assignement" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

std::string Animal::getType() const {
	return _type;
}

// Function
void Animal::makeSound() const{
	std::cout << getType() <<": Wowwwwwww" << std::endl;
}
