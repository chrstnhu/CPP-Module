/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:09:37 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/25 16:29:15 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <math.h>
#include <cmath>


int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "Type: " << j->getType() << " " << std::endl
			<< "Adress: " << j << std::endl;
	std::cout << "Type: " << i->getType() << " " << std::endl
			<< "Adress: " << i << std::endl;
	i->makeSound();
	j->makeSound();
	
	static int index = 0;
	static int nb = 10;
	const Animal** a = new const Animal *[nb];
	std::cout << YELLOW << "========== Animal object ==========" << DEF << std::endl;
	while (index < (nb/2)) {
		a[index] = new Dog();
		std::cout << index + 1 << " - Type: " << a[index]->getType() << " " << std::endl;
        std::cout << "Address: " << a[index] << std::endl;
		index++;
	}
	while (index < nb) {
		a[index] = new Cat();
		std::cout << index + 1 << " - Type: " << a[index]->getType() << " " << std::endl;
        std::cout << "Address: " << a[index] << std::endl;
		index++;
	}
	delete i;
	delete j;
	for (int index = 0; index < nb; index++) {
		delete a [index];
	}
	delete[] a;
	return 0;
}
