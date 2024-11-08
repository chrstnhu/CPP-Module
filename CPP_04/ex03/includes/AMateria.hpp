/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:59:34 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/08 13:25:41 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "Utils.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string _type; 

	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		virtual ~AMateria();
		
		// Copy assignement operator
		AMateria &operator=(const AMateria &other);
		
		// Getters
		std::string const &getType() const; // Returns the materia type

		// Functions
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif