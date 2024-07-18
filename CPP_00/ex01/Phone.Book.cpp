/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone.Book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/18 20:49:56 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phone.Book.hpp"
#include "contact.hpp"

void PhoneBook::add_contact(Contact contact) 
{
    if (contact_count < max_contacts)
	{
        contacts[contact_count] = contact;
        contact_count++;
    } else
	{
        for (int i = 1; i < max_contacts; i++) 
		{
            contacts[i - 1] = contacts[i];
        }
        contacts[max_contacts - 1] = contact;
    }
}

void PhoneBook::display_contacts() const 
{
    if (contact_count == 0) {
            std::cout << "No contacts to display." << std::endl;
            return;
        }

        for (int i = 0; i < contact_count; i++) {
            std::cout << "Contact " << i + 1 << ": "
                      << std::setw(10) << contacts[i].get_first_name() << " "
                      << std::setw(10) << contacts[i].get_last_name() << " "
                      << std::setw(10) << contacts[i].get_nickname() << " "
                      << std::setw(15) << contacts[i].get_phone_number() << " "
                      << std::setw(20) << contacts[i].get_darkest_secret() << std::endl;
        }
}
