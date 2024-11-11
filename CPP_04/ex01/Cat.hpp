/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/11 12:36:05 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	private :
		Brain *_brain;
	public :
		Cat();
		Cat(std::string const type);
		Cat(const Cat &other);
		~Cat();

		// Copy assignement
		Cat &operator=(const Cat &other);

		// Setter
		std::string getBrainIdeas(int index) const;
		void setBrainIdeas(int index, std::string idea);
		
		// Function
		virtual void makeSound() const;
};

#endif
