/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phone.Book.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:28:02 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/18 20:47:52 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include "contact.hpp"

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
    PhoneBook() : contact_count(0) {}

    void add_contact(Contact contact);
    void display_contacts() const ;
};

void add(PhoneBook &phonebook);

#endif