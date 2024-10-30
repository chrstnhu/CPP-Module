/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:11:29 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/30 13:27:49 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	protected :
		AMateria	*_inventory[MAX_MATERIA];
		std::string _type;
	public :
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		// Copy assignement
		MateriaSource &operator=(const MateriaSource &other);

		// Functions
		void		learnMateria(AMateria*m);
		AMateria*	createMateria(std::string const & type);
};

#endif