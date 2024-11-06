/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:09:37 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/06 12:49:37 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << "Type: " << j->getType() << " " << std::endl;
	std::cout << "Type: " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	
	delete i;
	delete j;


	static const int max = 10;
	const AAnimal** a = new const AAnimal *[max];
	std::cout << YELLOW << "========== Animal object ==========" << DEF << std::endl;

	for (int i = 0; i < max / 2; i++) {
		a[i] = new Dog();
		std::cout << i + 1 << " - Type: " << a[i]->getType() << " " << std::endl;
        std::cout << "Address: " << a[i] << std::endl;
	}
	for (int i = max / 2; i < max; i++) {
		a[i] = new Cat();
		std::cout << i + 1 << " - Type: " << a[i]->getType() << " " << std::endl;
        std::cout << "Address: " << a[i] << std::endl;
	}

	for (int i = 0; i < max; i++) {
		delete a [i];
	}

	delete [] a;
	return 0;
}
