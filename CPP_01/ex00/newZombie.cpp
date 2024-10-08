/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 13:28:16 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Create and allocate newZombie in heap
Zombie* newZombie( std::string name ) {
	Zombie *newName = new Zombie(name);
	return (newName);
}
