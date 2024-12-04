/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:10:24 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 17:01:19 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

Base::~Base() {
	std::cout << ITALICGREEN << "Base Destructor" << DEF << std::endl;
}

A::A() {
	std::cout << ITALICGREEN << "A Constructor" << DEF << std::endl;
}

A::~A() {
	std::cout << ITALICGREEN << "A Destructor" << DEF << std::endl;
}

B::B() {
	std::cout << ITALICGREEN << "B Constructor" << DEF << std::endl;
}

B::~B() {
	std::cout << ITALICGREEN << "B Destructor" << DEF << std::endl;
}

C::C() {
	std::cout << ITALICGREEN << "C Constructor" << DEF << std::endl;
}

C::~C() {
	std::cout << ITALICGREEN << "C Destructor" << DEF << std::endl;
}

// Functions
Base *Base::generate(void) {
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
void A::identify(Base *p) {
	printColor("Enter identify(Base *p) in A", ITALICCYAN, 1);
	
	if (dynamic_cast<A*>(p)) {
    	std::cout << "I am an object of type A." << std::endl;
	}
	else {
		std::cout << "I am not an object of type A." << std::endl;
	}
}

void A::identify(Base &p) {
	printColor("Enter identify(Base &p) in A", ITALICCYAN, 1);

	try {
		if (dynamic_cast<A *>(&p)) {
			throw std::exception();
		}
		std::cout << "I am an object of type A." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "I am not an object of type A." << e.what() << std::endl;
	}
}

// Derived class B
void B::identify(Base *p) {
	printColor("Enter identify(Base *p) in B", ITALICCYAN, 1);
	
	if (dynamic_cast<A*>(p)) {
    	std::cout << "I am an object of type B." << std::endl;
	}
	else {
		std::cout << "I am not an object of type B." << std::endl;
	}
}

void B::identify(Base &p) {
	printColor("Enter identify(Base &p) in B", ITALICCYAN, 1);

	try {
		if (dynamic_cast<B *>(&p)) {
			throw std::exception();
		}
		std::cout << "I am an object of type B." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "I am not an object of type B." << e.what() << std::endl;
	}
}

// Derived class C
void C::identify(Base *p) {
	printColor("Enter identify(Base *p) in C", ITALICCYAN, 1);

	if (dynamic_cast<A*>(p)) {
    	std::cout << "I am an object of type C." << std::endl;
	}
	else {
		std::cout << "I am not an object of type C." << std::endl;
	}
}

void C::identify(Base &p) {
	printColor("Enter identify(Base &p) in C", ITALICCYAN, 1);

	try {
		if (dynamic_cast<C *>(&p)) {
			throw std::exception();
		}
		std::cout << "I am an object of type C." << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "I am not an object of type C." << e.what() << std::endl;
	}
}
