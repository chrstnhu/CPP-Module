/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:02:17 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 17:01:28 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include "Utils.hpp"

// Base class
class Base {
	public :
		virtual ~Base();

		// Functions
		static Base *generate(void);
		virtual void identify(Base *p) = 0;
		virtual void identify(Base &p) = 0;
};

// Derived classes
class A : public Base {
	public :
		A();
		~A();
};

class B : public Base {
	public :
		B();
		~B();
		void identify(Base *p);
		void identify(Base &p);
};

class C : public Base {
	public :
		C();
		~C();
		void identify(Base *p);
		void identify(Base &p);
};

#endif