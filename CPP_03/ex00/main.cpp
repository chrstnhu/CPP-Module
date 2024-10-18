/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:27:07 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/18 18:30:10 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void printIdentity(ClapTrap &Clap);

int main () {
	ClapTrap ClapTrack("Bob");
	ClapTrap ClapTrap;

	// Attack
	ClapTrack.attack("Someone");
	ClapTrack.attack("Zombie");
	ClapTrack.attack("Fish");
	printIdentity(ClapTrack);
	
	ClapTrap.attack("Computer");
	printIdentity(ClapTrap);

	// Take damage
	ClapTrack.takeDamage(10);
	printIdentity(ClapTrack);
	ClapTrack.takeDamage(3);
	printIdentity(ClapTrack);
	
	ClapTrap.takeDamage(20);
	printIdentity(ClapTrap);
	ClapTrap.takeDamage(2);
	printIdentity(ClapTrap);
	
	// Repair
	ClapTrack.beRepaired(7);
	printIdentity(ClapTrack);
	
	ClapTrap.beRepaired(20);
	printIdentity(ClapTrap);
	ClapTrap.beRepaired(4);
	printIdentity(ClapTrap);

	
}

static void printIdentity(ClapTrap &Clap)
{
	if (Clap.getHitPoint() != 0)
	{
		std::cout << GREEN << Clap.getName() << DEF
			<< " - Hit point(s): " 
			<< YELLOW << Clap.getHitPoint() << DEF
			<< ", energy point: "
			<< YELLOW << Clap.getEnergyPoint() << DEF << std::endl;
	}
}