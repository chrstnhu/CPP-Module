/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 16:53:29 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	private :
		Brain *_brain;
	public :
		Dog();
		Dog(const Dog &other);
		~Dog();

		// Copy assignement
		Dog &operator=(const Dog &other);

		// Function
		virtual void makeSound() const;
		Brain* getBrain() const { return _brain; }
};

#endif