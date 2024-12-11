/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/11 14:08:03 by chrhu            ###   ########.fr       */
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
		std::cout << "array[" << x << "] = " << array[x] << std::endl;
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
		std::cout << "arrayCopy[" << x << "] = " << arrayCopy[x] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception catch: " << e.what() << DEF << std::endl;
	}

	// Test string array
	printColor("--> Print string array", YELLOW);
	Array<std::string> arrayString(3);
	size = arrayString.size();
	try {
		arrayString.add("Hello", 0);
		arrayString.add("World", 1);
		arrayString.add("42", 2);
		for (int i = 0; i < size; ++i) {
			std::cout << "arrayString[" << i << "] = " << arrayString[i] << std::endl;
		}
		// overload array
		arrayString.add("Paris", 3);
		arrayString.add("France", 2);
		for (int i = 0; i < size; ++i) {
			std::cout << "arrayString[" << i << "] = " << arrayString[i] << std::endl;
		}


	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception catch: " << e.what() << DEF << std::endl;
	}
	return 0;
}