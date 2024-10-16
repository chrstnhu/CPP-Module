/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:52:03 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/16 17:42:32 by chrhu            ###   ########.fr       */
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
		Point &operator=( const Point &other );
		~Point();

		// Getters
		Fixed		getX( void ) const;
		Fixed		getY( void ) const;
		
		// Overload << operator
		friend std::ostream &operator<<( std::ostream &os, const Point &obj );
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
float sign(int x1, int y1, int x2, int y2, int xPoint, int yPoint);
#endif
