/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:29:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/10 19:39:45 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() {
	std::cout << GREEN << "Default constructor called" << DEF << std::endl;
}

// Copy constructor
Fixed::Fixed(Fixed &numberFixed) {
	std::cout << GREEN << "Copy constructor called" << DEF << std::endl;
}

// Destructor
Fixed::~Fixed() {
	std::cout << GREEN << "Destructor called" << DEF << std::endl;
}