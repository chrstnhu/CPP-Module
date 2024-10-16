/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:05:38 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/16 11:06:44 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"
#include "includes/Point.hpp"

static void print_bsp(Point &a, Point &b, Point &c, Point point);

int main(void) {
	// Triangle coordinates
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	std::cout << "Triangle coordinates = a(0, 0); b(5, 0); c(0, 5)" << std::endl << std::endl;
	
	//Points
	Point p1(1, 1);
	Point p2(1.658, 2.5);
	Point p3(0, 0);
	Point p4(2, 0);
	Point p5(6.6, 1);

	print_bsp(a, b, c, p1);
	print_bsp(a, b, c, p2);
	print_bsp(a, b, c, p3);
	print_bsp(a, b, c, p4);
	print_bsp(a, b, c, p5);
	return 0;
}

static void print_bsp(Point &a, Point &b, Point &c, Point point)
{
	if (bsp(a, b, c, point)) {
		std::cout << "Test for point (" << point.getX() << ", " << point.getY() << "): ";
		std::cout << "Inside the triangle" << std::endl;
	} else {
		std::cout << "Test for point (" << point.getX() << ", " << point.getY() << "): ";
		std::cout << "Outside the triangle" << std::endl;
	}
}