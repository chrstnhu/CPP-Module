/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:12:26 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/23 17:19:30 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal() {
	std::cout << GREEN << "Default constructor animal" << DEF << std::endl;
}

// Constructor with parameters
Animal::Animal(std::string type) : _type(type) {
	std::cout << GREEN << "Constructor animal" << DEF << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other) {
	std::cout << GREEN << "Copy constructor animal" << DEF << std::endl;
}
		
// Destructor
Animal::~Animal() {
	std::cout << GREEN << "Destructor animal" << DEF << std::endl;
}

// Copy assignement
Animal &Animal::operator=(const Animal &other) {
	std::cout << GREEN << "Copy assignement animal" << DEF << std::endl;
}