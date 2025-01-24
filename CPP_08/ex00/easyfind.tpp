/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:00:55 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/16 16:07:31 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"

template <typename T>
void easyfind(T &container, int n) {
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    
    int index = std::distance(container.begin(), it);
    if (it != container.end()) {
        std::cout << GREEN << "Element found: '" << *it
                << "' at index " << index << DEF << std::endl;
    }
    else {
        throw std::invalid_argument("Element not found");
    }
}