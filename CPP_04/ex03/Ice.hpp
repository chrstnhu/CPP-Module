/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:26:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/30 12:40:26 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria {
	public:
		Ice();
		Ice(std::string type);
		Ice(const Ice &other);
		~Ice();

		// Copy assignement
		Ice &operator=(const Ice &other);

		// Function
		Ice*	clone() const;
		void	use(ICharacter& target);
};

#endif