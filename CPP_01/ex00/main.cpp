/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 13:56:27 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av) {

	(void)ac;
	if (av[1] != NULL)
	{
		std::cout << YELLOW << " Usage : ./zombie " << DEF << std::endl;
		return (1);
	}

	Zombie zombie1("Foo");
	Zombie zombie2;

	std::cout << YELLOW << " ---Announce itself--- " << DEF << std::endl;
    zombie1.announce();
	zombie2.announce();

	Zombie *newName;
	std::cout << YELLOW << " ---New Zombie--- " << DEF << std::endl;	
	newName = newZombie("New");
	newName->announce();
	delete (newName);
	
	std::cout << YELLOW << " ---Random Chump--- " << DEF << std::endl;
	randomChump("Random");

    return (0);
}

