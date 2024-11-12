/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:11 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/12 11:31:43 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal {
	protected :
		std::string _type;
	public :
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &other);
		virtual ~AAnimal();

		// Copy assignement
		AAnimal &operator=(const AAnimal &other);

		// Getter and setter
		std::string getType() const;
		virtual void setType(std::string type) = 0;

		// Function
		virtual void makeSound() const = 0;
};

#endif