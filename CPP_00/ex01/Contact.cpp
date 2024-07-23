/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:47:51 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/23 12:56:38 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::set_first_name(const std::string fn) {
    first_name = fn;
}

void Contact::set_last_name(const std::string ln) {
    last_name = ln;
}

void Contact::set_nickname(const std::string nn) {
    nickname = nn;
}

void Contact::set_phone_number(const std::string pn) {
    phone_number = pn;
}

void Contact::set_darkest_secret(const std::string ds) {
    darkest_secret = ds;
}

std::string Contact::get_first_name() const {
    return first_name;
}

std::string Contact::get_last_name() const {
    return last_name;
}

std::string Contact::get_nickname() const {
    return nickname;
}

std::string Contact::get_phone_number() const {
    return phone_number;
}

std::string Contact::get_darkest_secret() const {
    return darkest_secret;
}