/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:15:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/24 18:50:52 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

// Default constructor
WrongDog::WrongDog() : WrongAnimal("WrongDog") {
	std::cout << GREEN << "WrongDog Default constructor " << DEF << std::endl;
}

// Destructor
WrongDog::~WrongDog() {
	std::cout << GREEN << "WrongDog destructor " << DEF << std::endl;
}

// Functions
void WrongDog::makeSound() const{
	std::cout << getType() << ": my little doggy" << std::endl;
}
