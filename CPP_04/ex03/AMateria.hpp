/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:59:34 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 12:57:00 by chrhu            ###   ########.fr       */
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
		
		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class Ice : public AMateria {
	public:
		Ice();
		Ice(std::string type);
		Ice(const AMateria &other);
		~Ice();

		Ice &operator=(const Ice &other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

class Cure : public AMateria {
	public:
		Cure();
		Cure(std::string type);
		Cure(const AMateria &other);
		~Cure();

		Cure &operator=(const Cure &other);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif