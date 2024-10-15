/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:23:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/15 17:21:14 by chrhu            ###   ########.fr       */
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

	//Points
    Point p1(1, 1);   // Inside
    Point p2(6.6, 1);   // Outside
    Point p3(0, 0);   // On the edge
    Point p4(2, 0);   // On the edge
	Point p5(1.658, 2.5);   // Inside;

	std::cout << "Test pour point (1, 1): ";
    print_bsp(a, b, c, p1);
	std::cout << "Test pour point (6.6, 1): ";
	print_bsp(a, b, c, p2);
	std::cout << "Test pour point (0, 0): ";
	print_bsp(a, b, c, p3);
	std::cout << "Test pour point (2, 0): ";
	print_bsp(a, b, c, p4);
	std::cout << "Test pour point (1.658, 2.5): ";
	print_bsp(a, b, c, p5);
    return 0;
}

static void print_bsp(Point &a, Point &b, Point &c, Point point)
{
	if (bsp(a, b, c, point)) {
        std::cout << "À l'intérieur" << std::endl;
    } else {
        std::cout << "À l'extérieur" << std::endl;
    }
}