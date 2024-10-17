/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:23:54 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/17 12:21:09 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

#include <iostream>
#include <cmath>

class Fixed {
	private :
		int					_raw;
		static int const 	_rawBit = 8;
		static float const	_rawFloatBit;
	
	public :
		Fixed();
		Fixed( int const number );
		Fixed( float const number );
		Fixed( const Fixed &other );
		~Fixed();

		// Copy assignment operator overload
		Fixed	&operator=( const Fixed &other );

		// Getter and setter
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		// Conversion
		float	toFloat( void ) const;
		int		toInt( void ) const;

};

// Overloads the << operator
std::ostream &operator << (std::ostream& os, const Fixed &obj);

#endif