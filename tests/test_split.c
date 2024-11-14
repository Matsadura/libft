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

void free_split_result(char **result) {
    if (!result)
        return;
    for (int i = 0; result[i]; i++)
        free(result[i]);
    free(result);
}

int compare_splits(char **expected, char **result) {
    if (!expected && !result)
        return 1;
    if (!expected || !result)
        return 0;
    
    int i = 0;
    while (expected[i] && result[i]) {
        if (strcmp(expected[i], result[i]) != 0)
            return 0;
        i++;
    }
    return expected[i] == NULL && result[i] == NULL;
}

void test_ft_split() {
    printf("\n=== Testing ft_split ===\n\n");

    // Test 1: Basic split with spaces
    {
        char **result = ft_split("hello world test", ' ');
        char *expected[] = {"hello", "world", "test", NULL};
        int passed = compare_splits(expected, result);
        print_result(passed);
        printf("Basic split with spaces\n");
        free_split_result(result);
    }

    // Test 2: Multiple consecutive delimiters
    {
        char **result = ft_split("hello   world", ' ');
        char *expected[] = {"hello", "world", NULL};
        int passed = compare_splits(expected, result);
        print_result(passed);
        printf("Multiple consecutive delimiters\n");
        free_split_result(result);
    }

    // Test 3: Empty string
    {
        char **result = ft_split("", ' ');
        char *expected[] = {NULL};
        int passed = compare_splits(expected, result);
        print_result(passed);
        printf("Empty string\n");
        free_split_result(result);
    }

    // Test 4: String with only delimiters
    {
        char **result = ft_split("     ", ' ');
        char *expected[] = {NULL};
        int passed = compare_splits(expected, result);
        print_result(passed);
        printf("String with only delimiters\n");
        free_split_result(result);
    }

    // Test 5: No delimiters in string
    {
        char **result = ft_split("hello", ' ');
        char *expected[] = {"hello", NULL};
        int passed = compare_splits(expected, result);
        print_result(passed);
        printf("No delimiters in string\n");
        free_split_result(result);
    }

    // Test 6: Delimiter at start and end
    {
        char **result = ft_split(" hello world ", ' ');
        char *expected[] = {"hello", "world", NULL};
        int passed = compare_splits(expected, result);
        print_result(passed);
        printf("Delimiter at start and end\n");
        free_split_result(result);
    }

    // Test 7: NULL input
    {
        char **result = ft_split(NULL, ' ');
        int passed = (result == NULL);
        print_result(passed);
        printf("NULL input\n");
        free_split_result(result);
    }

    // Test 8: Different delimiter
    {
        char **result = ft_split("one,two,three", ',');
        char *expected[] = {"one", "two", "three", NULL};
        int passed = compare_splits(expected, result);
        print_result(passed);
        printf("Different delimiter (comma)\n");
        free_split_result(result);
    }

    // Test 9: Long string with multiple splits
    {
        char **result = ft_split("this is a very long string to test splitting", ' ');
        char *expected[] = {"this", "is", "a", "very", "long", "string", "to", "test", "splitting", NULL};
        int passed = compare_splits(expected, result);
        print_result(passed);
        printf("Long string with multiple splits\n");
        free_split_result(result);
    }

    // Test 10: Special characters
    {
        char **result = ft_split("test@email@domain", '@');
        char *expected[] = {"test", "email", "domain", NULL};
        int passed = compare_splits(expected, result);
        print_result(passed);
        printf("Special characters as delimiter\n");
        free_split_result(result);
    }
}

int main(void) {
    test_ft_split();
    return 0;
}
