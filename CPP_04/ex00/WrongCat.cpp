/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 13:24:29 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << GREEN << "WrongCat Default constructor" << DEF << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << GREEN << "WrongCat Copy constructor" << DEF << std::endl;
}

// Destructor
WrongCat::~WrongCat() {
	std::cout << GREEN << "WrongCat destructor " << DEF << std::endl;
}

// Copy assignement
WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << GREEN << "WrongCat Copy assignement" << DEF << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

// Function
void WrongCat::makeSound() const{
	std::cout << getType() << ": my little cat" << std::endl;
}
