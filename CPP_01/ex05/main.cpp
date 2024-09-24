/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:13:56 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/24 16:05:59 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
	
	std::string names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	if (ac == 2)
	{
		Harl Harl1;
		i = 0;
		while(i < 4)
		{
			if (names[i] == av[1])
			{
				Harl1.complain(av[1]);
				return 0;
			}
			i++;
		}
		std::cout << "Didn't complain" << std::endl;
		std::cout << "Please enter (DEBUG, INFO, WARNING, ERROR)" << std::endl;
	}
	else
		std::cout << RED << "Usage : ./Harl complain(DEBUG, INFO, WARNING, ERROR)" << DEF << std::endl;
		
	return 0;
}
