/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:03:29 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/05 18:03:22 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

int main (int ac, char **av) {
	(void)av;
	if (ac != 1) {
		printColor("Usage: ./identify", RED, 0);
		return 1;
	}
	srand(time(NULL));

	printColor("========= First object =========\n", DEF, 0);
	Base *obj = generate();

	identify(obj); // By pointer
    identify(*obj); // By reference

	delete obj;


	printColor("========= Second object =========\n", DEF, 1);
	Base *obj2 = generate();

	identify(obj2);
    identify(*obj2);

	delete obj2;


	printColor("========= Third object =========\n", DEF, 1);
	Base *obj3 = generate();

	identify(obj3);
    identify(*obj3);

	delete obj3;


	printColor("========= Fourth object (testing exception) =========\n", DEF, 1);
    Base *obj4 = new Base();

    identify(obj4);
    identify(*obj4);

	delete obj4;
	return 0;
}
