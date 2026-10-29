# vect2 — study notes

## 1. Reframe the problem
- I have to create a class with two int components (x and y) that I can read and wright through v[0] and v[1].
- Have to submmit two files vect2.hpp and vect2.cpp.
- Everything that the class must support:
    - *Constructing:*
        - vect2 v1;             // no arguments -> default constructor, sets {0, 0}
        - vect2 v2(1, 2);       // two ints -> constructor taking (int x, int y)
        - const vect2 v3(v2);   // from another vect2 -> copy constructor
        - vect2 v4 = v2;        // also the copy constructor (it's a creation, not an assignment).
        - v2 = v3 + v3 * 2;     // v2 already exists -> assignment operator=
    - *Invrement and decrement:*
    ++v, v++, --v, v-- are four separeted operators. They add or substract 1 on both components: {1, 2} becomes {2, 3}.
    - *Compound assignment:*
    +=, -=, *=. They change the vector itself.
    - *Arithmetic:*
    v + v, v - v, v * int, int * v. They return a new vectorand leave the original untouched. Why 3 * v2 can't be a member: a member operator always has my object to the left. v3 * 2 becomes v3.operator*(2), which is fine. With 3 * v2, the left side is an int, and we can't add methods to int. So that must be a function outside the class:
        - vect2 operator*(int n, const vect2 &v);
    - *Unary minus:*
    -v2 returns a new vector with both components negated: {20, 40} becomes {-20, -40}.
    - *Comparision:*
    == and != compare both components.
    - *Acces []:*
    v1[1] = 12 writes, so [] must return a reference (int&) to the component. v3 is const, so calling non-const method on it won't compile. We need two versions:
        - int   &operator[](int i);             // for normal vectors: read + write.
        - const int &operator[](int i) const;   // for const vectors: read only.
    - *Printing:*
    operator<< must also live outside the class, for the same reason as 3 * v: the left side is std::cout, not my object.

## 2. Key concepts
<!-- Concept → short explanation → tiny example -->

## 3. Build log
<!-- Steps I took, bugs I hit, how I fixed them -->

## 4. Self-test
<!-- Questions / micro-exercises and my answers -->

## Attempts
| Date | Time taken | From scratch? | Passed? | Notes |
|------|------------|---------------|---------|-------|
|------|------------|---------------|---------|-------|
|------|------------|---------------|---------|-------|
|------|------------|---------------|---------|-------|


## Compile & run
c++ -Wall -Wextra -Werror -std=c++98 -I my_solution main.cpp my_solution/vect2.cpp -o vect2

./vect2
