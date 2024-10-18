/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:26:14 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/18 17:43:51 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

class ScavTrap : public ClapTrap {
	public :
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap( const ScavTrap &other );
		~ScavTrap();

		ScavTrap &operator=( const ScavTrap &other );
		void guardGate();
};

#endif