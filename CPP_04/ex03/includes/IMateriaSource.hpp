/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:11:29 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/06 13:46:13 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class AMateria;

class IMateriaSource {
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*m) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif