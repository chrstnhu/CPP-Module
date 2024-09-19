/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/19 10:10:17 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() {
	std::cout << GREEN << "Construct zombie" << DEF << std::endl;
}

// Constructor : initialize zombie name
Zombie::Zombie(std::string _name) : name(_name) {}

// Destructor
Zombie::~Zombie() {
	if (name.empty()) {
        std::cout << GREEN << "Destroy unamed zombie" << DEF << std::endl;
    }
	else {
    	std::cout << GREEN << "Destroy " << get_name() << " zombie" << DEF << std::endl;
	}
}

// Set name of zombie
void Zombie::set_name(const std::string _name) {
    name = _name;
}

// Get name of zombie
std::string Zombie::get_name() const {
    return name;
}

// Announce
void Zombie::announce(void) {
	if (name.empty()) {
        std::cout << "Unnamed: BraiiiiiiinnnzzzZ..." << std::endl;
    }
	else {
        std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
}