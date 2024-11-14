#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t ft_strlcat(char *dst, const char *src, unsigned int size);

void test_case(const char *initial_dst, const char *src, unsigned int size, const char *case_name) {
    char *std_dst = calloc(size + 1, sizeof(char));  // +1 for potential overflow test
    char *ft_dst = calloc(size + 1, sizeof(char));   // +1 for potential overflow test
    unsigned int std_result, ft_result;

    // Initialize dst with initial_dst
    strlcpy(std_dst, initial_dst, size);
    strlcpy(ft_dst, initial_dst, size);

    printf("=== Test Case: %s ===\n", case_name);
    printf("Initial dst: \"%s\"\n", initial_dst);
    printf("Source: \"%s\"\n", src);
    printf("Size: %u\n", size);

    std_result = strlcat(std_dst, src, size);
    ft_result = ft_strlcat(ft_dst, src, size);

    printf("Standard strlcat result:\n");
    printf("  Return value: %u\n", std_result);
    printf("  Destination: \"%s\"\n", std_dst);
    printf("ft_strlcat result:\n");
    printf("  Return value: %u\n", ft_result);
    printf("  Destination: \"%s\"\n", ft_dst);

    if (std_result == ft_result && strcmp(std_dst, ft_dst) == 0) {
        printf("Result: PASS\n");
    } else {
        printf("Result: FAIL\n");
    }

    // Check for buffer overflow
    if (ft_dst[size] != '\0') {
        printf("WARNING: Possible buffer overflow in ft_strlcat\n");
    }

    printf("\n");

    free(std_dst);
    free(ft_dst);
}

int main() {
    // Test case 1: Normal case
    test_case("Hello, ", "world!", 20, "Normal case");

    // Test case 2: Exact fit
    test_case("Hello, ", "world!", 13, "Exact fit");

    // Test case 3: Truncation
    test_case("Hello, ", "world!", 10, "Truncation");

    // Test case 4: Empty source
    test_case("Hello", "", 10, "Empty source");

    // Test case 5: Empty destination
    test_case("", "Hello", 10, "Empty destination");

    // Test case 6: Zero size
    test_case("Hello", "world", 0, "Zero size");

    // Test case 7: Size 1 (only null terminator)
    test_case("Hello", "world", 1, "Size 1");

    // Test case 8: Long string
    char long_string[1000] = "This is a very long string. ";
    for (int i = 0; i < 5; i++) {
        strcat(long_string, long_string);
    }
    test_case("Start: ", long_string, 50, "Long string");

    // Test case 9: Special characters
    test_case("Hello", "\0hidden", 20, "Special characters");

    // Test case 10: Non-printable characters
    const char src_non_printable[] = "\1\2\3World";
    test_case("Hello", src_non_printable, 15, "Non-printable characters");

    // Test case 11: Size smaller than initial dst length
    test_case("Hello", "world", 3, "Size smaller than initial dst");

    // Test case 12: Size equal to initial dst length
    test_case("Hello", "world", 6, "Size equal to initial dst");

    return 0;
}
