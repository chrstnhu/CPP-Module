/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:03:27 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/07 13:59:24 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

// Default constructor
AMateria::AMateria() : _type("Unamed") {
}

// Constructor with parameter
AMateria::AMateria(std::string const &type) : _type(type) {
}

// Copy constructor
AMateria::AMateria(const AMateria &other) {
	_type = other._type;
}

// Destructor
AMateria::~AMateria() {
}

// Copy assignement operator
AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		// _type = other._type;
	}
	return *this;
}

// Getter
std::string const& AMateria::getType() const {
	return this->_type;
}

// Function 
void AMateria::use(ICharacter& target) {
	std::cout << "* Nothing to use of "
		<< target.getName()	<< " wounds *" << std::endl;
}
