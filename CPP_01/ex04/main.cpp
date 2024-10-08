/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:02:23 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/08 17:23:02 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void replaceString(std::string &line, const std::string &s1, const std::string &s2);

int main(int ac, char **av) {
    std::string line;
    std::string fileName;
    std::string newFile;

    if (ac == 4) {
		fileName = av[1];
        std::ifstream inputFile(av[1]);
        if (inputFile.is_open()) {
            newFile += fileName + ".replace";

            std::ofstream outputFile(newFile.c_str());
            if (!outputFile.is_open()) {
                std::cout << "Can't create the output file: " << newFile << std::endl;
                return 1;
            }

            while (std::getline(inputFile, line)) {
                replaceString(line, av[2], av[3]);
                outputFile << line << std::endl;
            }

            inputFile.close(); 
            outputFile.close();
        } else {
            std::cout << "Can't open this file: " << fileName << std::endl;
            return 1;
        }
    } else {
        std::cout << "Usage: " << av[0] << " <filename> <string> <replacestring>" << std::endl;
    }
    return 0;
}

// Replace string
void replaceString(std::string &line, const std::string &s1, const std::string &s2) {
    std::string newLine;
    size_t i = 0;
    size_t found;

    while ((found = line.find(s1, i)) != std::string::npos) {
        newLine += line.substr(i, found - i);
        newLine += s2;
        i = found + s1.length();
    }
    newLine += line.substr(i);
    line = newLine;
}
