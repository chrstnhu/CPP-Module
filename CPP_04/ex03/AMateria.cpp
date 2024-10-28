/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:03:27 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/28 17:32:27 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default constructor
AMateria::AMateria() {
	std::cout << GREEN << "Default constructor AMateria" << DEF << std::endl;
}

// Constructor with parameter
AMateria::AMateria(std::string const & type) {
	std::cout << GREEN << "Constructor with parameter AMateria" << DEF << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria &other) {
	std::cout << GREEN << "Copy constructor AMateria" << DEF << std::endl;
}

// Destructor
AMateria::~AMateria() {
	std::cout << GREEN << "Destructor AMateria" << DEF << std::endl;
}

// Copy assignement operator
AMateria &AMateria::operator=(const AMateria &other) {
	std::cout << GREEN << "Copy assignement operator AMateria" << DEF << std::endl;
	return (*this);
}

// Getter
std::string const& AMateria::getType() const {
	return (this->_type);
}
