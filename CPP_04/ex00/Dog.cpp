/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 13:14:32 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
Dog::Dog() : Animal("Dog") {
	std::cout << GREEN << "Dog Default constructor " << DEF << std::endl;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << GREEN << "Dog copy constructor " << DEF << std::endl;
}

// Destructor
Dog::~Dog() {
	std::cout << GREEN << "Dog Destructor" << DEF << std::endl;
}

// Copy assignement
Dog &Dog::operator=(const Dog &other) {
	std::cout << GREEN << "DOg copy assignement" << DEF << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

// Functions
void Dog::makeSound() const{
	std::cout << getType() << ": Waoufffffff" << std::endl;
}
