/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:31:31 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 16:21:43 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << GREEN << "Default constructor Ice" << DEF << std::endl;
}

// Constructor with parameter
Ice::Ice(std::string type) : AMateria("ice " + type) {
	std::cout << GREEN << "Constructor with parameter Ice" << DEF << std::endl;
}

// Copy constructor
Ice::Ice(const Ice &other) {
	std::cout << GREEN << "Copy constructor Ice" << DEF << std::endl;
	*this = other;
}

// Destructor
Ice::~Ice() {
	std::cout << GREEN << "Destructor Ice" << DEF << std::endl;
}

// Copy assignement operator
Ice &Ice::operator=(const Ice &other) {
	std::cout << GREEN << "Copy assignement operator Ice" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Function 
Ice* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at" << target.getName() << " *" << std::endl;
}