/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:03:29 by chrhu             #+#    #+#             */
/*   Updated: 2024/12/04 17:26:10 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

int main () {
	srand(time(NULL));

	Base *obj = generate();

	// By pointer
	identify(obj);

	// By reference
    identify(*obj);

	delete obj;
	return 0;
}
