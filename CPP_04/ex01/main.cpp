/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:09:37 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 17:17:04 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void fillTab();
static void tryDeepCopy();

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "Type: " << j->getType() << std::endl;
	std::cout << "Type: " << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	
	delete i;
	delete j;
	
	fillTab();
	tryDeepCopy();
	return 0;
}

static void printCopy(const Animal **a, int index, const std::string &type) {
	if (type == "Dog") {
		a[index] = new Dog();
	}
	else if (type == "Cat") {
		a[index] = new Cat();
	}
	else if (type == "Animal") {
		a[index] = new Animal();
	}
	std::cout << index + 1 << " - Type: " << a[index]->getType() << " | "
              << "Address: " << a[index] << std::endl;
}

static void fillTab () {
	static int max = 10;
	const Animal** a = new const Animal *[max];

	std::cout << std::endl << YELLOW << "========== Animal object ==========" << DEF << std::endl;
	for (int index = 0; index < max / 2; index++) {
		printCopy(a, index, "Dog");
	}
	for (int index = max/2; index < (max); index++) {
		printCopy(a, index, "Cat");
	}
	for (int index = 0; index < max / 2; index++) {
		printCopy(a, index, "Animal");
	}
	for (int index = max/2; index < (max); index++) {
		printCopy(a, index, "");
	}
	std::cout << std::endl << YELLOW << "===== Delete all =====" << DEF << std::endl;
	for (int index = 0; index < max; index++) {
		delete a [index];
	}
	delete[] a;
}

static void tryDeepCopy () {
	std::cout << std::endl << YELLOW << "========== Deep Copy ==========" << DEF << std::endl;
	
    Dog* originalDog = new Dog();
    Cat* originalCat = new Cat();

    Dog* copiedDog = new Dog(*originalDog);
    Cat* copiedCat = new Cat(*originalCat);

    std::cout << "Original Dog Brain Address: " << originalDog->getBrain() << std::endl;
    std::cout << "Copied Dog Brain Address: " << copiedDog->getBrain() << std::endl;

    std::cout << "Original Cat Brain Address: " << originalCat->getBrain() << std::endl;
    std::cout << "Copied Cat Brain Address: " << copiedCat->getBrain() << std::endl;

    if (originalDog->getBrain() != copiedDog->getBrain()) {
        std::cout << "Dog is a deep copy." << std::endl;
    } else {
        std::cout << "Dog is a shallow copy." << std::endl;
    }

    if (originalCat->getBrain() != copiedCat->getBrain()) {
        std::cout << "Cat is a deep copy." << std::endl;
    } else {
        std::cout << "Cat is a shallow copy." << std::endl;
    }

    delete originalDog;
    delete copiedDog;
    delete originalCat;
    delete copiedCat;
}