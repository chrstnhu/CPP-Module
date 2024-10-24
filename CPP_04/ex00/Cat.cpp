/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:15:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/24 15:12:42 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Default constructor
Cat::Cat() : Animal("Cat") {
	std::cout << GREEN << "Cat Default constructor " << DEF << std::endl;
}

// Destructor
Cat::~Cat() {
	std::cout << GREEN << "Cat destructor " << DEF << std::endl;
}

// Function
void Cat::makeSound() const{
	std::cout << getType() << ": Miaouuuuuuuu" << std::endl;
}
