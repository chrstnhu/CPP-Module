/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:15:58 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/16 17:33:47 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fixed.hpp"

// Copy assignement operator +
Fixed Fixed::operator+ ( const Fixed &other ) {
	Fixed result;
	result._raw = this->_raw + other._raw;
	return result;
}

// Copy assignement operator -
Fixed Fixed::operator- ( const Fixed &other ) {
	Fixed result;
	result._raw = this->_raw - other._raw;
	return result;
}

// Copy assignement operator *
Fixed Fixed::operator* ( const Fixed &other ) {
	Fixed result;
	result._raw = this->_raw * other._raw >> _rawBit;;
	return result;
}

// Copy assignement operator /
Fixed Fixed::operator/ ( const Fixed &other ) {
	if (other.getRawBits() == 0) {
		return Fixed(0);
	}
	Fixed result;
	result._raw = (this->_raw << _rawBit) / other._raw ;
	return result;
}