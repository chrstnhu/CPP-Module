/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:40 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/19 18:09:19 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

using namespace std;

void PhoneBook::display_index(string number) const {
	int i = 0;

	cout << "" << endl;
    if (number[1] == '\0' && number[0] >= '1' && number[0] <= '8')
	{
		i = number[0] - '1';
		cout << YELLOW << "Here are the detail of the contact " << i + 1 << ": " << DEFAULT << endl;
		if (contacts[i].get_first_name() == "\0")
		{
			cout << RED << "No detail about contact " << i + 1 << DEFAULT << endl << endl;
			return ;
		}
		cout << "* First name :" << contacts[i].get_first_name() << endl;
		cout << "* Last_name :" << contacts[i].get_last_name() << endl;
		cout << "* Nickname :" << contacts[i].get_nickname() << endl;
		cout << "* Phone Number :" << contacts[i].get_phone_number() << endl;
		cout << "* Darkest secret :" << contacts[i].get_darkest_secret() << endl;
	}
	else
		cout << RED << "ERROR, please insert a number beetween 1-8" << DEFAULT << endl;
	std::cout << "" << std::endl;
}

string PhoneBook::resize(string str) const {
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
		cout << "_________________________________________________________" << endl;
        cout << "| Contact " << i + 1 << " |"
			<< setw(10) << resize(contacts[i].get_first_name()) << "|"
			<< setw(10) << resize(contacts[i].get_last_name()) << "|"
			<< setw(10) << resize(contacts[i].get_nickname()) << "|"
			<< setw(10) << resize(contacts[i].get_phone_number()) << "|" << endl;
	}
	cout << "_________________________________________________________" << endl << endl;
}

PhoneBook::~PhoneBook(void) {
	return;
}