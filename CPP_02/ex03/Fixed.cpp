/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:29:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/16 18:55:41 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

float const Fixed::_rawFloatBit = static_cast<float>(1 << _rawBit);

// Default constructor
Fixed::Fixed() : _raw(0) {
}

// Converts the int to fixed-point number
Fixed::Fixed(int number) {
	_raw = number << _rawBit;
}

// Converts the float to fixed-point number
Fixed::Fixed(float number) {
	_raw = static_cast<int>(roundf(number * _rawFloatBit));
}

// Copy constructor
Fixed::Fixed( const Fixed &other ) {
	*this = other;
}

// Destructor
Fixed::~Fixed() {
}

// Copy assignement operator =
Fixed &Fixed::operator= ( const Fixed &other ) {
	if (this != &other) {
		_raw = other.getRawBits();
	}
	return *this;
}

// Getter
int		Fixed::getRawBits( void ) const {
	return _raw;
}

// Setter
void	Fixed::setRawBits( int const raw ) {
	_raw = raw;
}

// Converts the value to float
float	Fixed::toFloat( void ) const {
	return static_cast<float>(_raw) / _rawFloatBit;
}

// Converts the value to int
int		Fixed::toInt( void ) const {
	return _raw >> _rawBit;
}

// Overloads the << operator for output
std::ostream &operator << (std::ostream& os, const Fixed &obj) {
	os << obj.toFloat();
	return os;
}
