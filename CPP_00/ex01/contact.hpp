/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:28:02 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/18 20:47:47 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iomanip>
#include "Phone.Book.hpp"


class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();
    Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);

    void set_first_name(const std::string &fn);
    void set_last_name(const std::string &ln);
    void set_nickname(const std::string &nn);
    void set_phone_number(const std::string &pn);
    void set_darkest_secret(const std::string &ds);

    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_phone_number() const;
    std::string get_darkest_secret() const;
};

#endif
