/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:27:07 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/22 11:55:06 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

static void printIdentity(ClapTrap &Clap);
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
	printIdentity(DiamondTrap);
	DiamondTrap.whoAmI();
}

static void ftAttack(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap, DiamondTrap &DiamondTrap) {
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

	DiamondTrap.attack("rock");
	printIdentity(DiamondTrap);
}

static void ftTakeDamage(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap, DiamondTrap &DiamondTrap) {
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

	DiamondTrap.takeDamage(80);
	printIdentity(DiamondTrap);
}

static void ftRepair(ClapTrap &ClapTrap, ScavTrap &ScavTrap, FragTrap &FragTrap, DiamondTrap &DiamondTrap) {
	std::cout << std::endl << "======================= Repair =======================" << std::endl;
	ClapTrap.beRepaired(7);
	printIdentity(ClapTrap);
	
	ScavTrap.beRepaired(46);
	printIdentity(ScavTrap);
	ScavTrap.beRepaired(4);
	printIdentity(ScavTrap);

	FragTrap.beRepaired(100);
	printIdentity(FragTrap);

	DiamondTrap.beRepaired(50);
	printIdentity(DiamondTrap);
}

static void printIdentity(ClapTrap &Clap)
{
	if (Clap.getHitPoint() != 0)
	{
		std::cout << GREEN << Clap.getName() << DEF
			<< " - Hit point(s): " 
			<< YELLOW << Clap.getHitPoint() << DEF
			<< ", energy point: "
			<< YELLOW << Clap.getEnergyPoint() << DEF
			<< ", attack damage: "
			<< YELLOW << Clap.getAttackDamage() << DEF << std::endl;
	}
}
