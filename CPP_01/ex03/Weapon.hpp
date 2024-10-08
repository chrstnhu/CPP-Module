/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:13 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 11:31:19 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

#include <iostream>
#include <string>

class Weapon {
	private:
		std::string	_type;

	public:
		Weapon();
		Weapon(const std::string type);
		~Weapon();
		
		void setType(const std::string type);
		std::string getType() const;
};

#endif 

