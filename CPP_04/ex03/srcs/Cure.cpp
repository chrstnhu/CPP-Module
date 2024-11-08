/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:37:46 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/08 12:33:35 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

// Constructor with parameter
Cure::Cure(std::string type) : AMateria("cure " + type) {
}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria(other) {
}

// Destructor
Cure::~Cure() {
}

// Copy assignement operator
Cure &Cure::operator=(const Cure &other) {
	if (this != &other) {
		AMateria::operator=(other);
		// _type = other._type;
	}
	return *this;
}

// Function 
AMateria* Cure::clone() const{
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << GREEN << target.getName() << DEF
		<< "’s wounds *" << std::endl;
}
