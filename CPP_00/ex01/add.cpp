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

#include "Phone.Book.hpp"
#include "contact.hpp"

using namespace std;

void PhoneBook::add_contact(Contact contact) 
{
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

int add_str(std::string &str)
{
	getline(cin, str); 
	if (str.empty())
	{
		cout << YELLOW << "Don't leave it empty !" << DEFAULT << endl;
		return (1);
	}
	return (0);
}

void PhoneBook::add(PhoneBook &phonebook)
{
    string first_name;
    string last_name;
    string nickname;
    string phone_number;
    string darkest_secret;

    cout << "First name: ";
    if (add_str(first_name))
		return;
    
	cout << "Last name: ";
    if (add_str(last_name))
		return;
    
	cout << "Nickname: ";
    if (add_str(nickname))
		return;
    
	cout << "Phone number: ";
    if (add_str(phone_number))
		return;

    cout << "Secrets: ";
    if (add_str(darkest_secret))
		return;

    Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
    phonebook.add_contact(new_contact);

    cout << GREEN << "Contact added successfully!" << DEFAULT << endl << endl;
}
