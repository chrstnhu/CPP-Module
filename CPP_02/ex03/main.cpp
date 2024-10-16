/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:05:38 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/16 17:38:29 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"
#include "includes/Point.hpp"

static void print_bsp( Point &a, Point &b, Point &c, Point point );

int main(void) {
	// Triangle coordinates
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	std::cout << "Triangle coordinates: "
			<< "a(" << a.getX() << ", " << a.getY() << ") | "
			<< "b(" << b.getX() << ", " << b.getY() << ") | "
			<< "c(" << c.getX() << ", " << c.getY() << ")" << std::endl << std::endl;

	//Points
	Point p1(1, 1);
	Point p2(1.658f, 2.5f);
	Point p3(-2 + 2, 0);
	Point p4(0, -2 * -2);
	Point p5(4.6f, 0.2f);
	Point p6(1.6f / 2.0f, -3.2f);

	print_bsp(a, b, c, p1);
	print_bsp(a, b, c, p2);
	print_bsp(a, b, c, p3);
	print_bsp(a, b, c, p4);
	print_bsp(a, b, c, p5);
	print_bsp(a, b, c, p6);
	return 0;
}

static void print_bsp( Point &a, Point &b, Point &c, Point point )
{
	if (bsp(a, b, c, point)) {
		std::cout << "Test for point (" << point.getX() << ", " << point.getY() << "): ";
		std::cout << "Inside the triangle" << std::endl;
	} else {
		std::cout << "Test for point (" << point.getX() << ", " << point.getY() << "): ";
		std::cout << "Outside the triangle" << std::endl;
	}
}