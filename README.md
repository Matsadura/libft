# Libft

The aim of this project is to code a C library regrouping usual functions.

## Progress Checklist

### Part 1 - Libc functions

#### Memory functions
- [ ] ft_memset: Fill memory with a constant byte
- [ ] ft_bzero: Zero a byte string
- [ ] ft_memcpy: Copy memory area
- [ ] ft_memccpy: Copy memory area until a specific char is found
- [ ] ft_memmove: Copy memory area (overlap-safe)
- [ ] ft_memchr: Locate byte in byte string
- [ ] ft_memcmp: Compare memory areas

#### String functions
- [ ] ft_strlen: Calculate the length of a string
- [ ] ft_strlcpy: Size-bounded string copying
- [ ] ft_strlcat: Size-bounded string concatenation
- [ ] ft_strchr: Locate character in string (first occurrence)
- [ ] ft_strrchr: Locate character in string (last occurrence)
- [ ] ft_strnstr: Locate a substring in a string (size-bounded)
- [ ] ft_strncmp: Compare two strings (size-bounded)

#### Type functions
- [ ] ft_atoi: Convert a string to an integer
- [x] ft_isalpha: Check for alphabetic character
- [x] ft_isdigit: Check for digit (0 through 9)
- [x] ft_isalnum: Check for alphanumeric character
- [x] ft_isascii: Check for ASCII character
- [x] ft_isprint: Check for printable character
- [x] ft_toupper: Convert lowercase letter to uppercase
- [x] ft_tolower: Convert uppercase letter to lowercase

#### Functions using malloc:
- [ ] ft_calloc: Allocate and zero-initialize array
- [ ] ft_strdup: Create a duplicate of the string

### Part 2 - Additional functions

- [ ] ft_substr: Extract substring from string
- [ ] ft_strjoin: Concatenate two strings
- [ ] ft_strtrim: Trim beginning and end of string with specified characters
- [ ] ft_split: Split string into array of substrings
- [ ] ft_itoa: Convert integer to ASCII string
- [ ] ft_strmapi: Create new string from modifying string with specified function
- [ ] ft_putchar_fd: Output a character to given file descriptor
- [ ] ft_putstr_fd: Output string to given file descriptor
- [ ] ft_putendl_fd: Output string to given file descriptor with newline
- [ ] ft_putnbr_fd: Output integer to given file descriptor

### Bonus Part

- [ ] ft_lstnew: Create new list element
- [ ] ft_lstadd_front: Add new element at beginning of list
- [ ] ft_lstsize: Count elements in a list
- [ ] ft_lstlast: Find last element of list
- [ ] ft_lstadd_back: Add new element at end of list
- [ ] ft_lstdelone: Delete element from list
- [ ] ft_lstclear: Delete sequence of elements of list from a starting point
- [ ] ft_lstiter: Apply function to content of all list's elements
- [ ] ft_lstmap: Apply function to content of all list's elements into new list
