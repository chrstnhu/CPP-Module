/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:27:07 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/18 18:08:45 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void printIdentity(ClapTrap &Clap);

int main () {
	ClapTrap ClapTrack("Bob");
	ScavTrap ScavTrap;

	// Attack
	ClapTrack.attack("Someone");
	ClapTrack.attack("Zombie");
	ClapTrack.attack("Fish");
	printIdentity(ClapTrack);
	
	ScavTrap.attack("Computer");
	printIdentity(ScavTrap);

	// Take damage
	ClapTrack.takeDamage(10);
	printIdentity(ClapTrack);
	ClapTrack.takeDamage(3);
	printIdentity(ClapTrack);
	
	ScavTrap.takeDamage(60);
	printIdentity(ScavTrap);
	ScavTrap.takeDamage(2);
	printIdentity(ScavTrap);
	
	// Repair
	ClapTrack.beRepaired(7);
	printIdentity(ClapTrack);
	
	ScavTrap.beRepaired(46);
	printIdentity(ScavTrap);
	ScavTrap.beRepaired(4);
	printIdentity(ScavTrap);

	// Gate keeper mode
	ScavTrap.guardGate();
	
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