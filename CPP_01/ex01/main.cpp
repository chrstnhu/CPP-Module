/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/05 14:31:25 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av) {
	(void)ac;
	if (av[1] != NULL)
	{
		std::cout << YELLOW << " Usage : ./zombieHorde " << DEF << std::endl;
		return (1);
	}

	int i = 0;
	const int nb = 5;
	std::string names[nb] = {"Foo", "New", "John"};
	
	Zombie *zombie;

	std::cout << YELLOW << " ---Zombie Horde--- " << DEF << std::endl;	
	while (i < nb)
	{
		zombie = zombieHorde(1, names[i]);
		zombie[0].announce();
		delete [](zombie);
		i++;
	}
    return (0);
}

