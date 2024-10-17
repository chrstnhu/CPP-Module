/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:20:58 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/17 18:30:16 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cmath>

class ClapTrap {
	private :
		std::string _name;
		int	_hitPoint;
		int _energyPoint;
		int _attackDamage;
	
	public :
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		
		ClapTrap &operator=(const ClapTrap &other);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void takeDamage(unsigned int amount);
};

#endif