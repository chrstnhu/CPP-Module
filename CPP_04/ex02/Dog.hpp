/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/08 14:26:48 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
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