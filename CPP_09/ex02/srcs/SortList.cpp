/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:58 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/05 17:23:47 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// Recursive Sort Maxima
void PMergeMe::recursiveSortMaxima(std::list<std::pair<int, int> >& pairsList) {
    if (pairsList.size() <= 1) {
        return;
    }

    // Split list into two parts (left and right)
    std::list <std::pair<int, int> >::iterator mid = pairsList.begin();
    std::advance(mid, pairsList.size() / 2); // Déplacer l'itérateur à la position du milieu
    std::list<std::pair<int, int> > left(pairsList.begin(), mid);
    std::list<std::pair<int, int> > right(mid, pairsList.end());
    
    // Recursive calls
    recursiveSortMaxima(left);
    recursiveSortMaxima(right);

    std::list<std::pair<int, int> > result;
    std::list<std::pair<int, int> >::iterator leftIt = left.begin();
    std::list<std::pair<int, int> >::iterator rightIt = right.begin();

    // Merge elements
    while (leftIt != left.end() && rightIt != right.end()) {
        if (leftIt->second < rightIt->second) {
            result.push_back(*leftIt);
            leftIt++;
        } else {
            result.push_back(*rightIt);
            rightIt++;
        }
    }

    // Insert remaining elements
    result.splice(result.end(), left);
    result.splice(result.end(), right);

    pairsList = result;
}

// Jacobsthal 
std::list<int> PMergeMe::jacobsthal(std::list<std::pair<int, int> > &pairs) {
    // Fill main and pending list
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    
    for (; it != pairs.end(); ++it) {
        if (it->second != 0) {
            _mainList.push_back(it->second);
        }
        _pendingList.push_back(it->first);
    }

    // Insert first pending list
    _mainList.push_front(_pendingList.front());

    // Calculate Jacobsthal distance and add to list
    std::list<int> jacobsthalList;
    for (int i = 3; i < 15; ++i) {
        jacobsthalList.push_back(jacobsthalDistance(i));
    }
    return jacobsthalList;
}

// Insert Pending with Binary Search
void PMergeMe::insertMinimaBinarySearch(std::list<int> jacobsthalList) {
    size_t end = 0;
    size_t start = 0;

    std::list<int>::iterator pendingIt = _pendingList.begin();
    std::list<int>::iterator it = jacobsthalList.begin();
    for (; it != jacobsthalList.end() && pendingIt != _pendingList.end(); ++it) {
        end += *it;
        start = end - *it + 1;

        if (end >= _pendingList.size()) {
            end = _pendingList.size() - 1;
        }

        // Calculer la taille de la portion restante de la liste après `end + 1`
        size_t subList = 0;
        if (end + 1 < _pendingList.size()) {
            // Utiliser des itérateurs pour calculer la distance entre `end + 1` et la fin de la liste
            std::list<int>::iterator itEndPlusOne = _pendingList.begin();
            std::advance(itEndPlusOne, end + 1);  // Avancer jusqu'à `end + 1`

            subList = std::distance(itEndPlusOne, _pendingList.end());  // Distance jusqu'à la fin de la liste
        }

        // Insertion dans la liste principale
        if (start <= end) {
            for (size_t j = end; j > start; --j) {
                std::list<int>::iterator targetIt = _pendingList.begin();
                std::advance(targetIt, j);
                int target = *targetIt;
                
                std::list<int>::iterator left = _mainList.begin();
                std::list<int>::iterator right = _mainList.end();
                
                // Recherche binaire
                while (left != right) {
                    std::list<int>::iterator mid = left;
                    std::advance(mid, std::distance(left, right) / 2);
                    if (*mid < target) {
                        std::advance(mid, 1);
                        left = mid;
                    } else {
                        right = mid;
                    }
                }
                _mainList.insert(left, target);
            }
        }
    }
}


// Sort Ford Johnson
void PMergeMe::sortFordJohnson(std::list<std::pair<int, int> > &pairsList){
    recursiveSortMaxima(pairsList);
    
    // Insert if is impair
    if (!_impairNbrList.empty()) {
        pairsList.push_back(_impairNbrList.front());
    }

    insertMinimaBinarySearch(jacobsthal(pairsList));
}
