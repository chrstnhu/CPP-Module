/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:56:13 by chrhu             #+#    #+#             */
/*   Updated: 2024/09/18 17:11:26 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# define BLUE "\033[0;313m"
# define DEF "\033[0;39m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m" 

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string		name;
	
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void set_name(const std::string name);
		std::string get_name() const ;
		void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif 
