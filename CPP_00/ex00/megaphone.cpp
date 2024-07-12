/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:30:44 by chrhu             #+#    #+#             */
/*   Updated: 2024/07/12 15:48:24 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;

	if (argc > 1)
	{
		while (++i < argc && argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] >= 97 &&argv[i][j] <= 122)
					argv[i][j] -=32;
				j++;
			}
			std::cout << argv[i];
		}
		std::cout << "" << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}

