/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <bbeceiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 16:34:40 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/10/27 16:52:04 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

set::set(searchable_bag &bag) : bag(bag) {}

set::set(const set &other) : bag(other.bag) {}

set &set::operator=(const set &other) {
    (void)other;
    return (*this);
}

set::~set() {}

void    set::insert(int value) {
    if (!bag.has(value))
        bag.insert(value);
}

void    set::insert(int *array, int size) {
    for (int i = 0; i < size; i++)
        insert(array[i]);
}

bool    set::has(int value) const { return (bag.has(value)); }

void    set::print() const { bag.print(); }

void    set::clear() { bag.clear(); }

const searchable_bag &set::get_bag() const { return bag; }