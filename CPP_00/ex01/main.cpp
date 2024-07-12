/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:53 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/12 20:15:20 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phone.Book.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	std::string str;

	if (argc == 1)
	{
		std::cout << "> ";
		while (std::getline(std::cin, str))
		{
			if (str == "EXIT")
				break ;
			else if (str == "ADD")
				add();
			else if (str == "SEARCH")
				std::cout << "enter SEARCH" << std::endl;
			else
				std::cout << RED << "Try again with : ADD/SEARCH/EXIT " << DEFAULT << std::endl;
			std::cout << "> ";
		}
	}
	else
		std::cout << RED << "./phonebook don't take arg" << DEFAULT << std::endl;
	return (0);
}
