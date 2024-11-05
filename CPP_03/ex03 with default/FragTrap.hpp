/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:15:42 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/05 11:50:33 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected :
		static const int	_defaultHitPoint = 100;
		static const int	_defaultEnergyPoint = 100;
		static const int	_defaultAttackDamage = 30;
	public :
		FragTrap();
		FragTrap( std::string name );
		FragTrap( const FragTrap &other);
		~FragTrap();

		// Copy assignement
		FragTrap &operator=( const FragTrap &other);
	
		// Functions
		void highFivesGuys( void );
};

#endif