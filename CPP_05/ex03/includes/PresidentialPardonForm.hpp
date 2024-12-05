/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:28 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/05 16:22:02 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Utils.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		virtual ~PresidentialPardonForm();

		// Copy assignement operator
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

		// Functions
		void performAction() const;
};

#endif