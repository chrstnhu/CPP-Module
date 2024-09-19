/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/19 12:34:59 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() {
	std::cout << GREEN << "Construct zombie" << DEF << std::endl;
	return ;
}

// Constructor : initialize zombie name
Zombie::Zombie( std::string name ) {
	this->_name = name;
	return ;
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

// Announce
void Zombie::announce( void ) {
	if (_name.empty()) {
        std::cout << "Unnamed: BraiiiiiiinnnzzzZ..." << std::endl;
    }
	else {
        std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
}