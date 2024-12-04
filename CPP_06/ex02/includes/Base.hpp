/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:02:17 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 17:21:29 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include "Utils.hpp"

// Base class
class Base {
	public :
		virtual ~Base();
};

// Derived classes
class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif