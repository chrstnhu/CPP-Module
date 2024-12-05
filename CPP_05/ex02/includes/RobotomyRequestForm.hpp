/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/05 16:24:48 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Utils.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		virtual ~RobotomyRequestForm();

		// Copy assignement operator
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

		// Functions
		void performAction() const;
};

#endif