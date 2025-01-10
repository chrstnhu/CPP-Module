/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:00:55 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/10 11:49:26 by chrhu            ###   ########.fr       */
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
        std::ostringstream oss;
        oss << "Element not found at index " << index;
        throw std::invalid_argument(oss.str());
    }
}