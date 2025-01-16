/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:29:51 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/16 17:57:16 by chrhu            ###   ########.fr       */
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
        RPN(std::stack<int> stack);
        RPN(const RPN &other);
        ~RPN();

        // Copy assignement;
        RPN &operator=(const RPN &other);
        
        // Function
        void checkValidity(const std::string str);
        int evalRPN(std::string str);
        
};

# endif