/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:04:36 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/15 17:24:03 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {	
}

// Constructor with parameters
Point::Point( const float x, const float y ) : _x(x), _y(y) {
}

// Destructor
Point::~Point() {
}
		
// Copy assignment
Point &Point::operator=( const Point &other ) {
	if (this != &other) {
		const_cast<Fixed&>(_x) = other._x;
		const_cast<Fixed&>(_y) = other._y;
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
	os << "Point(" << obj._x << ", " << obj._y << ")";
	return os;
}

// Calculate the sign value to determine the position of the point
float sign(Point p1, Point p2, Point point) {
    float x1 = p1.getX().toFloat();
    float y1 = p1.getY().toFloat();
    float x2 = p2.getX().toFloat();
    float y2 = p2.getY().toFloat();
    float xPoint = point.getX().toFloat();
    float yPoint = point.getY().toFloat();

    return (x1 - x2) * (yPoint - y2) - (xPoint - x2) * (y1 - y2);
}

// Tests if a point is inside a triangle (a, b, c)
bool bsp( Point const a, Point const b, Point const c, Point const point) {
	float dist1 = sign(a, b, point);
	float dist2 = sign(b, c, point);
	float dist3 = sign(c, a, point);

	bool has_neg = (dist1 < 0) || (dist2 < 0) || (dist3 < 0);
	bool has_pos = (dist1 > 0) || (dist2 > 0) || (dist3 > 0);

    return !(has_neg && has_pos) && (dist1 != 0 && dist2 != 0 && dist3 != 0);
}
