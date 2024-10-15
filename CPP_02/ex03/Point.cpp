/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:04:36 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/15 14:16:31 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : x(0), y(0) {	
	std::cout << "Default Point constuctor" << std::endl;
}

// Constructor with parameters
Point::Point( const float x, const float y ) : _x(x), _y(y) {
	std::cout << "Constructor with parameters";
}

// Destructor
Point::~Point() {
	std::cout << "Point destructor" << std::endl;
}
		
// Copy assignment
Point &Point::operator=( const Point &other ) {
	if (this != &other) {
		_x = other.getX();
		_y = other.getY();
	}
	return *this;
}

// Getters
Fixed		Point::getX(void) const {
	return _x;
}

Fixed		Point::getY(void) const {
		return _y;
}


// Overload << operator
std::ostream &operator<<( std::ostream &os, const Point &obj ) {
	os << obj.functions;
	return os;
}