/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:27:07 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/18 18:41:20 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void printIdentity(ClapTrap &Clap);
static void ftAttack(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap);
static void ftTakeDamage(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap);
static void ftRepair(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap);

int main () {
	ClapTrap ClapTrap("Bob");
	ScavTrap ScavTrap;
	FragTrap FragTrap("Knight");

	ftAttack(ClapTrap, ScavTrap, FragTrap);
	ftTakeDamage(ClapTrap, ScavTrap, FragTrap);
	ftRepair(ClapTrap, ScavTrap, FragTrap);

	// Gate keeper mode
	std::cout << std::endl << "======================= Guard Gate =======================" << std::endl;
	ScavTrap.guardGate();

	// High Five
	std::cout << std::endl << "======================= High Five =======================" << std::endl;
	FragTrap.highFivesGuys();
}

static void ftAttack(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap) {
	std::cout << std::endl << "======================= Attack =======================" << std::endl;
	ClapTrap.attack("Someone");
	ClapTrap.attack("Zombie");
	ClapTrap.attack("Fish");
	printIdentity(ClapTrap);
	
	ScavTrap.attack("Computer");
	printIdentity(ScavTrap);

	for (int i = 0; i < 5; i++)
		FragTrap.attack("robot");
	printIdentity(FragTrap);
}

static void ftTakeDamage(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap) {
	std::cout << std::endl << "======================= Take Damage =======================" << std::endl;
	ClapTrap.takeDamage(10);
	printIdentity(ClapTrap);
	ClapTrap.takeDamage(3);
	printIdentity(ClapTrap);
	
	ScavTrap.takeDamage(60);
	printIdentity(ScavTrap);
	ScavTrap.takeDamage(2);
	printIdentity(ScavTrap);

	FragTrap.takeDamage(95);
	printIdentity(FragTrap);
}

static void ftRepair(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap) {
	std::cout << std::endl << "======================= Repair =======================" << std::endl;
	ClapTrap.beRepaired(7);
	printIdentity(ClapTrap);
	
	ScavTrap.beRepaired(46);
	printIdentity(ScavTrap);
	ScavTrap.beRepaired(4);
	printIdentity(ScavTrap);

	FragTrap.beRepaired(100);
	printIdentity(FragTrap);
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
