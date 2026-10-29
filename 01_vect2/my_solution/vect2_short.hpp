/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2_short.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brrr1 <brrr1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:59:46 by brrr1             #+#    #+#             */
/*   Updated: 2026/10/29 10:59:51 by brrr1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class vect2
{
	int v[2];

public:
	vect2(int x = 0, int y = 0) { v[0] = x; v[1] = y; }

	int &operator[](int i) { return v[i]; }
	int operator[](int i) const { return v[i]; }

	vect2 &operator+=(const vect2 &o) { v[0] += o.v[0]; v[1] += o.v[1]; return *this; }
	vect2 &operator-=(const vect2 &o) { v[0] -= o.v[0]; v[1] -= o.v[1]; return *this; }
	vect2 &operator*=(int n) { v[0] *= n; v[1] *= n; return *this; }

	vect2 operator+(const vect2 &o) const { return vect2(*this) += o; }
	vect2 operator-(const vect2 &o) const { return vect2(*this) -= o; }
	vect2 operator*(int n) const { return vect2(*this) *= n; }
	vect2 operator-() const { return vect2(-v[0], -v[1]); }

	vect2 &operator++() { return *this += vect2(1, 1); }
	vect2 &operator--() { return *this -= vect2(1, 1); }
	vect2 operator++(int) { vect2 t(*this); ++*this; return t; }
	vect2 operator--(int) { vect2 t(*this); --*this; return t; }

	bool operator==(const vect2 &o) const { return v[0] == o.v[0] && v[1] == o.v[1]; }
	bool operator!=(const vect2 &o) const { return !(*this == o); }
};

vect2 operator*(int n, const vect2 &v);
std::ostream &operator<<(std::ostream &os, const vect2 &v);
