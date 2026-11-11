*This project has been created as part of the 42 curriculum by mutalay, edogruer.*

# push_swap

## Description

push_swap is a sorting project from the 42 curriculum. The program receives a list of integers as arguments (stack **a**) and prints the shortest sequence of instructions it can find to sort them in ascending order, using a second, initially empty stack (**b**) and a limited set of operations:

| Operation | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the first two elements of a / b / both |
| `pa` / `pb` | take the top element of b / a and put it on top of a / b |
| `ra` / `rb` / `rr` | rotate a / b / both upwards (the first element becomes the last) |
| `rra` / `rrb` / `rrr` | rotate a / b / both downwards (the last element becomes the first) |

The goal is not only to sort, but to sort with as few operations as possible. This version of the project also requires four distinct strategies with different complexity classes (measured in number of push_swap operations), a disorder metric, and an adaptive strategy that chooses between them.

**Main features**

- Four strategies built into one binary: Simple O(n²), Medium O(n√n), Complex O(n log n) and Adaptive.
- Disorder metric computed before any move is made.
- `--bench` mode that prints the disorder, the selected strategy and the count of every operation type to stderr.
- Full input validation: non-integers, values outside the `int` range and duplicates print `Error` on stderr.

## Instructions

### Compilation

```bash
make        # builds libft and the push_swap binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # fclean + all
```

Compiled with `cc -Wall -Wextra -Werror`.

### Usage

```bash
./push_swap [strategy] [--bench] <numbers...>
```

| Flag | Meaning |
|---|---|
| `--simple` | force the O(n²) algorithm |
| `--medium` | force the O(n√n) algorithm |
| `--complex` | force the O(n log n) algorithm |
| `--adaptive` | choose the algorithm from the measured disorder (default) |
| `--bench` | print metrics to stderr after sorting |

The first number is the top of stack a. Without any number, the program prints nothing.

### Examples

```bash
./push_swap 3 2 1
./push_swap --complex 4 67 3 87 23
./push_swap --bench 4 67 3 87 23 2> bench.txt

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG     # OK

ARG=$(shuf -i 0-10000 -n 100 | awk '{printf "%d ", $1-5000}')
./push_swap $ARG | wc -l                                       # number of operations
./push_swap $ARG | ./checker_linux $ARG                        # OK / KO

./push_swap 1 2 two        # Error
./push_swap 3 2 3          # Error
```

Example `--bench` output (stderr):

```
[bench] disorder:  40.00%
[bench] strategy:  Adaptive / (n√n)
[bench] total_ops:  13
[bench] sa  0  sb  0  ss  0  pa  5  pb  5
[bench] ra  0  rb  2  rr  0  rra  0  rrb  1  rrr  0
```

## Algorithms

### Preprocessing: indexing

Before sorting, every value is replaced (in the `index` field of each node) by its rank: the smallest number gets 0, the largest gets n − 1 (`put_index`). All algorithms that need comparisons by position work on these ranks, so negative numbers and large values need no special handling.

### Disorder metric

`compute_disorder` counts, over all pairs (i, j) with i before j, how many pairs are in the wrong order (`a[i] > a[j]`), and divides by the total number of pairs. The result is 0 for a sorted stack and 1 for a reversed one. It is computed once, before any operation. If the input is already sorted, no strategy is called and nothing is printed.

### Simple — selection by minimum extraction, O(n²)

1. Find the position of the smallest element in a.
2. Bring it to the top with `ra` or `rra`, whichever direction is shorter.
3. `pb` it.
4. Repeat until a is empty, then `pa` everything back.

**Complexity:** each of the n extractions needs at most n/2 rotations plus one push, and the final phase needs n `pa` → O(n²) operations. Extra space: O(1) besides the two stacks.

### Medium — chunk sort, O(n√n)

1. The ranks are split into chunks of size ≈ 1.5·√n (`get_chunk_size`).
2. Elements of a are pushed to b chunk by chunk. An element whose rank is already below the current counter is pushed and sent to the bottom of b with `rb`, the others in the current window are pushed on top, the rest are rotated with `ra`. This keeps b roughly ordered by chunk.
3. The elements are pushed back to a from the largest rank to the smallest: each time the maximum of b is brought to the top with `rb`/`rrb` (shortest direction) and pushed with `pa`.

**Complexity:** there are O(√n) chunks and each chunk needs at most one pass over a (O(n) rotations) → O(n√n) for phase 2. Because b is ordered by chunk, the maximum is always within about one chunk of the top or bottom, so each `pa` needs O(√n) rotations → O(n√n) for phase 3. Extra space: O(1) besides the two stacks.

### Complex — binary LSD radix sort, O(n log n)

