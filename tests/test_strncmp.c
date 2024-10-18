#include "../libft.h"
#include <stdio.h>
#include <string.h>


void run_test(char *s1, char *s2, unsigned int n) {
    int expected = strncmp(s1, s2, n);
    int actual = ft_strncmp(s1, s2, n);

    printf("strncmp(\"%s\", \"%s\", %u)\n", s1, s2, n);
    printf("Expected: %d, Actual: %d\n", expected, actual);

    if (expected == actual) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
    printf("\n");
}

int main() {
    // Test cases
    run_test("hello", "hello", 5);         // Identical strings, full length
    run_test("hello", "hello", 3);         // Identical strings, partial length
    run_test("hello", "world", 5);         // Completely different strings
    run_test("hello", "hell", 5);          // Different lengths
    run_test("hello", "hell", 4);          // Different lengths, up to common part
    run_test("hello", "hello world", 5);   // One string is a prefix of the other
    run_test("", "", 1);                   // Both strings empty
    run_test("hello", "", 5);              // One string empty
    run_test("hello!", "hello", 6);        // Special characters
    run_test("hello123", "hello124", 8);   // Numbers in strings
    run_test("hello3", "hello124", 8);   // Numbers in strings
    run_test("hello", "hello124", 8);   // Numbers in strings

    return 0;
}
