/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:28:02 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/19 19:03:11 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iomanip>
#include "PhoneBook.hpp"

class Contact
{
	private:
	    std::string first_name;
	    std::string last_name;
	    std::string nickname;
	    std::string phone_number;
	    std::string darkest_secret;

	public:
	    Contact() {}
	    Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret) 
	        : first_name(first_name), last_name(last_name), nickname(nickname), phone_number(phone_number), darkest_secret(darkest_secret) {}	
		~Contact() {};

		//Setter
	    void set_first_name(const std::string &first_name);
	    void set_last_name(const std::string &last_name);
	    void set_nickname(const std::string &nickname);
	    void set_phone_number(const std::string &phone_number); 
	    void set_darkest_secret(const std::string &darkest_secret);

		//Getter
	    std::string get_first_name() const ;
	    std::string get_last_name() const ;
	    std::string get_nickname() const ;
	    std::string get_phone_number() const ;
	    std::string get_darkest_secret() const ;
};

#endif
