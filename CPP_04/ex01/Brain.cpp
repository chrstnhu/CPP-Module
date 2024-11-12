/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:07:24 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/12 11:11:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Default constructor
Brain::Brain() {
	std::cout << GREEN << "Default construct brain" << DEF << std::endl;
}

// Copy constructor
Brain::Brain(const Brain &other) {
	std::cout << GREEN << "Copy constructor brain" << DEF << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++) {
		this->ideas[i] = other.ideas[i];
	}
}

// Destructor
Brain::~Brain() {
	std::cout << GREEN << "Destructor brain" << DEF << std::endl;
}

// Copy assignement
Brain &Brain::operator=(const Brain &other) {
	std::cout << GREEN << "Copy assignement brain" << DEF << std::endl;
	if (this != &other)
	{
		for(int i = 0; i < MAX_IDEAS; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}