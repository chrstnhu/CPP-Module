/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:15:06 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/24 19:03:34 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

#include <iostream>
#include <string>

class WrongAnimal {
	protected :
		std::string _type;
	public :
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal();

		// Copy assignement
		WrongAnimal &operator=(const WrongAnimal &other);

		// Function
		void makeSound() const;
		std::string getType() const;
};

class WrongDog : public WrongAnimal {
	public :
		WrongDog();
		~WrongDog();
		void makeSound() const;
};

class WrongCat : public WrongAnimal {
	public :
		WrongCat();
		~WrongCat();
		void makeSound() const;
};

#endif