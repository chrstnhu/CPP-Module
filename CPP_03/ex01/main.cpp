/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:27:07 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/04 12:26:22 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

static void printIdentity(ClapTrap &Clap);
static void ftAttack(ClapTrap &ClapTrap, ScavTrap &ScavTrap);
static void ftTakeDamage(ClapTrap &ClapTrap, ScavTrap &ScavTrap);
static void ftRepair(ClapTrap &ClapTrap, ScavTrap &ScavTrap);

int main () {
	ClapTrap ClapTrap("Bob");
	ScavTrap ScavTrap;

	ftAttack(ClapTrap, ScavTrap);
	ftTakeDamage(ClapTrap, ScavTrap);
	ftRepair(ClapTrap, ScavTrap);

	// Gate keeper mode
	std::cout << std::endl << "======================= Guard Gate =======================" << std::endl;
	ScavTrap.guardGate();
}

static void ftAttack(ClapTrap &ClapTrap, ScavTrap &ScavTrap) {
	std::cout << std::endl << "======================= Attack =======================" << std::endl;
	ClapTrap.attack("Someone");
	ClapTrap.attack("Zombie");
	ClapTrap.attack("Fish");
	printIdentity(ClapTrap);
	
	ScavTrap.attack("Computer");
	printIdentity(ScavTrap);
}

static void ftTakeDamage(ClapTrap &ClapTrap, ScavTrap &ScavTrap) {
	std::cout << std::endl << "======================= Take Damage =======================" << std::endl;
	ClapTrap.takeDamage(10);
	printIdentity(ClapTrap);
	ClapTrap.takeDamage(3);
	printIdentity(ClapTrap);
	
	ScavTrap.takeDamage(60);
	printIdentity(ScavTrap);
	ScavTrap.takeDamage(2);
	printIdentity(ScavTrap);
}

static void ftRepair(ClapTrap &ClapTrap, ScavTrap &ScavTrap) {
	std::cout << std::endl << "======================= Repair =======================" << std::endl;
	ClapTrap.beRepaired(7);
	printIdentity(ClapTrap);
	
	ScavTrap.beRepaired(46);
	printIdentity(ScavTrap);
	ScavTrap.beRepaired(4);
	printIdentity(ScavTrap);
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