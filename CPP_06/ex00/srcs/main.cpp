/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:13:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/29 16:02:24 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

int main (int ac, char **av) {
	if (ac != 2) {
		printColor("Error: Invalid number of arguments", RED, 1);
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}