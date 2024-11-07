/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:15:06 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/07 16:59:37 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public :
		WrongCat();
		WrongCat(const WrongCat &other);
		~WrongCat();

		// Copy assignement
		WrongCat &operator=(const WrongCat &other);

		// Function
		void makeSound() const;
};

#endif