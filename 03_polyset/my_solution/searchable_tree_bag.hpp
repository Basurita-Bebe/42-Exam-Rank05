/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <bbeceiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 17:27:08 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/10/23 17:30:27 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag {
    public:
        searchable_tree_bag();
        searchable_tree_bag(const searchable_tree_bag &other);
        searchable_tree_bag &operator=(const searchable_tree_bag &other);
        ~searchable_tree_bag();
        
        bool has(int value) const;
};

#endif