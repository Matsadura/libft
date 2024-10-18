#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void run_test(const char *s) {
    char *expected = strdup(s);
    char *actual = ft_strdup(s);

    printf("strdup(\"%s\")\n", s);
    printf("Expected: \"%s\", Actual: \"%s\"\n", expected, actual);

    if (expected == NULL && actual == NULL) {
        printf("PASS (Both NULL)\n");
    } else if (expected != NULL && actual != NULL && strcmp(expected, actual) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }

    // Check if the returned strings are distinct copies
    if (expected != NULL && actual != NULL && s != actual) {
        printf("Memory: PASS (Distinct copy)\n");
    } else if (expected == NULL && actual == NULL) {
        printf("Memory: PASS (Both NULL)\n");
    } else {
        printf("Memory: FAIL (Not a distinct copy)\n");
    }

    printf("\n");

    // Free the allocated memory
    free(expected);
    free(actual);
}

int main() {
    // Test cases
    run_test("hello");             // Basic string
    run_test("");                  // Empty string
    run_test("hello world");       // String with space
    run_test("Hello\nWorld");      // String with newline
    run_test("12345");             // String with numbers
    run_test("!@#$%^&*()");        // String with special characters
    run_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit."); // Long string
    run_test("A");                 // Single character string
    run_test("\0hidden");          // String with null character (should only copy up to null)
    run_test("   ");               // String with only spaces

    return 0;
}
