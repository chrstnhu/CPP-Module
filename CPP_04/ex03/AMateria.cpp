/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:03:27 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/30 14:56:12 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default constructor
AMateria::AMateria() : _type("Unamed") {
	// std::cout << GREEN << "Default constructor AMateria" << DEF << std::endl;
}

// Constructor with parameter
AMateria::AMateria(std::string type) : _type(type) {
	// std::cout << GREEN << "Constructor with parameter AMateria" << DEF << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria &other) {
	// std::cout << GREEN << "Copy constructor AMateria" << DEF << std::endl;
	*this = other;
}

// Destructor
AMateria::~AMateria() {
	// std::cout << GREEN << "Destructor AMateria" << DEF << std::endl;
}

// Copy assignement operator
AMateria &AMateria::operator=(const AMateria &other) {
	// std::cout << GREEN << "Copy assignement operator AMateria" << DEF << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
}

// Getter
std::string const& AMateria::getType() const {
	return (this->_type);
}

// Function 
void AMateria::use(ICharacter& target) {
	std::cout << "* Nothing to use of " << target.getName() << " wounds *" << std::endl;
}
