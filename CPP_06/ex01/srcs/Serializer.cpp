/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:11:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 13:02:59 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

// Default constructor
Serializer::Serializer() {
	std::cout << ITALICGREEN << "Serializer Default constructor" << DEF << std::endl;
}

// Copy constructor
Serializer::Serializer(const Serializer &other) {
	std::cout << ITALICGREEN << "Serializer Copy constructor" << DEF << std::endl;
	*this = other;
}

// Destructor
Serializer::~Serializer() {
	std::cout << ITALICGREEN << "Serializer Destructor" << DEF << std::endl;
}

//Copy assignement operator
Serializer &Serializer::operator=(const Serializer &other) {
	std::cout << ITALICGREEN << "Serializer Copy assignement operator" << DEF << std::endl;
	if (this == &other) {
		*this = other;	
	}
	return (*this);
}

// Methods
uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
