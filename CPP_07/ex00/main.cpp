/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/11 14:46:03 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void printColor(const std::string &msg, const std::string &color) {
    std::cout << std::endl << color << msg << DEF << std::endl;
}

int main( void ) {
	int a = 2;
	int b = 3;

	// Swap int ------------------------------------------------------------------------
	printColor("--------- Swap int ----------", YELLOW);
	std::cout << YELLOW<< "Before swap: " << DEF
			<< "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << YELLOW << " After swap: " << DEF 
			<< "a = " << a << ", b = " << b << std::endl;
	
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;

	// Swap string ----------------------------------------------------------------------
	std::string c = "chaine1";
	std::string d = "chaine2";

	printColor("--------- Swap string ----------", YELLOW);
	std::cout << YELLOW << "Before swap: " << DEF
			<< "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << YELLOW << " After swap: " << DEF 
			<< "c = " << c << ", d = " << d << std::endl;
	
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;

	// Swap float -----------------------------------------------------------------------
	float e = 5.356f;
	float f = -85.14f;

	printColor("--------- Swap float ----------", YELLOW);
	std::cout << YELLOW << "Before swap: " << DEF
			<< "e = " << e << ", f = " << f << std::endl;
	::swap(e, f);
	std::cout << YELLOW << " After swap: " << DEF 
			<< "e = " << e << ", f = " << f << std::endl;
	
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl << std::endl;

	// Swap pointeur -----------------------------------------------------------------------
	float *ptr_e = &e;
	float a_to_float = static_cast<float>(a);
	float *ptr_a = &a_to_float;

	printColor("--------- Swap pointeur ----------", YELLOW);
	std::cout << YELLOW << "Before swap: " << DEF
			<< "ptr_e = " << *ptr_e << ", ptr_a = " << *ptr_a << std::endl;
	::swap(*ptr_e, *ptr_a);
	std::cout << YELLOW << " After swap: " << DEF 
			<< "ptr_e = " << *ptr_e << ", ptr_a = " << *ptr_a << std::endl;
	
	std::cout << "min( ptr_e, ptr_a ) = " << ::min( *ptr_e, *ptr_a ) << std::endl;
	std::cout << "max( ptr_e, ptr_a ) = " << ::max( *ptr_e, *ptr_a ) << std::endl << std::endl;
	return 0;
}