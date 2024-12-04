/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:13:43 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 13:02:54 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Utils.hpp"

class Serializer {
	private :	
		Serializer();
		Serializer(const Serializer &other);
		~Serializer();
		
		//Copy assignement operator
		Serializer &operator=(const Serializer &src);

	public :
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif