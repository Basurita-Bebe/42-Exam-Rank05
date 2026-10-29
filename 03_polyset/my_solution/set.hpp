// How to compile (run from 03_polyset/):
//   clang++ -Wall -Wextra -Werror -std=c++11 -I given -I my_solution given/*.cpp my_solution/*.cpp -o polyset
//   ./polyset 1 2 3
// The given files use nullptr and (int[]){...}: C++11, and only clang accepts that main.
// No clang? sudo apt install clang

#ifndef SET_HPP
#define SET_HPP

#include "searchable_bag.hpp"

class set {
    private:
        searchable_bag  &bag;
        set();                  // no default, a set must always wrap a bag
    public:
        set(searchable_bag &bag);
        set(const set &other);
        set &operator=(const set &other);
        ~set();

        void    insert(int value);
        void    insert(int *array, int size);
        bool    has(int value) const;
        void    print() const;
        void    clear();

        const   searchable_bag  &get_bag() const;
};

#endif