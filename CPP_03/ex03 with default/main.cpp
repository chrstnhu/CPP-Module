/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:27:07 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/05 11:52:41 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

static void printIdentity(ClapTrap &Clap, DiamondTrap &DiamondTrap, int isDiamond);
static void ftAttack(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap, DiamondTrap &DiamondTrap);
static void ftTakeDamage(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap, DiamondTrap &DiamondTrap);
static void ftRepair(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap, DiamondTrap &DiamondTrap);

int main () {
	ClapTrap ClapTrap("Bob");
	ScavTrap ScavTrap;
	FragTrap FragTrap("Knight");
	DiamondTrap DiamondTrap("Diamond");

	ftAttack(ClapTrap, ScavTrap, FragTrap, DiamondTrap);
	ftTakeDamage(ClapTrap, ScavTrap, FragTrap, DiamondTrap);
	ftRepair(ClapTrap, ScavTrap, FragTrap, DiamondTrap);

	// Gate keeper mode
	std::cout << std::endl << "======================= Guard Gate =======================" << std::endl;
	ScavTrap.guardGate();

	// High Five
	std::cout << std::endl << "======================= High Five =======================" << std::endl;
	FragTrap.highFivesGuys();

	// Diamond Trap
	std::cout << std::endl << "======================= Diamond trap =======================" << std::endl;
	std::cout << GREEN << "Name: " << DiamondTrap.getName() << DEF << std::endl;
	printIdentity(DiamondTrap, DiamondTrap, 1);
	DiamondTrap.guardGate();
	DiamondTrap.highFivesGuys();
	DiamondTrap.whoAmI();
}

static void ftAttack(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap, DiamondTrap &DiamondTrap) {
	std::cout << std::endl << "======================= Attack =======================" << std::endl;
	ClapTrap.attack("Someone");
	ClapTrap.attack("Zombie");
	ClapTrap.attack("Fish");
	printIdentity(ClapTrap, DiamondTrap, 0);
	
	ScavTrap.attack("Computer");
	printIdentity(ScavTrap, DiamondTrap, 0);

	for (int i = 0; i < 5; i++)
		FragTrap.attack("robot");
	printIdentity(FragTrap, DiamondTrap, 0);

	DiamondTrap.attack("rock");
	printIdentity(DiamondTrap, DiamondTrap, 1);
}

static void ftTakeDamage(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap, DiamondTrap &DiamondTrap) {
	std::cout << std::endl << "======================= Take Damage =======================" << std::endl;
	ClapTrap.takeDamage(10);
	printIdentity(ClapTrap, DiamondTrap, 0);
	ClapTrap.takeDamage(3);
	printIdentity(ClapTrap, DiamondTrap, 0);
	
	ScavTrap.takeDamage(60);
	printIdentity(ScavTrap, DiamondTrap, 0);
	ScavTrap.takeDamage(2);
	printIdentity(ScavTrap, DiamondTrap, 0);

	FragTrap.takeDamage(95);
	printIdentity(FragTrap, DiamondTrap, 0);

	DiamondTrap.takeDamage(80);
	printIdentity(DiamondTrap, DiamondTrap, 1);
}

static void ftRepair(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap, DiamondTrap &DiamondTrap) {
	std::cout << std::endl << "======================= Repair =======================" << std::endl;
	ClapTrap.beRepaired(7);
	printIdentity(ClapTrap, DiamondTrap, 0);
	
	ScavTrap.beRepaired(46);
	printIdentity(ScavTrap, DiamondTrap, 0);
	ScavTrap.beRepaired(4);
	printIdentity(ScavTrap, DiamondTrap, 0);

	FragTrap.beRepaired(100);
	printIdentity(FragTrap, DiamondTrap, 0);

	DiamondTrap.beRepaired(50);
	printIdentity(DiamondTrap, DiamondTrap, 1);
}

static void printIdentity(ClapTrap &Clap, DiamondTrap &DiamondTrap, int isDiamond)
{
	if (Clap.getHitPoint() != 0)
	{
		if (isDiamond)
			std::cout << GREEN << DiamondTrap.getName() << DEF;
		else
			std::cout << GREEN << Clap.getName() << DEF;
		std::cout << " - Hit point(s): " 
			<< YELLOW << Clap.getHitPoint() << DEF
			<< ", energy point: "
			<< YELLOW << Clap.getEnergyPoint() << DEF
			<< ", attack damage: "
			<< YELLOW << Clap.getAttackDamage() << DEF << std::endl;
	}
}
