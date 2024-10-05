/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:13 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/03 18:05:45 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB();
		HumanB(const std::string name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack(void);

	private:
		std::string	_name;
		Weapon *_weapon;
};

#endif 
