/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:31:31 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/28 17:38:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << GREEN << "Default constructor Ice" << DEF << std::endl;
}

// Constructor with parameter
Ice::Ice(std::string const & type) : AMateria("ice"), _type(type) {
	std::cout << GREEN << "Constructor with parameter Ice" << DEF << std::endl;
}

// Copy constructor
Ice::Ice(const Ice &other) {
	std::cout << GREEN << "Copy constructor Ice" << DEF << std::endl;
}

// Destructor
Ice::~Ice() {
	std::cout << GREEN << "Destructor Ice" << DEF << std::endl;
}

// Copy assignement operator
Ice &Ice::operator=(const Ice &other) {
	std::cout << GREEN << "Copy assignement operator Ice" << DEF << std::endl;
	return (*this);
}

// Function 
void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at" << getType()<< " *" << std::endl;
}
