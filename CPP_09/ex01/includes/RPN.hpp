/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:51 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/04 15:22:05 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <ctime>
# include <sstream>
# include <cmath>
# include <algorithm>
# include <stack>
# include <climits> 

# include "Colors.hpp"

class RPN {
    public :
        RPN();
        RPN(std::stack<double> stack);
        RPN(const RPN &other);
        ~RPN();

        // Copy assignement;
        RPN &operator=(const RPN &other);
        
        // Function
        void checkValidity(const std::string str);
        double evalRPN(std::string str);
        
        // Exceptions
        class isInvalid: public std::exception {
            public:
                virtual const char* what() const throw() {
                    return 
                        "\n************************************\n"
                        "*                                  *\n"
                        "*   ERROR: Invalid number (0 - 9)  *\n"
                        "*      or sign (+, -, *, /)        *\n"
                        "*                                  *\n"
                        "************************************\n";
                }
        };

        class notEnoughOperand: public std::exception {
            public:
                virtual const char* what() const throw() {
                    return 
                        "\n********************************\n"
                        "*                              *\n"
                        "*   ERROR: Not enough operand  *\n"
                        "*     number beetween(0 - 9)   *\n"
                        "*                              *\n"
                        "********************************\n";
                }
        };

        class notEnoughOperator: public std::exception {
            public:
                virtual const char* what() const throw() {
                    return 
                        "\n************************************\n"
                        "*                                  *\n"
                        "*    ERROR: Not enough operator    *\n"
                        "*         sign (+, -, *, /)        *\n"
                        "*                                  *\n"
                        "************************************\n";
                }
        };


        class invalidSize: public std::exception {
            public:
                virtual const char* what() const throw() {
                    return 
                        "\n*********************************\n"
                        "*                               *\n"
                        "*      ERROR: Invalid size      *\n"
                        "*  Not enough operand in stack  *\n"
                        "*                               *\n"
                        "*********************************\n";
                }
        };

};

# endif