/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhu <chrhu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:21:42 by chrhu             #+#    #+#             */
/*   Updated: 2024/10/17 18:32:23 by chrhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(0), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
}

ClapTrap::~ClapTrap() {
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		_name = ;
		_hitPoint = ;
		_energyPoint = ;
		_attackDamage = ;
	}
	return *this;
}

/*
attack function()
print : ClapTrap <name> attacks <target>, causing <damage> points of damage!
*/