/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/08 15:27:20 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private :
		Brain *_brain;
	public :
		Dog();
		Dog(const Dog &other);
		~Dog();

		// Copy assignement
		Dog &operator=(const Dog &other);

		// Setter
		void setBrainIdeas(int index, std::string idea);
		std::string getBrainIdeas(int index) const;

		// Function
		virtual void makeSound() const;
};

#endif