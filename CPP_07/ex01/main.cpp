/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:42:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/11 14:38:12 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void printColor(const std::string &msg, const std::string &color) {
    std::cout << std::endl << color << msg << DEF << std::endl;
}

// Test with int
void printInt(int &element) {
	std::cout << element << " ";
	std::cout << "Multiply by 2: " << element * 2 << std::endl;
}

// Test with char
void printChar(char &element) {
	std::cout << element << ", ";
}

// Test with string
void printString(std::string &element) {
	std::cout << element << " ";
}

// Test with pointeur
void printIntPtr(int * &element) {
	std::cout << *element << " | " << "Address: " << element << std::endl;
}


int main( void ) {
	// Test with int -------------------------------------------
	printColor("--> Print int", YELLOW);
	int array[] = {1, 2, 3, 4, 5};
	int len = 5;

	iter(array, len, printInt);
	
	// Test with char -------------------------------------------
	printColor("\n--> Print char", YELLOW);
	char array2[] = {'a', 'b', 'c', 'd', 'e'};
	int len2 = 10;
	iter(array2, len2, printChar);
	std::cout << "|" << std::endl;
	
	// Test with string -----------------------------------------
	printColor("\n--> Print string", YELLOW);
	std::string array3[] = {"Hello", "World", "42", "Paris", "France"};
	int len3 = 2;
	iter(array3, len3, printString);
	
	// Test with pointeur -----------------------------------------
	printColor("\n--> Print pointeur", YELLOW);
	int a = 42;
	int b = -42;
	int c = 0;
	
	int *array4[] = {&a, &b, &c};
	int len4 = 3;
	iter(array4, len4, printIntPtr);

	return 0;
}
