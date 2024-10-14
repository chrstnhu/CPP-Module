/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:23:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/14 19:07:41 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << YELLOW << "    Print original a: " << DEF << a << std::endl
			<< YELLOW << "Print increment ++a: " << DEF << ++a << std::endl
			<< YELLOW << "    Print original a: " << DEF << a << std::endl
			<< YELLOW << "Print increment a++: " << DEF << a++ << std::endl
			<< YELLOW << "          Final a++: " << DEF << a << std::endl;

	std::cout << YELLOW << "          Final b++: " << DEF << b << std::endl << std::endl;
	
	std::cout << YELLOW << "------ Print max -------" << DEF << std::endl
			<< YELLOW << "(a: " << a << " or b: " << b  << ") : " << DEF << Fixed::max( a, b ) << std::endl;
	
	Fixed c;
	std::cout << std::endl << YELLOW << "    Print original c: " << DEF << c << std::endl
			<< YELLOW << "Print decrement --c: " << DEF << --c << std::endl
			<< YELLOW << "    Print original c: " << DEF << c << std::endl
			<< YELLOW << "Print decrement c--: " << DEF << c-- << std::endl
			<< YELLOW << "          Final c++: " << DEF << c << std::endl;

	float float_a = 5.56568f;
	float float_b = 3.2;
	std::cout << std::endl << YELLOW << "------ Arithmetic ------ " << DEF << std::endl
			<< float_a << " + " << float_b << " = " << (float_a + float_b) << std::endl
			<< float_a << " - " << float_b << " = " << (float_a - float_b) << std::endl
			<< float_a << " * " << float_b << " = " << (float_a * float_b) << std::endl
			<< float_a << " / " << float_b << " = " << (float_a / float_b) << std::endl;

	std::cout << std::endl << YELLOW << "------ Comparison ------ " << DEF << std::endl
			<< float_a << " > " << float_b << "  | " << (float_a > float_b) << std::endl
			<< float_a << " < " << float_b << "  | " << (float_a < float_b) << std::endl
			<< float_a << " >= " << float_b << " | " << (float_a >= float_b) << std::endl
			<< float_a << " <= " << float_b << " | " << (float_a <= float_b) << std::endl
			<< float_a << " == " << float_b << " | " << (float_a == float_b) << std::endl
			<< float_a << " != " << float_b << " | " << (float_a != float_b) << std::endl;

	std::cout << std::endl << YELLOW << "------ Return min/max ------ " << DEF << std::endl;
    std::cout << "a: " << a << std::endl
    		<< "c: " << c << std::endl
    		<< "Min(a, c): " << Fixed::min(a, c) << std::endl
    		<< "Max(a, c): " << Fixed::max(a, c) << std::endl;

    const Fixed d(4.0f);
    const Fixed e(1.5f);
    std::cout << "d: " << d << std::endl
    		<< "e: " << e << std::endl
    		<< "Min(d, e): " << Fixed::min(d, e) << std::endl
    		<< "Max(d, e): " << Fixed::max(d, e) << std::endl;
}