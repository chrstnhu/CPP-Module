/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/06 12:47:15 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << GREEN << "Cat Default constructor " << DEF << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other) : AAnimal(other) {
	std::cout << GREEN << "Copy constructor animal" << DEF << std::endl;
	_brain = new Brain(*other._brain);
}

// Destructor
Cat::~Cat() {
	std::cout << GREEN << "Cat destructor " << DEF << std::endl;
	delete _brain;
}

// Copy assignement
Cat &Cat::operator=(const Cat &other) {
    std::cout << GREEN << "Cat Copy assignement" << DEF << std::endl;
	if (this != &other) {
		delete _brain;
		AAnimal::operator=(other);
		_brain = new Brain(*other._brain);
	}
	return *this;
}

// Function
void Cat::makeSound() const {
	std::cout << getType() << ": Miaouuuuuuuu" << std::endl;
}
