/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:15:58 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/17 18:35:17 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Copy assignement operator >
bool Fixed::operator> ( const Fixed &other ) const{
	return this->_raw > other._raw;
}

// Copy assignement operator <
bool Fixed::operator< ( const Fixed &other ) const{
	return this->_raw < other._raw;
}

// Copy assignement operator >=
bool Fixed::operator>= ( const Fixed &other ) const{
	return this->_raw > other._raw;
}

// Copy assignement operator <=
bool Fixed::operator<= ( const Fixed &other ) const{
	return this->_raw <= other._raw;
}

// Copy assignement operator ==
bool Fixed::operator== ( const Fixed &other ) const{
	return this->_raw == other._raw;
}

// Copy assignement operator !=
bool Fixed::operator!= ( const Fixed &other ) const{
	return this->_raw != other._raw;
}
