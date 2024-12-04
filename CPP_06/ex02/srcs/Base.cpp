/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:10:24 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 17:25:47 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

Base::~Base() {
	std::cout << ITALICGREEN << "Base Destructor" << DEF << std::endl;
}

// Functions
Base *generate(void) {
	int randomNum = rand() % 3;

	if (randomNum == 0) {
		return new A();
	}
	else if (randomNum == 1) {
		return new B();
	}
	else {
		return new C();
	}
}

// Derived class A
void identify(Base *p) {
	printColor("Enter identify(Base *p)", ITALICCYAN, 1);
	
	if (dynamic_cast<A*>(p)) {
    	std::cout << "I am an object of type A." << std::endl;
	}
	else if (dynamic_cast<B*>(p)) {
		std::cout << "I am an object of type B." << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
		std::cout << "I am an object of type C." << std::endl;
	}
	else {
		std::cout << "I am not an object of type A, B or C." << std::endl;
	}
}

void identify(Base &p) {
	printColor("Enter identify(Base &p)", ITALICCYAN, 1);

	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "I am an object of type A." << std::endl;
	}
	catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "I am an object of type B." << std::endl;
		}
		catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "I am an object of type C." << std::endl;
			}
			catch (std::exception &e) {
				std::cout << "I am not an object of type A, B or C." << std::endl;
			}
		}
	}
}
