/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortDequeSimple.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:58 by chrhu             #+#    #+#             */
/*   Updated: 2025/02/05 16:28:35 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// Jacobsthal 
std::deque<int> PMergeMe::jacobsthal(std::deque<std::pair<int, int> > &pairsDeque) {
    // Fill main and pending deque
    for (size_t index = 0; index < pairsDeque.size(); ++index) {
        if (pairsDeque[index].second != 0) {
            _mainDeque.push_back(pairsDeque[index].second);
        }
        _pendingDeque.push_back(pairsDeque[index].first);
    }

    // Insert first pending deque
    _mainDeque.push_front(_pendingDeque[0]);

    std::deque<int> jacobsthalDeque;

    // Calculate Jacobsthal distance and add to deque
    for (int i = 3; i < 15; ++i) {
        jacobsthalDeque.push_back(jacobsthalDistance(i));
    }
    return jacobsthalDeque;
}

// Insert Minima with Binary Search
void PMergeMe::insertMinimaBinarySearch(std::deque<int> jacobsthalDeque) {
    size_t end = 0;
    size_t start = 0;

    for (size_t i = 0; i < jacobsthalDeque.size() && ! _pendingDeque.empty(); i++) {
        end = end + jacobsthalDeque[i];
        start = end - jacobsthalDeque[i] + 1;

		if (end >= _pendingDeque.size()) {
			end = _pendingDeque.size() - 1;
        }

        // Insert pending deque to main deque        
        for (size_t j = end; j >= start; j--) {
            size_t subDeque = _mainDeque.size() - (_pendingDeque.size() - (end + 1));
            int target = _pendingDeque[j];
            std::deque<int>::iterator pos = std::lower_bound(_mainDeque.begin(), _mainDeque.begin() + subDeque, target);
            _mainDeque.insert(pos, target);
        }
    }
}

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second; // Adjust the comparison logic as needed
}

// Sort Ford Johnson
void PMergeMe::sortFordJohnson(std::deque<std::pair<int, int> > &pairsDeque){
    // Sort second number
    std::sort(pairsDeque.begin(), pairsDeque.end(), comparePairs);
    
    // Insert if is impair
    if (!_impairNbrDeque.empty()) {
        pairsDeque.push_back(_impairNbrDeque[0]);
    }
    
    insertMinimaBinarySearch(jacobsthal(pairsDeque));
}
