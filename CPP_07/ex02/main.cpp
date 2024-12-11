/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/11 12:07:24 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void printColor(const std::string &msg, const std::string &color) {
    std::cout << std::endl << color << msg << DEF << std::endl;
}

int main( void ) {
	srand(time(NULL));

	// Subject main test
	printColor("--> Print int", YELLOW);
	int *a = new int(42);

	std::cout << "a = " << *a << std::endl;

	delete a;

	// Constructor test
	Array<int> array(5);
	int size = array.size();
	
	// Fill array
	for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
	// Try to access array index
	try {
		int x = rand() % 10;
		std::cout << YELLOW << "x = " << x << DEF << std::endl;
		std::cout << "array[x] = " << array[x] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception catch: " << e.what() << DEF << std::endl;
	}

	// Copy constructor test
	printColor("--> Print copy array", YELLOW);
	Array<int> arrayCopy(array);
	for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
		std::cout << "arrayCopy[" << i << "] = " << arrayCopy[i] << std::endl;
	}
	try {
		int x = rand() % 10;
		std::cout << YELLOW << "x = " << x << DEF << std::endl;
		std::cout << "arrayCopy[x] = " << arrayCopy[x] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception catch: " << e.what() << DEF << std::endl;
	}

	// Copy assignement test
	printColor("--> Print assignement array", YELLOW);
	Array<int> arrayAssignement(3);
	arrayAssignement = array;
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 100;
		std::cout << "arrayAssignement[" << i << "] = " << arrayAssignement[i] << std::endl;
	}
	try {
		int x = rand() % 10;
		std::cout << YELLOW << "x = " << x << DEF << std::endl;
		std::cout << "arrayAssignement[" << x << "] = " << arrayAssignement[x] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception catch: " << e.what() << DEF << std::endl;
	}
	return 0;
}