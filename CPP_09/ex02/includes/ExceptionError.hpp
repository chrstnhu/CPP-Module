/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExceptionError.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:01:00 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/05 15:31:05 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTIONERROR_HPP
# define EXCEPTIONERROR_HPP

# include "PmergeMe.hpp"

class ExceptionError {
    public :
        class NumberIsNotPositif : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return 
                        "\n*********************************\n"
                        "*                               *\n"
                        "*      ERROR: Number is not     *\n"
                        "*           POSITIVE !          *\n"
                        "*                               *\n"
                        "*********************************\n";
                }
        };

        class IsNotANumber: public std::exception {
            public:
                virtual const char* what() const throw() {
                    return 
                        "\n*********************************\n"
                        "*                               *\n"
                        "*      ERROR: Args is not       *\n"
                        "*           A NUMBER !          *\n"
                        "*                               *\n"
                        "*********************************\n";
                }
        };
};

class notSorted: public std::exception {
    public:
        virtual const char* what() const throw() {
            return 
                "\n*********************************\n"
                "*                               *\n"
                "*      ERROR: Not sorted        *\n"
                "*                               *\n"
                "*********************************\n";
        }
};

# endif