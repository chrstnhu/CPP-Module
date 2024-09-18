/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/18 17:11:14 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int i = 0;
	const int nb = 5;
	std::string names[nb] = {"Foo", "New", "John"};
	
	Zombie *zombie;

	std::cout << YELLOW << " ---Zombie Horde--- " << DEF << std::endl;	
	
	while (i < nb) {
		zombie = zombieHorde(1, names[i]);
		zombie[0].announce();
		delete [](zombie);
		i++;
	}
    return (0);
}

