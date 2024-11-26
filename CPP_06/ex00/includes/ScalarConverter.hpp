/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:13:43 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/26 18:16:01 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "Utils.hpp"

class ScalarConverter {
	private :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		
		//Copy assignement operator
		ScalarConverter &operator=(const ScalarConverter &src);

		static bool isChar(const std::string &input);
		static bool isInt(const std::string &input);
		static bool isFloat(const std::string &input);
		static bool isDouble(const std::string &input);
		
	public :
		static void convert(const std::string &input);
};

#endif