/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/12 11:10:56 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() : _type("Animal"){
	std::cout << GREEN << "Default constructor animal" << DEF << std::endl;
}

// Constructor with parameters
Animal::Animal(std::string type) : _type(type) {
	std::cout << GREEN << "Constructor animal" << DEF << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other) {
	std::cout << GREEN << "Copy constructor animal" << DEF << std::endl;
	_type = other._type;
}
		
// Destructor
Animal::~Animal() {
	std::cout << GREEN << "Destructor animal" << DEF << std::endl;
}

// Copy assignement
Animal &Animal::operator=(const Animal &other) {
	std::cout << GREEN << "Copy assignement animal" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

// Getter and setter
std::string Animal::getType() const {
	return _type;
}

void Animal::setType(std::string type) {
	_type = type + " Animal";
}


// Function
void Animal::makeSound() const{
	std::cout << getType() <<": Wowwwwwww" << std::endl;
}
