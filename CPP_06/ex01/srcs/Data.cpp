/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:35:43 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 12:53:36 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// Default constructor
Data::Data() : _input("Nothing to print") {
	std::cout << ITALICGREEN << "Data Default constructor" << DEF << std::endl;
}

// Constructor with parameter
Data::Data(std::string input) : _input(input) {
	std::cout << ITALICGREEN << "Data Constructor with parameter" << DEF << std::endl;
}

// Copy constructor
Data::Data(const Data &other) {
	std::cout << ITALICGREEN << "Data Copy constructor" << DEF << std::endl;
	_input = other._input;
}

// Destructor
Data::~Data() {
	std::cout << ITALICGREEN << "Data Destructor" << DEF << std::endl;
}

//Copy assignement operator
Data &Data::operator=(const Data &other) {
	std::cout << ITALICGREEN << "Data Copy assignement operator" << DEF << std::endl;
	if (this == &other) {
		_input = other._input;
	}
	return (*this);
}


// Getters and setters
void Data::setInput(std::string input) {
	_input = input;
}

std::string Data::getInput() const {
	return _input;
}
