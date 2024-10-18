#include "../libft.h"
#include <stdio.h>
#include <string.h>

void run_test(const char *s, int c) {
    char *expected = strrchr(s, c);
    char *actual = ft_strrchr(s, c);

    printf("strrchr(\"%s\", '%c')\n", s, c);
    printf("Expected: %p (\"%s\"), Actual: %p (\"%s\")\n",
           (void*)expected, expected ? expected : "NULL",
           (void*)actual, actual ? actual : "NULL");

    if ((expected == NULL && actual == NULL) ||
        (expected != NULL && actual != NULL && strcmp(expected, actual) == 0)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
    printf("\n");
}

int main() {
    // Test cases
    run_test("hello", 'h');        // Character at the beginning
    run_test("hello", 'o');        // Character at the end
    run_test("hello", 'l');        // Character in the middle
    run_test("hello", 'x');        // Character not in the string
    run_test("hello", '\0');       // Null terminator
    run_test("", 'a');             // Empty string
    run_test("hello world", ' ');  // Space character
    run_test("hello\nworld", '\n'); // Newline character
    run_test("12345", '3');        // Digit in the string
    run_test("!@#$%", '%');        // Special character
    run_test("aaaaaa", 'a');       // Multiple occurrences (should return first)
    run_test("hello", 0);          // ASCII NUL character (should find string terminator)
    run_test("hello", 'H');        // Case sensitivity check

    return 0;
}
