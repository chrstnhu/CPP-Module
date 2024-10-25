/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/25 11:17:17 by chrhu            ###   ########.fr       */
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
	*this = other;
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

std::string Animal::getType() const {
	return _type;
}

// Function
void Animal::makeSound() const{
	std::cout << getType() <<": Wowwwwwww" << std::endl;
}


// Default constructor
Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
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
Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
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
