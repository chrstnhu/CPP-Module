/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/19 12:39:30 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Create and allocate N Zombie
Zombie* zombieHorde( int N, std::string name ) {
	int i = 0;

	if (N <= 0)
		return (0);

	Zombie *newHorde = new Zombie[N];
	while (i < N) {
		newHorde[i].setName(name);
		i++;
	}
	return (newHorde);
}
