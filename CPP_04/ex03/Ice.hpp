/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:26:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 16:34:50 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(std::string type);
		Ice(const AMateria &other);
		virtual ~Ice();

		Ice &operator=(const Ice &other);

		// Function
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif