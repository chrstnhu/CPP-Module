/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:13:56 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/05 15:45:00 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
	
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// int i = 0;

	if (ac == 2)
	{
		Harl Harl1;
		Harl1.complain(av[1]);
	}
	else
		std::cout << RED << "Usage : ./Harl [complain(DEBUG, INFO, WARNING, ERROR)]" << DEF << std::endl;
		
	return 0;
}
