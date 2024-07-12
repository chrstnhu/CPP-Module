/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:47:51 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/12 20:15:38 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phone.Book.hpp"

int add_str(std::string str)
{
	std::getline(std::cin, str); 
	if (str.empty())
	{
		std::cout << YELLOW <<"Don't leave it empty" << DEFAULT <<std::endl;
		return (1);
	}
	// std::cout << "First name : " << str << std::endl;
	return (0);
}

void add(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secrets;

	std::cout << "enter ADD" << std::endl;
	std::cout << "First name : ";
	if (add_str(first_name))
		return ;
	std::cout << "Last name : ";
	if (add_str(last_name))
		return ;
	std::cout << "Nickname : ";
	if (add_str(nickname))
		return ;
	std::cout << "Phone number : ";
	if (add_str(phone_number))
		return ;
	std::cout << "Secrets : ";
	if (add_str(darkest_secrets))
		return ;
}