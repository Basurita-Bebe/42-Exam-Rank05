# Exam Rank 05 — study repo

My prep for the 42 exam rank 05. Subjects and given files come from
[flmarsou/42nice-exam05](https://github.com/flmarsou/42nice-exam05). No reference solutions in here: everything in `my_solution/` is written by me.

## Method (per exercise)
1. Read only `subject.txt` + given main → reframe the problem in `NOTES.md`
2. List the key concepts with short explanations
3. Build the solution step by step in `my_solution/`
4. Test myself with questions and micro-exercises
5. Redo from scratch under exam conditions until it's automatic

## Progress
| # | Exercise | Lang | Understood | Built | Redone from scratch | Exam-ready |
|---|----------|------|:---:|:---:|:---:|:---:|
| 1 | [vect2](01_vect2)     | C++ | ☐ | ☐ | ☐ | ☐ |
| 2 | [bigint](02_bigint)   | C++ | ☐ | ☐ | ☐ | ☐ |
| 3 | [polyset](03_polyset) | C++ | ☐ | ☐ | ☐ | ☐ |
| 4 | [life](04_life)       | C   | ☐ | ☐ | ☐ | ☐ |

## Layout
```
0X_name/
├── subject.txt      # the subject, untouched
├── main*.cpp/given/ # files provided by the exam (bigint's main has extra debug output)
├── my_solution/     # my code
└── NOTES.md         # reframe, concepts, build log, self-test, attempts
```

## Compile
```sh
# C++ exercises (run inside the exercise folder)
c++ -Wall -Wextra -Werror -std=c++98 -I my_solution my_solution/*.cpp main.cpp
# life
gcc -Wall -Wextra -Werror my_solution/*.c -o life
```
