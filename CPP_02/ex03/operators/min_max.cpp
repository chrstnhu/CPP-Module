/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:15:58 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/15 13:59:52 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Return the smallest number
Fixed Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

// Return the bigest number
Fixed Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}

// Return the smallest number const
Fixed const Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

// Return the bigest number const
Fixed const Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}