/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_12.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:00:30 by chrhu             #+#    #+#             */
/*   Updated: 2025/01/24 14:12:00 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <deque>
# include "../includes/PmergeMe.hpp"

void recursiveSortMaxima(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1) {
        return;
    }

    size_t mid = pairs.size() / 2;
    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());

    recursiveSortMaxima(left);
    recursiveSortMaxima(right);

    std::deque<std::pair<int, int> > result;
    size_t leftIndex = 0;
    size_t rightIndex = 0;

    while (leftIndex < left.size() && rightIndex < right.size()) {
        if (left[leftIndex].second < right[rightIndex].second) {
            result.push_back(left[leftIndex]);
            leftIndex++;
        } else {
            if (right[rightIndex].second != 0) {
                result.push_back(right[rightIndex]);
            }
            rightIndex++;
        }
    }

    while (leftIndex < left.size()) {
        result.push_back(left[leftIndex]);
        leftIndex++;
    }
    while (rightIndex < right.size()) {
        result.push_back(right[rightIndex]);
        rightIndex++;
    }

    pairs = result;
}

// Insert Minima with Binary Search
void insertMinimaBinarySearch(std::vector<int>& maxima, std::vector<int>& minima) {

    // Insert the first minima at the front
    maxima.insert(maxima.begin(), minima[0]);

    // Find the position of minima in the maxima vector
    for (size_t index = 1; index < minima.size(); ++index) {
        int target = minima[index];

        std::vector<int>::iterator pos = std::lower_bound(maxima.begin(), maxima.end(), target);

        maxima.insert(pos, target);
    }
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << RED "Usage : ./PmergeMe [multiple number]" DEF << std::endl;
    }
    
    std::vector<int> vec;
    
    for(int i = 1; i < ac; i++) {
        int number;
        std::stringstream ss(av[i]);

        ss >> number;

        if (ss.fail() || number < 0) {
            std::cerr << RED "Error" DEF << std::endl;
            return 1;
        }
        else {
            vec.push_back(number);
        }
    }

    std::cout << YELLOW "Before:  " DEF;
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i += 2) {
        if (i + 1 < vec.size()) {
            if (vec[i] < vec[i + 1]) {
                pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
            }
            else {
                pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
            }
        } else {
            pairs.push_back(std::make_pair(vec[i], 0));
        }
    }

    recursiveSortMaxima(pairs);

    std::vector<int> maxima;
    std::vector<int> minima;
    for (size_t i = 0; i < pairs.size(); i++) {
            maxima.push_back(pairs[i].second);
            minima.push_back(pairs[i].first);
    }

    insertMinimaBinarySearch(maxima, minima);
    
    // Afficher les éléments du deque après insertion
    std::cout << YELLOW << "After:   " DEF;
    for (size_t i = 0; i < maxima.size(); i++) {
        std::cout << maxima[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
