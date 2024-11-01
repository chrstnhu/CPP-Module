/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 13:18:51 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal("Cat") {
	std::cout << GREEN << "Cat Default constructor " << DEF << std::endl;
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << GREEN << "Cat Copy constructor " << DEF << std::endl;
}

// Destructor
Cat::~Cat() {
	std::cout << GREEN << "Cat Destructor" << DEF << std::endl;
}

// Copy assignement
Cat &Cat::operator=(const Cat &other) {
    std::cout << GREEN << "Cat Copy assignement" << DEF << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

// Function
void Cat::makeSound() const{
	std::cout << getType() << ": Miaouuuuuuuu" << std::endl;
}
