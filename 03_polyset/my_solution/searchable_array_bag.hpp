/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <bbeceiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:19:08 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/10/23 17:22:07 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// How to compile (run from 03_polyset/):
//   clang++ -Wall -Wextra -Werror -std=c++11 -I given -I my_solution given/*.cpp my_solution/*.cpp -o polyset
//   ./polyset 1 2 3
// The given files use nullptr and (int[]){...}: C++11, and only clang accepts that main.
// No clang? sudo apt install clang

#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag {
    public:
        searchable_array_bag();
        searchable_array_bag(const searchable_array_bag &other);
        searchable_array_bag &operator=(const searchable_array_bag &other);
        ~searchable_array_bag();
        
        bool has(int value) const;
};

#endif