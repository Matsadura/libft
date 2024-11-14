#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

void print_result(int passed) {
    if (passed)
        printf("✅ ");
    else
        printf("❌ ");
}

// Test functions to pass to ft_strmapi
char to_upper(unsigned int i, char c) {
    (void)i;  // Unused parameter
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

char to_index_char(unsigned int i, char c) {
    (void)c;  // Unused parameter
    return '0' + (i % 10);
}

char alternate_case(unsigned int i, char c) {
    if (i % 2 == 0) {
        if (c >= 'a' && c <= 'z')
            return c - 32;
    } else {
        if (c >= 'A' && c <= 'Z')
            return c + 32;
    }
    return c;
}

char add_index(unsigned int i, char c) {
    if (c >= 'a' && c <= 'z') {
        char new_char = ((c - 'a' + i) % 26) + 'a';
        return new_char;
    }
    return c;
}

void test_ft_strmapi() {
    printf("\n=== Testing ft_strmapi ===\n\n");

    // Test 1: Basic uppercase conversion
    {
        char const *input = "hello";
        char *result = ft_strmapi(input, &to_upper);
        int passed = (result != NULL && strcmp(result, "HELLO") == 0);
        print_result(passed);
        printf("Basic uppercase conversion\n");
        free(result);
    }

    // Test 2: Replace with indices
    {
        char const *input = "test";
        char *result = ft_strmapi(input, &to_index_char);
        int passed = (result != NULL && strcmp(result, "0123") == 0);
        print_result(passed);
        printf("Replace with indices\n");
        free(result);
    }

    // Test 3: Alternate case
    {
        char const *input = "hello world";
        char *result = ft_strmapi(input, &alternate_case);
        int passed = (result != NULL && strcmp(result, "HeLlO wOrLd") == 0);
		printf("%s\n\n", result);
        print_result(passed);
        printf("Alternate case\n");
        free(result);
    }

    // Test 4: Empty string
    {
        char const *input = "";
        char *result = ft_strmapi(input, &to_upper);
        int passed = (result != NULL && strcmp(result, "") == 0);
        print_result(passed);
        printf("Empty string\n");
        free(result);
    }

    // Test 5: NULL string
    {
        char *result = ft_strmapi(NULL, &to_upper);
        int passed = (result == NULL);
        print_result(passed);
        printf("NULL string\n");
        free(result);
    }

    // Test 6: NULL function
    {
        char const *input = "test";
        char *result = ft_strmapi(input, NULL);
        int passed = (result == NULL);
        print_result(passed);
        printf("NULL function\n");
        free(result);
    }

    // Test 7: Long string
    {
        char const *input = "abcdefghijklmnopqrstuvwxyz";
        char *result = ft_strmapi(input, &add_index);
        // Expected: each character is shifted by its index
        char expected[] = "acegikmoqsuwyacegikmoqsuw";
        int passed = (result != NULL && strcmp(result, expected) == 0);
		printf("%s\n", expected);
		printf("%s\n\n", result);
        print_result(passed);
        printf("Long string with index-based transformation\n");
        free(result);
    }

    // Test 8: String with special characters
    {
        char const *input = "Hello! @World#";
        char *result = ft_strmapi(input, &to_upper);
        int passed = (result != NULL && strcmp(result, "HELLO! @WORLD#") == 0);
        print_result(passed);
        printf("String with special characters\n");
        free(result);
    }

    // Test 9: Single character
    {
        char const *input = "x";
        char *result = ft_strmapi(input, &to_upper);
        int passed = (result != NULL && strcmp(result, "X") == 0);
        print_result(passed);
        printf("Single character\n");
        free(result);
    }

    // Test 10: Memory allocation for long string
    {
        char input[1000];
        memset(input, 'a', 999);
        input[999] = '\0';
        char *result = ft_strmapi(input, &to_upper);
        int passed = 0;
        if (result) {
            passed = 1;
            for (int i = 0; i < 999; i++) {
                if (result[i] != 'A') {
                    passed = 0;
                    break;
                }
            }
        }
        print_result(passed);
        printf("Long string memory allocation (1000 chars)\n");
        free(result);
    }
}

int main(void) {
    test_ft_strmapi();
    return 0;
}
