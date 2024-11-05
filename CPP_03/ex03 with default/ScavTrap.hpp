/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:26:14 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/05 11:52:19 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected :
		static const int	_defaultHitPoint = 100;
		static const int	_defaultEnergyPoint = 50;
		static const int	_defaultAttackDamage = 20;
	public :
		ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap &other );
		~ScavTrap();

		// Copy assignement
		ScavTrap &operator=( const ScavTrap &other );
		
		// Functions
		void attack( const std::string& target );
		void guardGate();
};

#endif