/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:15:58 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/14 18:14:26 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fixed.hpp"

// Copy assignement operator >
bool Fixed::operator> (const Fixed &other) const{
	return this->_raw > other._raw;
}

// Copy assignement operator <
bool Fixed::operator< (const Fixed &other) const{
	return this->_raw < other._raw;
}

// Copy assignement operator >=
bool Fixed::operator>= (const Fixed &other) const{
	return this->_raw > other._raw;
}

// Copy assignement operator <=
bool Fixed::operator<= (const Fixed &other) const{
	return this->_raw <= other._raw;
}

// Copy assignement operator ==
bool Fixed::operator== (const Fixed &other) const{
	return this->_raw == other._raw;
}

// Copy assignement operator !=
bool Fixed::operator!= (const Fixed &other) const{
	return this->_raw != other._raw;
}
