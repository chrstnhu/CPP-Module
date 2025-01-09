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

// Test subject main
void subjectMain() {
	int *a = new int(42);

	std::cout << "a = " << *a << std::endl;

	delete a;
}

// Test empty array
void emptyArrayTest() {
	try {
		Array<int> emptyArray;
		std::cout << "emptyArray.size() = " << emptyArray.size() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << RED << "Exception catch: " << e.what() << DEF << std::endl;
	}
}

// Test array with size and initialise random values
void arrayIntTest() {
	Array<int> array(5);
	int size = array.size();

	// Fill array with random values
	for (int i = 0; i < size; ++i) {
		array[i] = rand() % 100;
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}

	try {

		int x = rand() % 10;
		std::cout << YELLOW << "x = " << x << DEF << std::endl;
		std::cout << "array[" << x << "] = " << array[x] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception catch: " << e.what() << DEF << std::endl;
	}

	// Copy constructor test
	printColor("=== Print copy constructor array ====", YELLOW);
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
}

// Test string array
void arrayStringTest() {
	Array<std::string> arrayString(3);
	int size = arrayString.size();

	try {
		arrayString.add("Hello", 0);
		arrayString.add("World", 1);
		arrayString.add("42", 2);
		for (int i = 0; i < size; ++i) {
			std::cout << "arrayString[" << i << "] = " << arrayString[i] << std::endl;
		}
		// overload array
		std::cout << std::endl << "--> Add array" << std::endl;
		arrayString.add("Paris", 3);
		arrayString.add("France", 2);
		for (int i = 0; i < size; ++i) {
			std::cout << "arrayString[" << i << "] = " << arrayString[i] << std::endl;
		}


	}
	catch (std::exception &e) {
		std::cerr << RED << "Exception catch: " << e.what() << DEF << std::endl;
	}
}

int main( void ) {
	srand(time(NULL));

	// Subject main test
	printColor("==== Subject test ====", YELLOW);
	subjectMain();


	// Empty array test
	printColor("==== Empty array test ====", YELLOW);
	emptyArrayTest();


	// Test array with size and initialise random values
	printColor("==== Array with size and random value ====", YELLOW);
	arrayIntTest();


	// Test string array
	printColor("=== Print string array ===", YELLOW);
	arrayStringTest();

	return 0;
}