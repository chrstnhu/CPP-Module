/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:20:58 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/21 12:30:40 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

#include <iostream>
#include <cmath>

class ClapTrap {
	private :
		std::string		_name;
		unsigned int	_hitPoint;
		unsigned int	_energyPoint;
		unsigned int	_attackDamage;
	
	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hitPoint, int energyPoint, int attackDamage);
		ClapTrap( const ClapTrap &other );
		~ClapTrap();
		
		// Copy assignement
		ClapTrap &operator=( const ClapTrap &other );

		// Functions
		void attack( const std::string& target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );

		// Setter and getter
		void		setName( const std::string name );
		std::string	getName( void ) const;
		int			getAttackDamage( void ) const;
		int			getHitPoint( void ) const;
		void		setEnergyPoint(unsigned int energyPoint );
		int			getEnergyPoint( void ) const;
};

#endif