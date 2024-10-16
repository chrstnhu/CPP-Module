/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:29:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/16 17:32:56 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _raw(0) {
	std::cout << GREEN << "Default constructor called" << DEF << std::endl;
}

// Copy constructor
Fixed::Fixed( const Fixed &other ) {
	std::cout << GREEN << "Copy constructor called" << DEF << std::endl;
	*this = other;
}

// Destructor
Fixed::~Fixed() {
	std::cout << GREEN << "Destructor called" << DEF << std::endl;
}

// Copy assignement operator
Fixed &Fixed::operator= ( const Fixed &other ) {
    std::cout << GREEN << "Copy assignment operator called" << DEF << std::endl;
	if (this != &other) {
		_raw = other.getRawBits();
	}
	return *this;
}

// Getter
int		Fixed::getRawBits( void ) const {
	std::cout << GREEN << "getRawBits member function called" << DEF << std::endl;
	return this->_raw;
}

// Setter
void	Fixed::setRawBits( int const raw ) {
	_raw = raw;
}
