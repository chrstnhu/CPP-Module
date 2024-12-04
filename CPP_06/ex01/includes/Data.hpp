/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:13:43 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 13:35:55 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include "Utils.hpp"

class Data {
	private :
		std::string _input;

	public :
		Data();
		Data(std::string input);
		Data(const Data &other);
		~Data();

		// Copy assignement operator
		Data &operator=(const Data &other);

		// Getters and setters
		void setInput(std::string input);
		std::string getInput() const;
};

#endif