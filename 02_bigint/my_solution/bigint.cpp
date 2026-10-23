/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeceiro <bbeceiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:08:46 by bbeceiro          #+#    #+#             */
/*   Updated: 2026/10/23 16:58:44 by bbeceiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.hpp"

bigint::bigint() : _digits("0") {}

bigint::bigint(unsigned long num) {
    std::stringstream ss;
    ss << num;
    _digits = ss.str();
}

bigint::bigint(const bigint &other) {
    *this = other;
}

bigint &bigint::operator=(const bigint &other) {
    if (this != &other)
        _digits = other._digits;
    return (*this);
}

bigint::~bigint() {}

static unsigned int strToUint(std::string str) {
    std::stringstream ss(str);
    unsigned int result = 0;
    ss >> result;
    return (result);
}

void bigint::normalize() {
    std::size_t pos = _digits.find_first_not_of('0');
    if (pos == std::string::npos)
        _digits = "0";
    else if (pos > 0)
        _digits.erase(0, pos);
}

const std::string &bigint::getDigits() const {
    return (_digits);
}

bigint &bigint::operator+=(const bigint &other) {
    std::string result = "";
    int carry = 0;
    int sum;
    int lefNum;
    int rigNum;
    int i = static_cast<int>(_digits.size()) - 1;
    int j = static_cast<int>(other._digits.size()) - 1;
    while (i >= 0 || j >= 0 || carry != 0) {
        lefNum = (i >= 0) ? _digits[i--] - '0' : 0;
        rigNum = (j >= 0) ? other._digits[j--] - '0' : 0;
        sum = lefNum + rigNum + carry;
        result.insert(result.begin(), static_cast<char>('0' + (sum % 10)));
        carry = sum / 10;
    }
    _digits = result;
    normalize();
    return (*this);
}

bigint bigint::operator+(const bigint &other) const {
    bigint result(*this);
    result += other;
    return (result);
}

bigint &bigint::operator++() {
    *this += 1;
    return (*this);
}

bigint bigint::operator++(int) {
    bigint copy(*this);
    ++(*this);
    return (copy);
}

bigint &bigint::operator<<=(unsigned int shift) {
    if (_digits != "0")
        _digits.append(shift, '0');
    return (*this);
}

bigint &bigint::operator<<=(const bigint &shift) {
    *this <<= strToUint(shift._digits);
    return (*this);
}

bigint bigint::operator<<(unsigned int shift) const {
    bigint result(*this);
    return (result <<= shift);
}

bigint bigint::operator<<(const bigint &shift) const {
    bigint result(*this);
    return (result <<= shift);
}

bigint &bigint::operator>>=(unsigned int shift) {
	if (shift >= _digits.size())
		_digits = "0";
	else
		_digits.erase(_digits.size() - shift);
	return (*this);
}

bigint &bigint::operator>>=(const bigint &shift) {
	*this >>= strToUint(shift._digits);
	return (*this);
}

bigint bigint::operator>>(unsigned int shift) const {
	bigint result(*this);
	return (result >>= shift);
}

bigint bigint::operator>>(const bigint &shift) const {
	bigint result(*this);
	return (result >>= shift);
}

bool bigint::operator<(const bigint &other) const {
	if (_digits.size() != other._digits.size())
		return (_digits.size() < other._digits.size());
	return (_digits < other._digits);
}

bool bigint::operator<=(const bigint &other) const {
	return (!(*this > other));
}

bool bigint::operator>(const bigint &other) const {
	return (other < *this);
}

bool bigint::operator>=(const bigint &other) const {
	return (!(*this < other));
}

bool bigint::operator==(const bigint &other) const {
	return (_digits == other._digits);
}

bool bigint::operator!=(const bigint &other) const {
	return (!(*this == other));
}

std::ostream &operator<<(std::ostream &out, const bigint &num) {
	out << num.getDigits();
	return (out);
}