1. Compute the number of bits of the largest rank: `max_bits = bits(n − 1)` (`get_max_bits`).
2. For each bit, from the least significant (bit 0) to bit `max_bits − 1`:
   - look at every element of a exactly once: if `(index >> bit) & 1` is 1, `ra` (keep it in a); if it is 0, `pb`;
   - then `pa` everything back from b.
3. After the last bit, a is sorted.

Each pass is a stable split by one bit, so after the pass on bit k the stack is sorted by the lowest k + 1 bits. After all bits it is fully sorted.

**Complexity:** ⌈log₂ n⌉ passes, each with n decisions (`ra`/`pb`) and at most n `pa` → at most 2·n·⌈log₂ n⌉ operations, O(n log n). Extra space: O(1) besides the two stacks. The number of operations depends only on n, not on the input order (1084 for 100 numbers, 6784 for 500).

### Adaptive — selection by disorder

| Disorder | Strategy | Class |
|---|---|---|
| d < 0.2 | Simple | O(n²) |
| 0.2 ≤ d < 0.5 | Medium | O(n√n) |
| d ≥ 0.5 | Complex | O(n log n) |

**Rationale for the thresholds:**

- The three regimes and their complexity targets come directly from the subject, so each regime uses the algorithm whose upper bound matches its target class.
- For low disorder the input is close to sorted. The minimum is usually near the top, so the extraction approach rarely needs long rotations and stays cheap in practice.
- For medium disorder the chunk method gives the best counts in our measurements.
- For high disorder (random-like input) the subject requires an O(n log n) bound in the worst case, which radix guarantees regardless of the order.

**Space:** every strategy works only with the two stacks and a constant number of local variables. The disorder computation and indexing are done before any move and produce no operations.

### Measured results

Average number of operations on 5 random inputs (values between −5000 and 5000):

| Strategy | 100 numbers | 500 numbers |
|---|---|---|
| Simple | ~1420 | ~31600 |
| Medium | ~560 | ~5100 |
| Complex | 1084 | 6784 |
| Adaptive | ~680 | ~5700 |

Subject targets: 100 numbers < 2000 to pass (< 700 excellent), 500 numbers < 12000 to pass (< 5500 excellent).

## Project structure

```
push_swap/
├── main.c
├── push_swap.h
├── Makefile
├── libft/                 libft library
├── parsing/               argument parsing, validation, cleanup
├── operations/            sa sb ss pa pb ra rb rr rra rrb rrr (each updates the operation counter)
├── sorting/               simple, medium, complex (radix) and adaptive strategies
└── utils/                 node and stack helpers, indexing, disorder, bench output
```

## Contributions

| Area | mutalay | edogruer |
|---|---|---|
| `main.c`, program flow | ✔ | |
| Parsing and error handling (`parsing/`) | ✔ | |
| Stack helpers and indexing (`utils/stack_utils.c`) | ✔ | |
| Operation counter and `--bench` output (`utils/bench.c`) | ✔ | |
| Node helpers (`utils/node_utils.c`) | | ✔ |
| Disorder metric (`utils/disorder.c`) | | ✔ |
| Operations (`operations/`) | | ✔ |
| Header (`push_swap.h`) | | ✔ |
| Simple strategy (`sort_simple.c`) | | ✔ |
| Medium strategy (`sort_medium.c`, `medium_utils.c`) | | ✔ |
| Complex strategy, radix sort (`sort_complex.c`, `complex_utils.c`) | ✔ | |
| Adaptive strategy and dispatcher (`sort_adaptive.c`) | | ✔ |
| Testing, norminette, code review, Git workflow | ✔ | ✔ |

Both of us reviewed each other's pull requests and can explain every algorithm in the project.

## Resources

- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
- [Inversion (discrete mathematics) — Wikipedia](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)) — the disorder metric is the normalised number of inversions
- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [C Bitwise Operators — W3Schools](https://www.w3schools.com/c/c_bitwise_operators.php)
- [maiadegraaf/push_swap — README](https://github.com/maiadegraaf/push_swap) — explanation of binary radix applied to two stacks
- The push_swap subject (42) and the provided `checker_linux`

### Use of AI

AI (Claude) was used as a learning and support tool, not to produce code we could not explain:

- **Concepts:** explanations of binary numbers and bitwise operators (`>>`, `&`), and of how binary radix sort works, using step-by-step paper traces on small stacks.
- **Complex strategy:** guidance on splitting radix into functions and code skeletons with blanks. The functions were written, debugged and tested by us.
- **Git workflow:** branches, merges, pull requests, upstream, resolving the shared-branch setup.
- **Norminette:** explanations of error messages (tabs vs spaces, pointer spacing, empty lines).
- **Testing:** command lines for random inputs, operation counting and the checker.
- **Documentation:** drafting this README, which we then reviewed and corrected.

Every piece of AI output was checked by running the code, norminette and the checker, and reviewed between the two of us.