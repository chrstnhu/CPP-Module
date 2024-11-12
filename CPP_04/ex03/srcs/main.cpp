/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:58:46 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/12 13:46:50 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/AMateria.hpp"

static void unequipAndDelete(ICharacter *Character, int idx);

void subjectExemple() {
	std::cout << YELLOW << "===== Subject exemple =====" << DEF << std::endl;
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main()
{
	subjectExemple();
	
	printColor("===== Learn the Materia =====", YELLOW);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure()); // More than 4 materia
	
	printColor("===== Create the Materia =====", YELLOW);
	ICharacter* me = new Character("me");
	AMateria* tmp;

	// Valid materia
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure"); 
	me->equip(tmp);
	
	// Non valid materia
	tmp = src->createMateria("ice2");
	me->equip(tmp); 
	tmp = src->createMateria("CURE");
	me->equip(tmp);

	// Valid materia
	tmp = src->createMateria("ice");
	me->equip(tmp); 
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure"); // More than 4 Materia
	delete tmp;
	me->equip(tmp);
	

	printColor("===== Character use Materia =====", YELLOW);
	ICharacter* bob = new Character("bob");
	
	printColor("-- Me use on bob --", YELLOW);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob); // More than 4 Materia
	me->use(5, *bob);

	printColor("-- Bob use on me --", YELLOW);
	// Do not have materia
	bob->use(0, *me);
	// Create materia to equip and use
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	bob->use(0, *me);
	bob->use(1, *me);

	printColor("===== Unequip =====", YELLOW);
	unequipAndDelete(me, 0);
	unequipAndDelete(me, 1);
	unequipAndDelete(me, 2);
	
	unequipAndDelete(bob, 0);
	unequipAndDelete(bob, 1);
	unequipAndDelete(bob, 5);

	delete bob;
	delete me;
	delete src;
	return 0;
}

// Recuperate the adress of Materia than unequip and delete it
void unequipAndDelete(ICharacter *Character, int idx)
{
	AMateria* tmp = Character->getMateria(idx);
	if (idx < 0 || idx >= MAX_MATERIA) {
		printOneBloc(RED "Invalid index to unequip ", idx, RED);
	}
	else if (tmp != NULL) {
		Character->unequip(idx);
		delete tmp;
		tmp = NULL;
	}
	else {
		printOneBloc(RED "No materia at index to unequip ", idx, RED);
	}
}