/*
** How to compile (run from 02_bigint/):
**   c++ -Wall -Wextra -Werror -std=c++98 -I my_solution main_test.cpp my_solution/bigint.cpp -o bigint
**   ./bigint
*/

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>

class bigint {
    private:
        std::string _digits;
        void normalize();
    public:
        bigint();
        bigint(unsigned long num);
        bigint(const bigint &other);
        bigint &operator=(const bigint &other);
        ~bigint();

        // Arithmetic operators
        bigint &operator+=(const bigint &other);
        bigint operator+(const bigint &other) const;
        bigint &operator++();
        bigint operator++(int);

        // Comparison operators
        bool operator<=(const bigint &other) const;
        bool operator<(const bigint &other) const;
        bool operator>=(const bigint &other) const;
        bool operator>(const bigint &other) const;
        bool operator==(const bigint &other) const;
        bool operator!=(const bigint &other) const;

        // Bitwise shift operators
        bigint &operator<<=(unsigned int shift);
        bigint &operator<<=(const bigint &shift);
        bigint operator<<(unsigned int shift) const;
        bigint operator<<(const bigint &shift) const;
        bigint &operator>>=(unsigned int shift);
        bigint &operator>>=(const bigint &shift);
        bigint operator>>(unsigned int shift) const;
        bigint operator>>(const bigint &shift) const;

        const std::string &getDigits() const;

};

std::ostream &operator<<(std::ostream &out, const bigint &num);

#endif