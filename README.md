# Push_swap

> *"Is push_swap really as simple as it seems?"*

A 42 algorithmic project that challenges you to sort data in a stack using a limited set of instructions, aiming for the lowest possible number of operations!

## 📋 Structure of Contents

- [About the Project](#About-the-Project)
- [Implemented Algorithm](#Implemented-algorithm)
- [Available Operations](#Available-Operations)
- [Compilation](#Compilation)
- [How to Use](#How-to-Use)
- [Benchmarks](#Benchmarks)
- [Visualizers](#Visualizers)
- [Project Structure](#Project-Structure)
- [Useful Resources](#Useful-Resources)
- [Contributing](#Contributing)

## 🎯 About the Project

**push_swap** is a project that involves sorting a stack of integers using only two stacks (a and b) and a specific set of operations. The challenge is in finding the most efficient sequence of moves.

### Objectives

- Deep understanding of some sorting algorithms.
- Algorithmic complexity analysis and implementation.
- Data structure manipulation (stacks/linked lists).



## 🧮 Implemented algorithm

The solution uses a **hybrid approach inspired by Radix Sort with chunk division**, specifically optimized for the 42 *push_swap* and to be one of the easiest algorithm implementations aimed at scoring 125 points.

Initially, a radix sort was implemented, but it didn't meet the school's criteria for a perfect score, so this project was created using a doubly linked list with an adaptation using chunks in order to reach 125 points with the bonus.


### Main Strategy

#### 1. **Indexing by Position**
Before sorting, each number is assigned an index based on its final position in the sorted sequence:
- The smallest number gets index 0
- The second smallest gets index 1
- And so on...

This simplifies the sorting logic by working with relative positions instead of the original values.

---
#### 2. **Chunk Division**

The algorithm divides the numbers into "chunks" and moves them strategically:

**For 100 numbers:**
- Chunk size: 15
- Numbers are pushed to stack B in groups
- Smaller numbers (in the current chunk) are rotated in B
- Larger numbers remain on top

**For 500 numbers:**
- Chunk size: 35
- Same logic, but with larger groups to optimize balance movements

#### Check the Excalidraw for a better example of the execution.
- [push_swap.excalidraw](https://excalidraw.com/#json=dAtp7vWXHduESoJWQBiss,glay8xOMjIhOPwaF1v2pJw)

```
Simple example of the process::
Stack A: [10, 8, 7, 1, 9, 5, 4, 3, 2, 6] → Position: [9, 7, 6, 0, 8, 4, 3, 2, 1, 5]

Chunk 0–14: Move numbers with position < 15
├─ If position < i: pb + rb (push and rotate)
├─ If position < i+chunk_size: pb (just push)
└─ If position >= i+chunk_size: ra (rotate A)
```
---
#### 3. **Optimized Reconstruction (push_back_sorted)**

After all the numbers are in stack B, the algorithm:

1 - Finds the largest number in B (highest position)  
2 - Calculate if it's faster to rotate or reverse rotate  
3 - Moves the largest number to the top of B  
4 - Execute `pa` to push it back to A  
5 - Repeats until B is empty

### Special Cases

**2 numbers:** just sa number.  
**3 numbers:** Specific algorithm (hard code covering all cases)  
**4-5 numbers:** Push the smallest value(s) to B, sort 3 in A, then push back

---
## 🔧 Available Operations

### Swap
- **sa**: Swap the first two elements at the top of stack A
- **sb**: Swap the first two elements at the top of stack B
- **ss**: Execute sa and sb respectively

### Push
- **pa**: Takes the top element from stack B and places it on top of stack A.
- **pb**: Takes the top element from stack A and places it on top of stack B.

### Rotate (move all elements up, first becomes last)
- **ra**: Rotate stack A upwards
- **rb**: Rotate stack B upwards
- **rr**: Execute ra and rb respectively

### Reverse Rotate (move all elements down, last becomes first)
- **rra**: Reverse rotate stack A
- **rrb**: Reverse rotate stack B
- **rrr**: Execute rra and rrb respectively

## 🛠️ Compilation

### Main Program (*push_swap*)

```bash
make
```

Generates the `./push_swap` executable.

### Bonus Program (checker)

```bash
make bonus
```

Generates the `./checker` executable to verify if a sequence of operations correctly sorts the stack.

### Cleaning

```bash
make clean   # Removes object files
make fclean  # Removes executables and object files
make re      # Recompiles everything
```

## 🚀 How to Use

### Push_swap

#### View operations in the terminal:

```bash
# See all operations performed
./push_swap 2 1 3 6 5 8

# Count number of operations
./push_swap 2 1 3 6 5 8 | wc -l
```

#### Test with random numbers:

```bash
# 100 random numbers - display operations
./push_swap $(seq 1 100 | shuf | tr '\n' ' ')

# 100 random numbers - count operations
./push_swap $(seq 1 100 | shuf | tr '\n' ' ') | wc -l

# 500 random numbers - count operations
./push_swap $(seq 1 500 | shuf | tr '\n' ' ') | wc -l
```

#### Run multiple times and see statistics:

```bash
# Run 10 times and display the number of operations
for i in {1..10}; do ./push_swap $(seq 1 100 | shuf | tr '\n' ' ') | wc -l; done
```

### Checker (Bonus)

The checker validates whether a sequence of operations correctly sorts the stack.

#### Basic usage:

```bash
# Should return "OK" if sorted correctly
arg=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $arg | ./checker $arg

# Test with 500 numbers
arg=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $arg | ./checker $arg
```

#### Manual input of operations:

```bash
# Pass the operations for the checker
./push_swap <NUMBERS WITH SPACE> | ./checker <THE SAME NUMBER WITH SPACES>

# Example:
./push_swap 10 8 7 1 9 5 4 3 2 6 | ./checker 10 8 7 1 9 5 4 3 2 6
```

#### Testing typing operations

```bash
./checker 3 2 1 0
# Type the operations (sa, pb, ra, ..)
# Press Ctrl+D to finish
# Returns "OK" if sorted, "KO" if not sorted
```

## 📊 Benchmarks

### Requirements for Passing with 100 points

| Numbers | Max Operations | Status |
|---------|----------------|--------|
| 3       | 3              |   ✅  |
| 5       | 12             |   ✅  |
| 100     | 700            |   ✅  |
| 500     | 5500           |   ✅  |

### Expected Performance

With the implemented algorithm:
- **100 numbers:** ~550-650 operations (average)
- **500 numbers:** ~4800-5200 operations (average)

## 🎨 Visualizers

For a visual experience of how the algorithm works:

### Linux with more control about the test
**[Push_swap Visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer)**

### Browser (Recommended!)
**[Push_swap Visualizer Web - Test with 500 numbers](https://codepen.io/ahkoh/full/bGWxmVz?EwFgrABAzAbAjBOAGacTRO4B2K1iRy4QjwTBIyICcAHDVVFOlJCNXnDNYnHiEh6w2zEuhDZGMbIiTBEMFNhRMU7KiHlwEsIVB7BqB6umrzQ85kMGIC5MAmQoiM-SoQ55IWkIeIQeMC0VHBgGtjy0uS0-FAycNQoFPS0lsA6YElkaFhcJAk0XmAsMSS0Mul4sIx09vRQwIzYMuyQPtDO2AZIamCWRuSSEOXQYBUamBBkcWqh-jy0LBXFCpDMHtQIAfmutPQSPKSW2uRzAfQGMPIDFITY+2gkSJCN-KkYZeJI+6Rl7mqUcg2AQyGAhUR2Zj0HA6QFQWiw+TYdCZRBjEjozSMPrQaFCbBsZpieR7RAEwb4QJdfCWMKoPGuILQTb4dBwJlEZzTYjMeJMEgkHDQGCBRZAqn7ExiBBSgh8rT8QgccicX5QPKgLZ5IkvbiCrSy5QYJKiNBaPLIbpeEVol6kxpqdVTNbUpnMThUOlccQszD0bSHVhPRUunRmQX8DTBfAte4KEKlcCOEY4QiWEbMSDKuL+pA6TTkUAkGBYcMNE0eKKseqyqBJZEQaiQGB4qgsgqkGQRRstdgkeJwepxFWcZ64yxIeJDCQvZw4gicOtPcwjdmzUfQoWwNnRojmMAvZUURwScgwNZIcTETAyA-QJ3saHbbRaYCBWRVJB4PV1l79KrwmUOjtImS7aIQqKgBoYA8NgjjpMWaxzKEPDIDI1BUIYkpaO0XA1p68R+PyCRbLQkDkqE+x5kCSzHFoUR8HyOhBkEagtiqCz3p60IIFcEAwYgYqgBUTKaCUbCGKcMhkU8KLmCctAqN8CjmmGfKoUQ-HJuYQawP63j8YEw7gM4RakJhCKoFUAmGCa-qWeyISAm+5hvvkECupO5BNog+A8Cs6Sof6FTIGe4jgKc9QBey0R-ncV4eKiTCuQYjT9iwd6Dm0IQRfwCFBEIYrqgO4gnFw-CDoJ-pCtoajUPEPm1AI96xF4+j2AqbYqA27AAs4zXtY0GgUBio7oIo+SRFgzU4PEkmuEM6qpY4KwSGopSwM49X+KRHmBH2mj0CEYBVHxAR4EM6ToHGdaJRZ5jsZoLwGd49l1alW2oVgwBFNCAmYHgmQqL8faWQEGgTW+mEsD5oDiHS8JKSou4-cKaJiGxPA2nwUUVSoWhwYgQYHgQB5k+TpPk1TFPU7TlO0wzjM09T9Mk0zbN00zrMs6z3OM40XNXH0VMC+zIt9OeXMM6LYss5LHNy7LnMU-LEtK9LwtKwLP1XHzCvi2Tess4b54EI0Mvq2rssW4rhua1bdNCw7ZvszbEuU277uSx7quWxbpP+wbjvM+rvMk-L9Oe-bru+17yuW0HKt09zosy0bnPp302vu5rKds5nFM-Q74f2+bhtR27RcxyXatV7nyfe7HodOzXJOp6rOt263afMwXCep23scpzbZfS6bSd61HicT67Ysj8bY9VxXuu+z7rfr47LsJzTlep1PIsd972tC9nxdny7x+C1nbf51nEcB6vptP7PCuB4rOt81vC8q+bTcL5PVwI7Pxrmvb+E8B6223pAi+wtf76xft3J2o9u4m1gQfYOUtj6V2AQHX+ZtvbFwAag+BadzaXw3l3Hef8RYX0brXM+0cR4dw1uHL+5cT5l0joAjm+D4Eh1oQ-fOdC46wO4bzbhP9GHj3dtnU+acCGFwIZ-Zh+c4EQM7h-E+wizZL1kdInhbdR5wJkWIhRzsZEmywXQn68ic4lzUWQiRuDAE6JkXvXBWdHH4O8R3Ixmi77txsSvKxH88G6zwWQyJLjNFhKCZErxsSXFJLBNoMEaT4B7D2IOTJ2SclpNSSk9JKTMklIRKUrJRTckIiKekqpWSymlK4PkpplTykVMKXU6pGSSktMHLk7Q-TinZKqS0+AYz8nFLaV0mpky2mjO6VM+Z4zWlzMaZM4ZCy1kzO2bUqZWzNlrNGfMzpcyanaAaac7ZTSRkzOGT0nJ1TemzLyd0m56yVk9POfc6ZBSVkDL2e0v5izam3IOY0l5YL2nHKWScnpHzLl-KOZcpZzyAVcCOVcgFwKdm3Kxfs2Z1zllnL2X0vpgKNnXO+XCwp8AyUXIRH02lCKcWwvxTsu55SUWwsJf0jlDSkVvI+Si1FnKaWMvyas9FWS6nColas6ZGSvn0ohbs+pDKiV3L5firl4KtWAtxfSpVbLVVqpVWMpV-yFXrLmeiyprKYUkvhdSllnTKX6teYc615LPmuvdc0x1xLjlYt6Y8012rnm-JNQ8o5Mr2UBo2XKkNeKflRvdW6-pzqRVmvTW65VXypVWtqSc85+bE0PMzXKz5NK-lZtzYWrNaKcXEu1cG2tLLW2BrrY8o19a9WUu5U21N3yHVooVeioNxrfUIvHSCg1yaVX-MjZCsds6nXKr9c2kl2Lq2svJYOyFeqN2DPFUS1NA7i2gpPSKk9x7TVdoxZsgpu7ZUZuZU68dZSL3mqGXO7d0KD2bryVKw9d6m1PtOaSklsqJkNrNXG8FurMUjKA16x5YGFk3plZKkFIyb0pOAwyuAQA)**

**This link is pre-configured with:**
- 500 random numbers
- A solution generated by my `push_swap`
- 4886 operations
- Step-by-step animated visualization

Just open it and click "Play" to watch the magic happening! ✨✨

## 📝 Project Structure

```
push_swap/
├── src/
│   ├── push_swap.c           # Main and list creation
│   ├── algorithm.c           # Core sorting logic
│   ├── sort_algorithm.c      # Algorithms for 100/500 numbers
│   ├── p_s_functions.c       # Push and swap operations
│   ├── rotate_functions.c    # Rotate and reverse operations
│   ├── push_swap_utils.c     # Helper functions
│   └── push_swap.h
├── src_bonus/
│   ├── checker_bonus.c       # Checker program
│   ├── checker_utils_bonus.c # Auxiliary functions
│   └── checker_bonus.h
├── libft/                    # Utility library
├── gnl/                      # ft_get_next_line
└── Makefile
```

## 📚 Useful Resources

- [Sorting Algorithm Visualizer](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html)
- [Push_swap guide (Gitbook)](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
- [Push_swap Tutorial (Medium)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

## 🤝 Contributing

This project is open for learning and exploration! If you find bugs or have optimization suggestions, fork the project
and open a Pull Request.

---

**Note:** This README was created to help future 42 students. Use it as a reference, but always implement your own solution! The real learning is in the process. 🚀