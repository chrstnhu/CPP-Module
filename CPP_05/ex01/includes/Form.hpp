/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/11/11 19:11:56 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
	private:
		std::string const _name;
		bool _signed;
		const int _grade;
		const int _executeGrade;
	
	public :
		Form();
		Form(std::string const name, int grade, int executeGrade);
		Form(Form const &other);
		~Form();

		// Copy assignement operator
		Form &operator=(Form const &other);
};

#endif