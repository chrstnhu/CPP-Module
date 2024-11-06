/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/06 12:48:54 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	std::cout << GREEN << "Dog Default constructor " << DEF << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout << GREEN << "Copy constructor animal" << DEF << std::endl;
	_brain = new Brain(*other._brain);
}

// Destructor
Dog::~Dog() {
	std::cout << GREEN << "Dog destructor " << DEF << std::endl;
	delete _brain;
}

// Copy assignement
Dog &Dog::operator=(const Dog &other) {
	std::cout << GREEN << "DOg copy assignement" << DEF << std::endl;
	if (this != &other) {
		delete _brain;
		AAnimal::operator=(other);
		_brain = new Brain(*other._brain);
	}
	return *this;
}

// Functions
void Dog::makeSound() const{
	std::cout << getType() << ": Waoufffffff" << std::endl;
}