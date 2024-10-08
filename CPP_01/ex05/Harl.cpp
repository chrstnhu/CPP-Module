/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:14:49 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 17:23:14 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor
Harl::Harl() {
	std::cout << GREEN << "Construct Harl" << DEF << std::endl;
	return ;
}

// Destructor
Harl::~Harl() {
	std::cout << GREEN << "Destruct Harl" << DEF << std::endl;
	return ;
}

// Messages
void Harl::debug( void ) {
	std::cout << "[DEBUG]" << std::endl
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. " << std::endl
	<< "I really do!" << std::endl << std::endl;
}

void Harl::info( void ) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. " << std::endl
	<< "You didn’t put enough bacon in my burger" << std::endl
	<< "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[WARNING]" << std::endl
	<< "I think I deserve to have some extra bacon for free." << std::endl
	<< "I’ve been coming  for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ERROR]" << std::endl
	<< "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

// Complain messages
void Harl::complain( std::string level ) {
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	void (Harl::*actions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	while (i < 4)
	{
		if (level == levels[i])	{
			(this->*actions[i])();
			return ;
		}
		i++;
	}
	std::cout << "Didn't complain" << std::endl;
	std::cout << "Please enter (DEBUG, INFO, WARNING, ERROR)" << std::endl;
}

