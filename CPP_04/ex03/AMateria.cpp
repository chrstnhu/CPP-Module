/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:03:27 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/30 16:47:35 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default constructor
AMateria::AMateria() : _type("Unamed") {
}

// Constructor with parameter
AMateria::AMateria(std::string type) : _type(type) {
}

// Copy constructor
AMateria::AMateria(const AMateria &other) {
	*this = other;
}

// Destructor
AMateria::~AMateria() {
}

// Copy assignement operator
AMateria &AMateria::operator=(const AMateria &other) {
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
