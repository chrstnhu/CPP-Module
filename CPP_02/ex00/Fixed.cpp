/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:29:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/10 19:55:05 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_rawBit = 0;

// Default constructor
Fixed::Fixed() : _numberFixed(0) {
	std::cout << GREEN << "Default constructor called" << DEF << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &fixed) : _numberFixed(fixed._numberFixed){
	std::cout << GREEN << "Copy constructor called" << DEF << std::endl;
}

// Destructor
Fixed::~Fixed() {
	std::cout << GREEN << "Destructor called" << DEF << std::endl;
}

// Getter
int		Fixed::getRawBits( void ) const {
	std::cout << GREEN << "getRawBits member function called" << DEF << std::endl;
	return (this->_rawBit);
}

// Setter
void	Fixed::setRawBits( int const raw ) {
	(void)raw;
	std::cout << GREEN << "Copy assignment operator called" << DEF << std::endl;
}