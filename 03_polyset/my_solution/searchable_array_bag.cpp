/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <bbeceiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:22:39 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/10/23 17:26:30 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() : array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other) : array_bag(other) {}

searchable_array_bag &searchable_array_bag::operator=(const searchable_array_bag &other) {
    if (this != &other)
        array_bag::operator=(other);
    return (*this);
}

searchable_array_bag::~searchable_array_bag() {}

bool searchable_array_bag::has(int value) const {
    for (int i = 0; i < size; i++)
        if (data[i] == value)
            return (true);
    return (false);
}