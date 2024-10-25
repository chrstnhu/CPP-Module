/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/25 16:53:58 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

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
	*this = other;
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

std::string AAnimal::getType() const {
	return _type;
}

// Function
void AAnimal::makeSound() const{
	std::cout << getType() <<": Wowwwwwww" << std::endl;
}


// Default constructor
Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	std::cout << GREEN << "Dog Default constructor " << DEF << std::endl;
}

// Destructor
Dog::~Dog() {
	std::cout << GREEN << "Dog destructor " << DEF << std::endl;
	delete _brain;
}

// Functions
void Dog::makeSound() const{
	std::cout << getType() << ": Waoufffffff" << std::endl;
}


// Default constructor
Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << GREEN << "Cat Default constructor " << DEF << std::endl;
}

// Destructor
Cat::~Cat() {
	std::cout << GREEN << "Cat destructor " << DEF << std::endl;
	delete _brain;
}

// Function
void Cat::makeSound() const{
	std::cout << getType() << ": Miaouuuuuuuu" << std::endl;
}
