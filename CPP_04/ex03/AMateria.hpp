/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:59:34 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/30 13:27:07 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string type);
		AMateria(const AMateria &other);
		virtual ~AMateria();
		
		// Copy assignement operator
		AMateria &operator=(const AMateria &other);
		
		// Getters
		std::string const &getType() const;

		// Functions
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif