/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:30 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/24 17:19:17 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// GETTERS
std::vector<int> &PMergeMe::getPairsVec() {
    return _pairsVec;
}

std::vector<int>&PMergeMe::getMaximaVec() {
    return _maximaVec;
}

// METHODS
void PMergeMe::savePairsVec(int ac, char **av) {
    for (int i = 1; i < ac; i += 2) {
        char* end;
        int first = std::strtol(av[i], &end, 10);
        if (i + 1 < ac) {
            int second = std::strtol(av[i + 1], &end, 10);
            if (first < second) {
                _pairsVec.push_back(first);
                _pairsVec.push_back(second);
            }
            else {
                _pairsVec.push_back(second);
                _pairsVec.push_back(first);
            }
        } else {
            _pairsVec.push_back(first);
        }
    }
}

// Recursive Sort Maxima
void PMergeMe::recursiveSortMaxima(std::vector<int> &pairsVec) {
    if (pairsVec.size() <= 1) {
        return;
    }

    size_t mid = pairsVec.size() / 2;
    std::vector<int> left(pairsVec.begin(), pairsVec.begin() + mid);
    std::vector<int> right(pairsVec.begin() + mid, pairsVec.end());

    recursiveSortMaxima(left);
    recursiveSortMaxima(right);

    std::vector<int> result;
    size_t leftIndex = 0;
    size_t rightIndex = 0;

    // Fusion des éléments avec comparaison selon les indices impairs
    while (leftIndex < left.size() && rightIndex < right.size()) {
        // Comparer les éléments aux indices impairs
        if (leftIndex % 2 != 0 && rightIndex % 2 != 0) {
            if (left[leftIndex] < right[rightIndex]) {
                result.push_back(left[leftIndex]);
                leftIndex++;
            } else {
                result.push_back(right[rightIndex]);
                rightIndex++;
            }
        } else {
            if (leftIndex % 2 != 0) {
                result.push_back(left[leftIndex]);
                leftIndex++;
            }
            if (rightIndex % 2 != 0) {
                result.push_back(right[rightIndex]);
                rightIndex++;
            }
        }
    }

    while (leftIndex < left.size()) {
        if (leftIndex % 2 != 0) {  // Ajout des éléments aux indices impairs
            result.push_back(left[leftIndex]);
        }
        leftIndex++;
    }

    while (rightIndex < right.size()) {
        if (rightIndex % 2 != 0) {  // Ajout des éléments aux indices impairs
            result.push_back(right[rightIndex]);
        }
        rightIndex++;
    }

    pairsVec = result;
}

// Insert Minima with Binary Search
void PMergeMe::insertMinimaBinarySearch(std::vector<int> &pairsVec) {
    // Remplir les vecteurs maxima et minima à partir de pairsVec
    for (size_t index = 0; index < pairsVec.size(); ++index) {
        if (index % 2 == 0) {  // Indices pairs (0, 2, 4, 6, ...)
            _minimaVec.push_back(pairsVec[index]);  // Ajouter à minima
        } else {  // Indices impairs (1, 3, 5, 7, ...)
            _maximaVec.push_back(pairsVec[index]);  // Ajouter à maxima
        }
    }

    // Insertion des éléments de minima dans maxima en maintenant l'ordre croissant
    for (size_t index = 1; index < _minimaVec.size(); ++index) {
        int target = _minimaVec[index];

        // Trouver la position où insérer dans le vecteur 'maxima' pour maintenir l'ordre croissant
        std::vector<int>::iterator pos = std::lower_bound(_maximaVec.begin(), _maximaVec.end(), target);
        _maximaVec.insert(pos, target);
    }
}

void PMergeMe::printPairsVec() {
    for (size_t i = 0; i < _maximaVec.size(); i++) {
            std::cout << _maximaVec[i] << " ";
        }
    std::cout << std::endl;
}