/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:31:31 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/08 12:33:38 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {
}

// Constructor with parameter
Ice::Ice(std::string type) : AMateria(type) {
	type = "ice" + AMateria::_type;
}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria(other) {
}

// Destructor
Ice::~Ice() {
}

// Copy assignement operator
Ice &Ice::operator=(const Ice &other) {
	if (this != &other) {
		AMateria::operator=(other);
		// _type = other._type;
	}
	return *this;
}

// Function 
AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "
		<< GREEN << target.getName() << DEF << " *" << std::endl;
}