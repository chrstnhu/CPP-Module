/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/11 12:47:48 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << GREEN << "Cat Default constructor " << DEF << std::endl;
}

// Constructor with parameter
Cat::Cat(std::string const type) : Animal(type), _brain(new Brain()) {
	_type = Animal::_type + " cat";
	std::cout << GREEN << _type << " constructor with parameter" << DEF << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << GREEN << _type << " copy constructor" << DEF << std::endl;
	_brain = new Brain(*other._brain);
}

// Destructor
Cat::~Cat() {
	std::cout << GREEN << _type << " destructor " << DEF << std::endl;
	delete _brain;
}

// Copy assignement
Cat &Cat::operator=(const Cat &other) {
    std::cout << GREEN << _type << " copy assignement" << DEF << std::endl;
	if (this != &other) {
		delete _brain;
		Animal::operator=(other);
		_brain = new Brain(*other._brain);
	}
	return *this;
}


// Getter and setter
std::string Cat::getBrainIdeas(int index) const {
	if (index >= 0 && index < MAX_IDEAS) {
		return _brain->ideas[index];
	}
	return "Invalid index";
}

void Cat::setBrainIdeas(int index, std::string idea) {
	if (index >= 0 && index < MAX_IDEAS) {
		_brain->ideas[index] = idea;
	}
}


// Function
void Cat::makeSound() const {
	std::cout << getType() << ": Miaouuuuuuuu" << std::endl;
}
