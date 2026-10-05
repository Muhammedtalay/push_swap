*This project has been created as part of the 42 curriculum by mutalay.*

# Libft

## Description

Libft is my own C library. It re-implements a set of standard C functions and adds some
extra ones that do not exist in libc.

The purpose is to understand how the standard functions work by writing them from
scratch, and to build a static library (`libft.a`) that I will reuse in the next
projects of the curriculum.

The library has three parts:

- **Part 1 — Libc functions:** `ft_strlen`, `ft_memset`, `ft_memcpy`, `ft_memmove`,
  `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`,
  `ft_memcmp`, `ft_strnstr`, `ft_atoi`, `ft_calloc`, `ft_strdup`, `ft_bzero`, and the
  character classification functions.
- **Part 2 — Additional functions:** `ft_substr`, `ft_strjoin`, `ft_strtrim`,
  `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri` and the `ft_put*_fd` family.
- **Part 3 — Linked list:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`,
  `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`, built on
  the `t_list` structure.

## Instructions

```bash
make        # builds libft.a
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # fclean + all
```

To use the library:

```c
#include "libft.h"
```

```bash
cc -Wall -Wextra -Werror main.c libft.a -o my_program
```

All files are compiled with `-Wall -Wextra -Werror` and the archive is created with
`ar`.

## Algorithm and technical choices

**Memory functions.** The `mem*` functions cast their `void *` parameters to
`unsigned char *` before working on them, because `char` signedness is
implementation-defined and byte comparisons must be unsigned. `ft_memmove` compares the
source and destination addresses first: when they overlap and the destination comes
after the source, it copies backwards, otherwise forwards. This is the only difference
from `ft_memcpy`.

**Allocating functions.** Every function that calls `malloc` computes the exact size it
needs and checks the returned pointer before writing to it. `ft_substr` takes the
smaller of the requested length and the number of characters actually remaining, which
avoids over-allocating and avoids a `size_t` underflow when `start` is close to the end
of the string.

**ft_split.** It works in two passes. The first pass counts the words using a flag that
tracks whether the parser is currently inside a word, so the number of pointers to
allocate is known before allocating. The second pass extracts each word with
`ft_substr`. If any allocation fails, every string already allocated is freed before
returning NULL, so a partial failure never leaks.

**Linked list.** The functions that can change the first node of the list
(`ft_lstadd_front`, `ft_lstadd_back`, `ft_lstclear`) take a `t_list **` parameter,
because C passes arguments by value: modifying the head requires the address of the
pointer itself, not a copy of it. `ft_lstclear` saves the address of the next node
before freeing the current one, otherwise it would read memory that has already been
released. `ft_lstmap` builds a completely new list and never modifies the original one;
if an allocation fails halfway through, it deletes the content it has just produced and
clears the partial new list before returning NULL.

**Helper functions** are declared `static` so their scope stays inside their own file
and they do not pollute the library.

## Resources

- `man` pages of every re-implemented function (`man strlen`, `man memmove`, ...)
- Kaan Aslan — *C ve Sistem Programcıları Derneği, C Ders Notları*
- Rifat Çölkesen — *Her Yönüyle C*
- mycodeschool — YouTube playlist on pointers and linked lists
- `valgrind` documentation, used to check for memory leaks

### Use of AI

I used an AI assistant as a learning tool during this project, mainly to understand
concepts and to debug my own code. The main topics were pointer semantics (the
difference between t_list * and t_list **, and why the address of a pointer is
needed to modify the head of a list), reading valgrind output, and reviewing edge
cases such as empty lists, NULL arguments and size_t underflow.

I also used it while working on Part 3 to ask questions when I was stuck and to
check whether my reasoning was correct. All of the code in this repository was
written by me, and I can explain every line of it.
