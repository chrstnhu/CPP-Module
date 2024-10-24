/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:15:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/24 18:50:57 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << GREEN << "WrongCat Default constructor " << DEF << std::endl;
}

// Destructor
WrongCat::~WrongCat() {
	std::cout << GREEN << "WrongCat destructor " << DEF << std::endl;
}

// Function
void WrongCat::makeSound() const{
	std::cout << getType() << ": my little cat" << std::endl;
}
