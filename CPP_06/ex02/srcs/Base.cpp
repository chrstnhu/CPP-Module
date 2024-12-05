/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:10:24 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/05 18:26:46 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

Base::~Base()
{
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

// Dynamic cast with pointer
void identify(Base *p) {
	printColor("-> Enter identify(Base *p) with pointer", ITALICDEF, 0);

	try {
		if (!dynamic_cast<A *>(p)) {
			throw std::exception();
		}
		std::cout << BOLDBLUE << "I am an object of type A" << DEF << std::endl;
	}
	catch (std::exception &e) {
		try {
			if (!dynamic_cast<B *>(p)) {
				throw std::exception();
			}
			std::cout << BOLDORANGE << "I am an object of type B" << DEF << std::endl;
		}
		catch (std::exception &e) {
			try {
				if (!dynamic_cast<C *>(p)) {
					throw std::exception();
				}
				std::cout << BOLDPURPLE << "I am an object of type C" << DEF << std::endl;
			}
			catch (std::exception &e) {
				std::cout << RED << "I am not an object of type A, B or C." << std::endl;
			}
		}
	}
}

// Dynamic cast with reference
void identify(Base &p) {
	printColor("-> Enter identify(Base &p) with reference", ITALICDEF, 1);

	try {
		A a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << BOLDBLUE << "I am an object of type A" << DEF << std::endl;
	}
	catch (std::exception &e) {
		try {
			B b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << BOLDORANGE << "I am an object of type B" << DEF << std::endl;
		}
		catch (std::exception &e) {
			try {
				C c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << BOLDPURPLE << "I am an object of type C" << DEF << std::endl;
			}
			catch (std::exception &e) {
				std::cout << RED << "I am not an object of type A, B or C." << std::endl;
			}
		}
	}
}
