/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:52:03 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/17 12:20:36 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

class Point {
	
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point( const int x, const int y );
		Point( const float x, const float y );
		Point( const Point &other );
		~Point();

		// Copy assignment operator overload
		Point &operator=( const Point &other );
		
		// Getters
		Fixed		getX( void ) const;
		Fixed		getY( void ) const;
		
};

// Overloads the << operator
std::ostream &operator << (std::ostream& os, const Fixed &obj);

// Binary space partitioning (find if the point is in the triangle)
bool	bsp( Point const a, Point const b, Point const c, Point const point);
float	sign(int x1, int y1, int x2, int y2, int xPoint, int yPoint);
#endif
