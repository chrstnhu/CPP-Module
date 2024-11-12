/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/11 16:31:17 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// Default constructor
AAnimal::AAnimal() : _type("Animal"){
	std::cout << GREEN << "Default constructor animal" << DEF << std::endl;
}

// Constructor with parameters
AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << GREEN << "Constructor animal" << DEF << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal &other) {
	std::cout << GREEN << "Copy constructor animal" << DEF << std::endl;
	this->_type = other._type;
}
		
// Destructor
AAnimal::~AAnimal() {
	std::cout << GREEN << "Destructor animal" << DEF << std::endl;
}

// Copy assignement
AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << GREEN << "Copy assignement animal" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

// Getter and setter
std::string AAnimal::getType() const {
	return _type;
}

void AAnimal::setType(std::string type) {
	_type = type;
}

// Function
void AAnimal::makeSound() const{
	std::cout << getType() <<": Wowwwwwww" << std::endl;
}
