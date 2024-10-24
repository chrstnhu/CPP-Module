/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:09:37 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/24 18:00:33 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

void printWrongAnimal();

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "Type: " << j->getType() << " " << std::endl;
	std::cout << "Type: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	printWrongAnimal();
	
	delete i;
	delete j;
	delete meta;
	return 0;
}

void printWrongAnimal() {
	std::cout << std::endl << YELLOW 
		<< "======= print Wrong Animal =========" 
		<< DEF << std::endl;
	const WrongAnimal* a = new WrongAnimal();
	const WrongAnimal* b = new WrongDog();
	const WrongAnimal* c = new WrongCat();

	std::cout << "Type: " << b->getType() << " " << std::endl;
	std::cout << "Type: " << c->getType() << " " << std::endl;
	a->makeSound();
	b->makeSound();
	c->makeSound();

	delete a;
	delete b;
	delete c;
}