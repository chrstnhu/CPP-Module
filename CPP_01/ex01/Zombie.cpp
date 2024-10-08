/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 13:37:40 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() {
	std::cout << GREEN << "Construct zombie" << DEF << std::endl;
	return ;
}

// Constructor : initialize zombie name
Zombie::Zombie(std::string name) : _name(name) {
	std::cout << GREEN << "Construct zombie with name" << DEF << std::endl;
	return ;
}

// Destructor
Zombie::~Zombie() {
	if (_name.empty()) {
        std::cout << GREEN << "Destroy unamed zombie" << DEF << std::endl;
    }
	else {
    	std::cout << GREEN << "Destroy " << _name << " zombie" << DEF << std::endl;
	}
	return ;
}

// Set name of zombie
void Zombie::setName( const std::string name ) {
    _name = name;
}

// Announce
void Zombie::announce( void ) {
	if (_name.empty()) {
        std::cout << "Unnamed: BraiiiiiiinnnzzzZ..." << std::endl;
    }
	else {
        std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
}