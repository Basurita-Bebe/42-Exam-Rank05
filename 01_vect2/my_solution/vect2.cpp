/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <bbeceiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:06:03 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/10/22 19:28:23 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vect2.hpp"

vect2::vect2() {
    this->_x = 0;
    this->_y = 0;
}

vect2::vect2(int x, int y) : _x(x), _y(y) {
}

vect2::vect2(const vect2 &source) {
    *this = source;
}

vect2& vect2::operator=(const vect2 &source) {
    if (this != &source) {
        this->_x = source._x;
        this->_y = source._y;
    }
    return *this;
}

vect2::~vect2() {
    // Destructor implementation (if needed)
}

int vect2::operator[](int index) const {return index == 0 ? _x : _y;}
int &vect2::operator[](int index) {return index == 0 ? _x : _y;}

vect2   &vect2::operator++() {
    ++_x;
    ++_y;
    return (*this);
}

vect2   vect2::operator++(int) {
    vect2   copy(*this);
    ++_x;
    ++_y;
    return (copy);
}

vect2   &vect2::operator--() {
    --_x;
    --_y;
    return (*this);
}

vect2   vect2::operator--(int) {
    vect2   copy(*this);
    --_x;
    --_y;
    return (copy);
}

vect2   vect2::operator+(const vect2 &rhs) const {
    vect2   result(*this);
    result._x += rhs._x;
    result._y += rhs._y;
    return (result);
}

vect2   &vect2::operator+=(const vect2 &rhs) {
    _x += rhs._x;
    _y += rhs._y;
    return (*this);
}

vect2   vect2::operator-(const vect2 &rhs) const {
    vect2   result(*this);
    result._x -= rhs._x;
    result._y -= rhs._y;
    return (result);
}

vect2   &vect2::operator-=(const vect2 &rhs) {
    _x -= rhs._x;
    _y -= rhs._y;
    return (*this);
}

vect2   vect2::operator*(int scalar) const {
    vect2   result(*this);
    result._x *= scalar;
    result._y *= scalar;
    return (result);
}

vect2   &vect2::operator*=(int scalar) {
    _x *= scalar;
    _y *= scalar;
    return (*this);
}

vect2   vect2::operator-() const {
    vect2   temp(*this);
    temp._x = -temp._x;
    temp._y = -temp._y;
    return (temp);
}

bool    vect2::operator==(const vect2 &rhs) const { return (_x == rhs._x && _y == rhs._y); }
bool    vect2::operator!=(const vect2 &rhs) const { return (_x != rhs._x || _y != rhs._y); }

vect2   operator*(int scalar, const vect2 &rhs) {
    vect2   result(rhs);
    result *= scalar;
    return (result);
}

std::ostream    &operator<<(std::ostream &out, const vect2 &rhs) {
    out << "{" << rhs[0] << ", " << rhs[1] << "}";
    return (out);
}

