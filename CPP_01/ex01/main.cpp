/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 16:02:16 by chrhu            ###   ########.fr       */
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

    const int nb = 5; 
    std::string names[nb] = {"Foo", "New", "John"};
    Zombie** zombieHordes = new Zombie*[nb];

	std::cout << YELLOW << " ---Zombie Horde--- " << DEF << std::endl;    
	for (int i = 0 ; i < nb ; i++)
    {
        zombieHordes[i] = zombieHorde(1, names[i]);
        zombieHordes[i][0].announce();
    }

    for (int j = 0; j < nb; j++) {
        delete[] zombieHordes[j];
    }
    delete[] zombieHordes;

    return (0);
}
