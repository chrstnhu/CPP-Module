/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:52:03 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/15 16:53:00 by chrhu            ###   ########.fr       */
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
		Point( const float x, const float y );
		~Point();
		
		// Copy assignment
		Point &operator=( const Point &other );

		// Getters
		Fixed		getX(void) const;
		Fixed		getY(void) const;
		
		// Overload << operator
		friend std::ostream &operator<<( std::ostream &os, const Point &obj );
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
float sign( Point p1, Point p2, Point p3);

#endif
