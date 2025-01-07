/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:13:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/06 16:29:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

int main (int ac, char **av) {
	if (ac != 2) {
		printColor("Usage: ./serializer [string]", RED, 0);
		return 1;
	}
	Data *original = new Data(av[1]);
	std::cout << std::endl << "Original string: " << original->getInput() << std::endl << std::endl;

	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Serialized pointer (uninptr_t): " << raw << std::endl << std::endl;

	Data *deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized string: " << deserialized->getInput() << std::endl << std::endl;

	if (original == deserialized) {
	    std::cout << BOLDGREEN << "Original and deserialized pointers are the same" << DEF << std::endl << std::endl;
	} else {
		std::cout << BOLDRED << "Original and deserialized pointers are different" << DEF << std::endl << std::endl;
	}

	delete original;
	return 0;
}