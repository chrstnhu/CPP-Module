/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:09:37 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/12 11:11:50 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testDeepCopy();

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "Type: " << j->getType() << " " << std::endl;
	std::cout << "Type: " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	
	delete i;
	delete j;


	static const int max = 10;
	const Animal** a = new const Animal *[max];
	std::cout << YELLOW << "========== Animal object ==========" << DEF << std::endl;

	for (int i = 0; i < max / 2; i++) {
		a[i] = new Dog();
		std::cout << i + 1 << " - Type: " << a[i]->getType() << std::endl;
	}
	for (int i = max / 2; i < max; i++) {
		a[i] = new Cat();
		std::cout << i + 1 << " - Type: " << a[i]->getType() << std::endl;
	}

	for (int i = 0; i < max; i++) {
		delete a [i];
	}

	delete [] a;

	testDeepCopy();
	return 0;
}

void testDeepCopy() {
	std::cout << std::endl << YELLOW << "========== Deep copy ==========" << DEF << std::endl;
	Dog dog1("Dog1");
	dog1.setBrainIdeas(0, "New idea in Dog1");

	std::cout << "Address of dog1.getBrain(): " << dog1.getBrain() << std::endl;

	Dog dog2 = dog1;
	std::cout << YELLOW << "Before dog2.setType" << DEF << std::endl;
	std::cout << dog2.getType() << " idea: " << dog2.getBrainIdeas(0) << std::endl;

	std::cout << "Address of dog2.getBrain(): " << dog2.getBrain() << std::endl;

	std::cout << YELLOW << "After dog2.setType" << DEF << std::endl;
	dog2.setType("Dog2");
	dog2.setBrainIdeas(0, "New idea in Dog2");
	// Compare dog1 and dog2
	std::cout << dog1.getType() << " idea: " << dog1.getBrainIdeas(0) << std::endl;
	std::cout << dog2.getType() << " idea: " << dog2.getBrainIdeas(0)  << std::endl;

	Dog *dog3;
	dog3 = new Dog(dog1);
	std::cout << YELLOW << "Before dog3.setType" << DEF << std::endl;
	std::cout <<  dog3->getType() << " idea: " << dog3->getBrainIdeas(0)<< std::endl;
	
	std::cout << "Address of dog3->getBrain(): " << dog3->getBrain()  << std::endl;
	
	// Compare dog1 and dog3
	std::cout << YELLOW << "After dog3.setType" << DEF << std::endl;
	dog3->setType("Dog3");
	dog3->setBrainIdeas(0, "New idea in Dog3");
	
	std::cout << dog1.getType() << " idea: " << dog1.getBrainIdeas(0) << std::endl;
	std::cout << dog3->getType() << " idea: " << dog3->getBrainIdeas(0)  << std::endl;
	delete dog3;
}
