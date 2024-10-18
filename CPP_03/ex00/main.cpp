/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:27:07 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/18 16:37:40 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

static void printIdentity(ClapTrap &Clap);

int main () {
	ClapTrap Clap1("Bob");
	ClapTrap Clap2;

	// Attack
	Clap1.attack(Clap2.getName());
	Clap1.attack(Clap2.getName());
	Clap1.attack(Clap2.getName());
	printIdentity(Clap1);
	
	Clap2.attack(Clap1.getName());
	printIdentity(Clap2);

	// Clap take damage
	Clap1.takeDamage(0);
	printIdentity(Clap1);
	Clap1.takeDamage(8);
	printIdentity(Clap1);
	
	Clap2.takeDamage(20);
	printIdentity(Clap2);
	Clap2.takeDamage(2);
	printIdentity(Clap2);
	
	// Clap2 repair
	Clap1.beRepaired(20);
	printIdentity(Clap1);
	Clap1.beRepaired(7);
	printIdentity(Clap1);
	
	Clap2.beRepaired(4);
	printIdentity(Clap2);

	
}

static void printIdentity(ClapTrap &Clap)
{
	std::cout << GREEN << Clap.getName() << DEF
		<< " - Hit point(s): " 
		<< YELLOW << Clap.getHitPoint() << DEF
		<< ", energy point: "
		<< YELLOW << Clap.getEnergyPoint() << DEF << std::endl;
}