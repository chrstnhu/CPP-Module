/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:28:02 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/23 13:15:31 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

# define DEFAULT "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

class PhoneBook 
{
	private:
		static const int max_contacts = 8;
		Contact contacts[max_contacts];
		int contact_count;

	public:
		PhoneBook(): contact_count(max_contacts) {}
		~PhoneBook();
		void add_contact(Contact contact);
		void display_contacts() const ;
		std::string resize(std::string str) const;
		void display_index(std::string number) const;
		void add(PhoneBook &phonebook);
};

#endif