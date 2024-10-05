/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:14:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/03 18:06:59 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

class Harl {
	public :
		Harl();
		~Harl();
		void complain( std::string level );

	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif 
