/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:47:51 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/18 20:30:54 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::add_contact(Contact contact) {
	int i = 0;

    if (contact_count < max_contacts) 
    {
		i = contact_count;
		while (i > 0) 
        {
            contacts[i] = contacts[i - 1];
			i--;
        }
        contacts[0] = contact;
        contact_count++;
    } 
    if (contact_count == max_contacts) 
    {
		i = max_contacts - 1;
        while (i > 0) 
        {
            contacts[i] = contacts[i - 1];
			i--;
        }
        contacts[0] = contact;
    }
}

int add_str(std::string &str) {
	std::getline(std::cin, str); 
	if (str.empty())
	{
		std::cout << YELLOW << "Don't leave it empty !" << DEFAULT << std::endl;
		return (1);
	}
	return (0);
}

void PhoneBook::add(PhoneBook &phonebook) {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "First name: ";
    if (add_str(first_name))
		return;
    
	std::cout << "Last name: ";
    if (add_str(last_name))
		return;
    
	std::cout << "Nickname: ";
    if (add_str(nickname))
		return;
    
	std::cout << "Phone number: ";
    if (add_str(phone_number))
		return;

    std::cout << "Secrets: ";
    if (add_str(darkest_secret))
		return;

    Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
    phonebook.add_contact(new_contact);

    std::cout << GREEN << "Contact added successfully!" << DEFAULT << std::endl << std::endl;
}
