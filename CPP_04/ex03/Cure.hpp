/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:26:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/29 16:53:52 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		Cure(std::string type);
		Cure(const AMateria &other);
		~Cure();

		// Copy assignement
		Cure &operator=(const Cure &other);

		// Function
		Cure*	clone() const;
		void	use(ICharacter& target);
};

#endif