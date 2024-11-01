/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/01 16:53:39 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	private :
		Brain *_brain;
	public :
		Cat();
		Cat(const Cat &other);
		~Cat();

		// Copy assignement
		Cat &operator=(const Cat &other);

		// Function
		virtual void makeSound() const;
		Brain* getBrain() const { return _brain; }
};

#endif
