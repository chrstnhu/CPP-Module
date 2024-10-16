/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_decrement.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:15:58 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/16 17:35:41 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Increment pre-increment
Fixed &Fixed::operator++() {
	_raw++;
	return *this;
}

// Decrement pre-increment
Fixed &Fixed::operator--() {
	_raw--;
	return *this;
}

// Increment post-increment
Fixed Fixed::operator++( int ) {
	Fixed temp;
	temp._raw = _raw;
	_raw++;
	return temp;
}

// Decrement post-increment
Fixed Fixed::operator--( int ) {
	Fixed temp;
	temp._raw = _raw;
	_raw--;
	return temp;
}