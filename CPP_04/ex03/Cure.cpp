/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:37:46 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 13:03:29 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << GREEN << "Default constructor Cure" << DEF << std::endl;
}

// Constructor with parameter
Cure::Cure(std::string type) : AMateria("cure " + type) {
	std::cout << GREEN << "Constructor with parameter Cure" << DEF << std::endl;
}

// Copy constructor
Cure::Cure(const Cure &other) {
	std::cout << GREEN << "Copy constructor Cure" << DEF << std::endl;
	*this = other;
}

// Destructor
Cure::~Cure() {
	std::cout << GREEN << "Destructor Cure" << DEF << std::endl;
}

// Copy assignement operator
Cure &Cure::operator=(const Cure &other) {
	std::cout << GREEN << "Copy assignement operator Cure" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Function 
void Cure::use(ICharacter& target) {
	std::cout << "* heals <" << target.getName() << "’s wounds *" << std::endl;
}
