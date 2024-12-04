/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:03:29 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 17:01:09 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

int main () {
	srand(time(NULL));

	Base *obj = Base::generate();

	// By pointer
	obj->identify(obj);

	// By reference
    obj->identify(*obj);

	return 0;
}

/* 

#include <iostream>
#include <exception>

class Parent { public: virtual ~Parent() {} };
class Child1: public Parent {};
class Child2: public Parent {};

int main () {
	Child1 a;
	Parent *b = &a;

	Child1 *c = dynamic_cast<Child1 *>(b);
	if (c == NULL) {
		std::cout << "Conversion is NOT OK" << std::endl;
	}
	else {
		std::cout << "Conversion is OK" << std::endl;
	}

	try {
		Child2 & d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion is Ok" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Conversion is NOT Ok: "  << e.what() << std::endl;
		return 0;
	}

	return 0;
	
} */