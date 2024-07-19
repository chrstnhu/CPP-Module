/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:27:53 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/19 19:04:12 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

using namespace std;

int main(int argc, char **argv) {
	(void)argv;
	PhoneBook phonebook;
	string str;
	string index;

	if (argc == 1)
	{
		cout << "phonebook > ";
		while (getline(cin, str))
		{
			if (str == "EXIT")
				break ;
			else if (str == "ADD")
				phonebook.add(phonebook);
			else if (str == "SEARCH")
			{
				phonebook.display_contacts();
				cout << YELLOW << "Which contact do you want the details ? " << DEFAULT << endl;
				getline(cin, index);
				phonebook.display_index(index);
			}
			else
				cout << RED << "Try again with : ADD/SEARCH/EXIT " << DEFAULT << endl;
			cout << "phonebook > ";
		}
	}
	else
		cout << RED << "./phonebook don't take arg" << DEFAULT << endl;
	return (0);
}
