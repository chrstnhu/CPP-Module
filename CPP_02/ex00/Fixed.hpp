/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 19:23:54 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/10 19:39:47 by chrhu            ###   ########.fr       */
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

class Fixed {
	private :
		int			_numberFixed;
		const int 	_bitNumber;
	
	public :
		Fixed();
		Fixed( Fixed &numberFixed );
		~Fixed();
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif