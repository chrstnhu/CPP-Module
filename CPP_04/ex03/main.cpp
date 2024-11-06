/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:58:46 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/06 13:41:07 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include "includes/Character.hpp"
#include "includes/ICharacter.hpp"
#include "includes/MateriaSource.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/AMateria.hpp"

int main()
{
	std::cout << YELLOW << "===== Learn the Materia =====" << DEF << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	
	std::cout << std::endl << YELLOW << "===== Create the Materia =====" << DEF << std::endl;
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	std::cout << std::endl << "Create the ice2" << std::endl;
	tmp = src->createMateria("ice2");
	me->equip(tmp);

	std::cout << std::endl << YELLOW << "===== Character use Materia =====" << DEF << std::endl;
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *me);
	me->use(3, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
}