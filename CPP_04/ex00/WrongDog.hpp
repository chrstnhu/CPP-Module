/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:15:25 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/24 16:35:59 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
	public :
		WrongDog();
		~WrongDog();
		void makeSound() const;
};


#endif