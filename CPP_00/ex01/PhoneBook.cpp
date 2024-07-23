/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/23 13:15:37 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


void PhoneBook::display_index(std::string number) const {
	int i = 0;

	std::cout << "" << std::endl;
    if (number[1] == '\0' && number[0] >= '1' && number[0] <= '8')
	{
		i = number[0] - '1';
		std::cout << YELLOW << "Here are the detail of the contact " 
					<< i + 1 << ": " << DEFAULT << std::endl;
		if (contacts[i].get_first_name() == "\0")
		{
			std::cout << RED << "No detail about contact " 
						<< i + 1 << DEFAULT << std::endl << std::endl;
			return ;
		}
		std::cout << "* First name :" << contacts[i].get_first_name() << std::endl;
		std::cout << "* Last_name :" << contacts[i].get_last_name() << std::endl;
		std::cout << "* Nickname :" << contacts[i].get_nickname() << std::endl;
		std::cout << "* Phone Number :" << contacts[i].get_phone_number() << std::endl;
		std::cout << "* Darkest secret :" << contacts[i].get_darkest_secret() << std::endl;
	}
	else
		std::cout << RED << "ERROR, please insert a number beetween 1-8" << DEFAULT << std::endl;
	std::cout << "" << std::endl;
}

std::string PhoneBook::resize(std::string str) const {
	if (str.size() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	return(str);
}

void PhoneBook::display_contacts() const {
	int i = -1;

    while (++i < contact_count) 
	{
		std::cout << "_________________________________________________________" << std::endl;
        std::cout << "| Contact " << i + 1 << " |"
			<< std::setw(10) << resize(contacts[i].get_first_name()) << "|"
			<< std::setw(10) << resize(contacts[i].get_last_name()) << "|"
			<< std::setw(10) << resize(contacts[i].get_nickname()) << "|"
			<< std::setw(10) << resize(contacts[i].get_phone_number()) << "|" << std::endl;
	}
	std::cout << "_________________________________________________________" << std::endl << std::endl;
}

PhoneBook::~PhoneBook(void) {
	return;
}