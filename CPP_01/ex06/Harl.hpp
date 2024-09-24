/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:14:01 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/24 14:53:42 by chrhu            ###   ########.fr       */
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
	private :
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public :
		Harl();
		~Harl();
		void complain( std::string level );

};

#endif 
