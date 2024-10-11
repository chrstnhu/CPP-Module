/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:29:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/11 17:01:05 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

float const Fixed::_rawFloatBit = 8.0f;

// Default constructor
Fixed::Fixed() : _raw(0) {
	std::cout << GREEN << "Default constructor called" << DEF << std::endl;
}

// Constructor with parameters
// Converts the int to fixed-point number
Fixed::Fixed(int number) {
	std::cout << GREEN << "Int constructor called" << DEF << std::endl;
	_raw = number << _rawBit;
}

// Converts the float to fixed-point number
Fixed::Fixed(float number) {
	std::cout << GREEN << "Float constructor called" << DEF << std::endl;
	_raw = static_cast<int>(roundf(number * (1 << _rawBit)));
}

// Copy constructor
Fixed::Fixed( const Fixed &other ) : _raw(other._raw) {
	std::cout << GREEN << "Copy constructor called" << DEF << std::endl;
}

// Destructor
Fixed::~Fixed() {
	std::cout << GREEN << "Destructor called" << DEF << std::endl;
}

// Copy assignement operator
Fixed &Fixed::operator= (const Fixed &other) {
    std::cout << GREEN << "Copy assignment operator called" << DEF << std::endl;
	if (this != &other) {
		_raw = other.getRawBits();
	}
	return *this;
}

// Getter
int		Fixed::getRawBits( void ) const {
	return this->_raw;
}

// Setter
void	Fixed::setRawBits( int const raw ) {
	_raw = raw;
}

// Converts the value to float
float	Fixed::toFloat( void ) const {
	return static_cast<float>(_raw) / (1 << _rawBit);
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