/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:26:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 16:23:22 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	protected :
		std::string	_type;
	public:
		Character();
		Character(std::string type);
		Character(const Character &other);
		~Character();
		
		// Copy assignment
		Character & operator=(const Character &other);
		
		// Getter
		std::string const & getName() const;

		// Function
		void equip(AMateria* m);
};

#endif
