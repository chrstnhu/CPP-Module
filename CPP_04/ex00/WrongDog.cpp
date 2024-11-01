/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 13:24:53 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

// Default constructor
WrongDog::WrongDog() : WrongAnimal("WrongDog") {
	std::cout << GREEN << "WrongDog Default constructor " << DEF << std::endl;
}

// Copy constructor
WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other) {
	std::cout << GREEN << "WrongDog Copy constructor " << DEF << std::endl;
}

// Destructor
WrongDog::~WrongDog() {
	std::cout << GREEN << "WrongDog destructor " << DEF << std::endl;
}

// Copy assignement
WrongDog &WrongDog::operator=(const WrongDog &other) {
	std::cout << GREEN << "WrongDog Copy assignement" << DEF << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

// Functions
void WrongDog::makeSound() const{
	std::cout << getType() << ": my little doggy" << std::endl;
}
