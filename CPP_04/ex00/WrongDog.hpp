/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:15:06 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 13:23:23 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
	public :
		WrongDog();
		WrongDog(const WrongDog &other);
		~WrongDog();

		// Copy assignement
		WrongDog &operator=(const WrongDog &other);
		
		// Functions
		void makeSound() const;
};

#endif