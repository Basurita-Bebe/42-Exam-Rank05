/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brrr1 <brrr1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:06:10 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/10/29 10:52:28 by brrr1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** How to compile (run from 01_vect2/):
**   c++ -Wall -Wextra -Werror -std=c++98 -I my_solution main.cpp my_solution/vect2.cpp -o vect2
**   ./vect2
*/

#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
	private:
		int _x;
		int _y;
	public:
		vect2();
        vect2(int x, int y);
        vect2(const vect2& source);
        vect2& operator=(const vect2& source);
        ~vect2();

        // Access
        int operator[](int index) const;
        int &operator[](int index);

        // Increment and decrement
        vect2   &operator++();    // ++x
        vect2   operator++(int);  // x++
        vect2   &operator--();    // --x
        vect2   operator--(int);  // x--

        // Arithmetic
        vect2   operator+(const vect2& rhs) const;
        vect2   &operator+=(const vect2& rhs);
        vect2   operator-(const vect2& rhs) const;
        vect2   &operator-=(const vect2& rhs);
        vect2   operator*(int scalar) const;
        vect2   &operator*=(int scalar);

        // Unary minus
        vect2   operator-() const;

        // Comparison
        bool    operator==(const vect2& rhs) const;
        bool    operator!=(const vect2& rhs) const;
};

vect2   operator*(int scalar, const vect2 &rhs);

std::ostream& operator<<(std::ostream& os, const vect2 &rhs);

#endif
