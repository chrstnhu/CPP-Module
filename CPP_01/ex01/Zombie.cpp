/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/19 12:38:53 by chrhu            ###   ########.fr       */
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
}

// Destructor
Zombie::~Zombie() {
	if (this->_name.empty()) {
        std::cout << GREEN << "Destroy unamed zombie" << DEF << std::endl;
    }
	else {
    	std::cout << GREEN << "Destroy " << this->_name << " zombie" << DEF << std::endl;
	}
	return ;
}

// Set name of zombie
void Zombie::setName( const std::string name ) {
    _name = name;
}

// Announce
void Zombie::announce( void ) {
	if (this->_name.empty()) {
        std::cout << "Unnamed: BraiiiiiiinnnzzzZ..." << std::endl;
    }
	else {
        std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
}