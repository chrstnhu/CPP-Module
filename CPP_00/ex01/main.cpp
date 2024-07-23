/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:53 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/23 13:21:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(int argc, char **argv) {
	(void)argv;
	PhoneBook phonebook;
	std::string str;
	std::string index;

	if (argc == 1)
	{
		std::cout << "phonebook > ";
		while (std::getline(std::cin, str))
		{
			if (str == "EXIT")
				break ;
			else if (str == "ADD")
				phonebook.add(phonebook);
			else if (str == "SEARCH")
			{
				phonebook.display_contacts();
				std::cout << YELLOW << "Which contact do you want the details ? " << DEFAULT << std::endl;
				std::getline(std::cin, index);
				phonebook.display_index(index);
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
