/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:53 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/18 20:40:25 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phone.Book.hpp"
#include "contact.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	std::string str;
	PhoneBook phonebook;

	if (argc == 1)
	{
		std::cout << "phonebook > ";
		while (std::getline(std::cin, str))
		{
			if (str == "EXIT")
				break ;
			else if (str == "ADD")
				add(phonebook);
			else if (str == "SEARCH")
			{
				std::cout << "enter SEARCH" << std::endl;
				phonebook.display_contacts();
			}
			else
				std::cout << RED << "Try again with : ADD/SEARCH/EXIT " << DEFAULT << std::endl;
			std::cout << "phonebook > ";
		}
	}
	else
		std::cout << RED << "./phonebook don't take arg" << DEFAULT << std::endl;
	return (0);
}
