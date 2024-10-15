/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:23:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/15 14:00:16 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"
#include "includes/Point.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << GREEN << "------ Print incrementation -------" << DEF << std::endl
			<< YELLOW << "   Original a: " << DEF << a << std::endl
			<< YELLOW << "Increment ++a: " << DEF << ++a << std::endl
			<< YELLOW << "   Original a: " << DEF << a << std::endl
			<< YELLOW << "Increment a++: " << DEF << a++ << std::endl
			<< YELLOW << "      Final a: " << DEF << a << std::endl << std::endl;

	std::cout << YELLOW << "Final b (5.05f * 2): " << DEF << b << std::endl << std::endl;
	
	std::cout << GREEN << "------ Print max -------" << DEF << std::endl
			<< YELLOW << "(a: " << a << " or b: " << b  << ") : " << DEF
			<< Fixed::max( a, b ) << std::endl << std::endl;

	Fixed c;
	printDecrementation(c);

	Fixed d(5.56f);
	Fixed e(3.2f);
	printArithmetic(d, e);
	printComparison(d, e);
	
	printMinMax(a, c);
 
    const Fixed f(4.0f);
    const Fixed g(1.5f);
    printConstMinMax(f, g);
}

void printDecrementation(Fixed &c) {
	std::cout << GREEN << "------ Print decrementation -------" << DEF << std::endl
		<< YELLOW << "   Print original c: " << DEF << c << std::endl
		<< YELLOW << "Print decrement --c: " << DEF << --c << std::endl
		<< YELLOW << "   Print original c: " << DEF << c << std::endl
		<< YELLOW << "Print decrement c--: " << DEF << c-- << std::endl
		<< YELLOW << "            Final c: " << DEF << c << std::endl << std::endl;
}

void printArithmetic(Fixed &d, Fixed &e) {
	std::cout << GREEN << "------ Arithmetic ------ " << DEF << std::endl;
	
	Fixed addition(d + e);
	std::cout << d << " + " << e << " = " << addition << std::endl;
	Fixed substration(d - e);
	std::cout << d << " - " << e << " = " << substration << std::endl;
	Fixed multiplication(d * e);
	std::cout << d << " * " << e << " = " << multiplication << std::endl;
	Fixed division(d / e);
	std::cout << d << " / " << e << " = " << division << std::endl << std::endl;
}

void printComparison(Fixed &d, Fixed &e) {
	std::cout << GREEN << "------ Comparison ------ " << DEF << std::endl;

	Fixed comparison1(d > e);
	std::cout << d << " > " << e << "  | " << comparison1 << std::endl;
	Fixed comparison2(d < e);
	std::cout << d << " < " << e << "  | " << comparison2 << std::endl;
	Fixed comparison3(d >= e);
	std::cout << d << " >= " << e << " | " << comparison3 << std::endl;
	Fixed comparison4(d <= e);
	std::cout << d << " <= " << e << " | " << comparison4 << std::endl;
	Fixed comparison5(d == e);
	std::cout << d << " == " << e << " | " << comparison5 << std::endl;
	Fixed comparison6(d != e);
	std::cout << d << " != " << e << " | " << comparison6 << std::endl << std::endl;
}

void printMinMax(Fixed &a, Fixed &c) {
	std::cout << GREEN << "------ Return min/max ------ " << DEF << std::endl;
    std::cout << "non-const a: " << a << std::endl
    		<< "non-const c: " << c << std::endl
    		<< "Min( a, c ): " << Fixed::min(a, c) << std::endl
    		<< "Max( a, c ): " << Fixed::max(a, c) << std::endl << std::endl;
}

void printConstMinMax(const Fixed &f, const Fixed &g) {
	std::cout << "const f  : " << f << std::endl
    		<< "const g  : " << g << std::endl
    		<< "Min(f, g): " << Fixed::min(f, g) << std::endl
    		<< "Max(f, g): " << Fixed::max(f, g) << std::endl;
}