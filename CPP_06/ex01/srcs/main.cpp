/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:13:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/05 17:51:16 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

int main (int ac, char **av) {
	if (ac != 2) {
		printColor("Usage: ./serializer [string]", RED, 0);
		return 1;
	}
	Data *original = new Data(av[1]);
	std::cout << "Original string: " << original->getInput() << std::endl;

	separatorLine(50);
	printColor("Serializing and deserializing", BOLDYELLOW, 1);
	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Serialized: " << raw << std::endl;


	Data *deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized: " << deserialized->getInput() << std::endl;

	separatorLine(50);
	printColor("Comparing addresses", BOLDYELLOW, 1);
    std::cout << "Address of original: " << original << std::endl;
    std::cout << "Address of deserialized: " << deserialized << std::endl;
	
	if (original == deserialized) {
		printColor("Original and deserialized are the same\n", BOLDGREEN, 1);
	} else {
		printColor("Original and deserialized are different\n", BOLDRED, 1);
	}
	delete original;

	return 0;
}