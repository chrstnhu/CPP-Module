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

void printColorWithoutEndl(const std::string &msg, const std::string &color) {
	std::cout << color << msg << DEF;
}

// Swap int 
void swapInt(int &a, int &b) {
	std::cout << YELLOW << "Before swap: " << DEF
			 << "a = " << a << ", b = " << b << std::endl;
	
	swap( a, b );

	std::cout << YELLOW << "After swap: " << DEF
			 << "a = " << a << ", b = " << b << std::endl << std::endl;

	std::cout << YELLOW << "Compare values and return minimum" << DEF << std::endl
			 << "a = " << a << ", b = " << b << std::endl
			 << "return minimum: " << ::min( a, b ) << std::endl;

	std::cout << YELLOW << "Compare values and return maximum" << DEF << std::endl
			 << "a = " << a << ", b = " << b << std::endl
			 << "return maximum: " << ::max( a, b ) << std::endl << std::endl;
}

// Swap string
void swapString(std::string &c, std::string &d) {
	std::cout << YELLOW << "Before swap: " << DEF
			<< "c = " << c << ", d = " << d << std::endl;
	
	swap(c, d);
	
	std::cout << YELLOW << " After swap: " << DEF 
			<< "c = " << c << ", d = " << d << std::endl << std::endl;
	

	std::cout << YELLOW << "Compare values and return minimum" << DEF << std::endl
			<< "c = " << c << ", d = " << d << std::endl
			<< "return minimum: " << ::min( c, d ) << std::endl << std::endl;

	std::cout << YELLOW << "Compare values and return maximum" << DEF << std::endl
			<< "c = " << c << ", d = " << d << std::endl
			<< "return maximum: " << ::max( c, d ) << std::endl << std::endl;
}

// Swap float
void swapFloat(float &e, float &f) {
	std::cout << YELLOW << "Before swap: " << DEF
			<< "e = " << e << ", f = " << f << std::endl;

	swap(e, f);

	std::cout << YELLOW << " After swap: " << DEF 
			<< "e = " << e << ", f = " << f << std::endl << std::endl;
	
	std::cout << YELLOW << "Compare values and return minimum" << DEF << std::endl
			<< "e = " << e << ", f = " << f << std::endl
			<< "return minimum: " << ::min( e, f ) << std::endl << std::endl;

	std::cout << YELLOW << "Compare values and return maximum" << DEF << std::endl
			<< "e = " << e << ", f = " << f << std::endl
			<< "return maximum: " << ::max( e, f ) << std::endl << std::endl;
}

// Swap pointeur
void swapPointer (float *ptr_e, float *ptr_a) {
	std::cout << YELLOW << "Before swap: " << DEF
			<< "ptr_e = " << *ptr_e << ", ptr_a = " << *ptr_a << std::endl;

	swap(*ptr_e, *ptr_a);
	
	std::cout << YELLOW << " After swap: " << DEF 
			<< "ptr_e = " << *ptr_e << ", ptr_a = " << *ptr_a << std::endl << std::endl;

	std::cout << YELLOW << "Compare values and return minimum" << DEF << std::endl
			<< "ptr_e = " << *ptr_e << ", ptr_a = " << *ptr_a << std::endl
			<< "return minimum: " << ::min( *ptr_e, *ptr_a ) << std::endl << std::endl;

	std::cout << YELLOW << "Compare values and return maximum" << DEF << std::endl
			<< "ptr_e = " << *ptr_e << ", ptr_a = " << *ptr_a << std::endl
			<< "return maximum: " << ::max( *ptr_e, *ptr_a ) << std::endl << std::endl;
}


int main( void ) {
	// Swap int ------------------------------------------------------------------------
	printColor("========= Swap int =========", GREEN);
	int a = 2;
	int b = 3;

	swapInt(a, b);


	// Swap string ----------------------------------------------------------------------
	printColor("========= Swap string =========", GREEN);

	std::string c = "chaine1";
	std::string d = "chaine2";

	swapString(c, d);


	// Swap float -----------------------------------------------------------------------
	printColor("========= Swap float =========", GREEN);
	float e = 5.356f;
	float f = -85.14f;

	swapFloat(e, f);


	// Swap pointeur -----------------------------------------------------------------------
	printColor("========= Swap pointeur =========", GREEN);
	float *ptr_e = &e;
	float a_to_float = static_cast<float>(a);
	float *ptr_a = &a_to_float;

	swapPointer(ptr_e, ptr_a);
	return 0;
}