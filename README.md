# Libft

The aim of this project is to code a C library regrouping usual functions.

## Progress Checklist

### Part 1 - Libc functions

#### Memory functions
- [x] ft_memset: Fill memory with a constant byte
- [x] ft_bzero: Zero a byte string
- [x] ft_memcpy: Copy memory area
- [x] ft_memccpy: Copy memory area until a specific char is found
- [x] ft_memmove: Copy memory area (overlap-safe)
- [x] ft_memchr: Locate byte in byte string
- [x] ft_memcmp: Compare memory areas

#### String functions
- [x] ft_strlen: Calculate the length of a string
- [x] ft_strlcpy: Size-bounded string copying
- [x] ft_strlcat: Size-bounded string concatenation
- [x] ft_strchr: Locate character in string (first occurrence)
- [x] ft_strrchr: Locate character in string (last occurrence)
- [x] ft_strnstr: Locate a substring in a string (size-bounded)
- [x] ft_strncmp: Compare two strings (size-bounded)

#### Type functions
- [x] ft_atoi: Convert a string to an integer
- [x] ft_isalpha: Check for alphabetic character
- [x] ft_isdigit: Check for digit (0 through 9)
- [x] ft_isalnum: Check for alphanumeric character
- [x] ft_isascii: Check for ASCII character
- [x] ft_isprint: Check for printable character
- [x] ft_toupper: Convert lowercase letter to uppercase
- [x] ft_tolower: Convert uppercase letter to lowercase

#### Functions using malloc:
- [x] ft_calloc: Allocate and zero-initialize array
- [x] ft_strdup: Create a duplicate of the string

### Part 2 - Additional functions

- [x] ft_substr: Extract substring from string
- [x] ft_strjoin: Concatenate two strings
- [x] ft_strtrim: Trim beginning and end of string with specified characters
- [x] ft_split: Split string into array of substrings
- [x] ft_itoa: Convert integer to ASCII string
- [x] ft_strmapi: Create new string from modifying string with specified function
- [x] ft_putchar_fd: Output a character to given file descriptor
- [x] ft_putstr_fd: Output string to given file descriptor
- [x] ft_putendl_fd: Output string to given file descriptor with newline
- [x] ft_putnbr_fd: Output integer to given file descriptor

### Bonus Part

- [x] ft_lstnew: Create new list element
- [x] ft_lstadd_front: Add new element at beginning of list
- [x] ft_lstsize: Count elements in a list
- [x] ft_lstlast: Find last element of list
- [x] ft_lstadd_back: Add new element at end of list
- [x] ft_lstdelone: Delete element from list
- [x] ft_lstclear: Delete sequence of elements of list from a starting point
- [x] ft_lstiter: Apply function to content of all list's elements
- [x] ft_lstmap: Apply function to content of all list's elements into new list
