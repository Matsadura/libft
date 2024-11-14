#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_test_result(const char *test_name, bool passed) {
    printf("Test %-50s %s\n", test_name, passed ? "✅" : "❌");
}

void test_ft_substr(void) {
    char *result;
    bool test_passed;
    
    // Test 1: Basic substring from middle
    char *str1 = "Hello, World!";
    result = ft_substr(str1, 7, 5);  // Should get "World"
    test_passed = (result != NULL && strcmp(result, "World") == 0);
    print_test_result("Basic substring from middle", test_passed);
    free(result);

    // Test 2: Empty string input
    result = ft_substr("", 0, 5);
    test_passed = (result != NULL && strcmp(result, "") == 0);
    print_test_result("Empty string input", test_passed);
    free(result);

    // Test 3: Start index beyond string length
    result = ft_substr("Hello", 10, 5);
    test_passed = (result != NULL && strcmp(result, "") == 0);
    print_test_result("Start index beyond string length", test_passed);
    free(result);

    // Test 4: Length longer than remaining string
    result = ft_substr("Hello", 2, 10);  // Should get "llo"
    test_passed = (result != NULL && strcmp(result, "llo") == 0);
    print_test_result("Length longer than remaining string", test_passed);
    free(result);

    // Test 5: Zero length
    result = ft_substr("Hello", 1, 0);
    test_passed = (result != NULL && strcmp(result, "") == 0);
    print_test_result("Zero length", test_passed);
    free(result);

    // Test 6: Start from beginning with exact length
    result = ft_substr("Hello", 0, 5);
    test_passed = (result != NULL && strcmp(result, "Hello") == 0);
    print_test_result("Full string copy", test_passed);
    free(result);

    // Test 7: NULL input string
    result = ft_substr(NULL, 0, 5);
    test_passed = (result == NULL);
    print_test_result("NULL input string", test_passed);
    free(result);

    // Test 8: Single character substring
    result = ft_substr("Hello", 1, 1);
    test_passed = (result != NULL && strcmp(result, "e") == 0);
    print_test_result("Single character substring", test_passed);
    free(result);

    // Test 9: Start at last character
    result = ft_substr("Hello", 4, 5);
    test_passed = (result != NULL && strcmp(result, "o") == 0);
    print_test_result("Start at last character", test_passed);
    free(result);

    // Test 10: String with spaces
    result = ft_substr("Hello World", 6, 5);
    test_passed = (result != NULL && strcmp(result, "World") == 0);
    print_test_result("String with spaces", test_passed);
    free(result);

    // Test 11: Very long string
    char long_str[1000];
    memset(long_str, 'a', 998);
    long_str[998] = 'b';
    long_str[999] = '\0';
    result = ft_substr(long_str, 998, 1);
    test_passed = (result != NULL && strcmp(result, "b") == 0);
    print_test_result("Very long string", test_passed);
    free(result);

    // Test 12: Memory allocation for exact size
    result = ft_substr("Hello", 1, 2);  // Should get "el"
    test_passed = (result != NULL && 
                  strcmp(result, "el") == 0 && 
                  strlen(result) == 2);
    print_test_result("Memory allocation exact size", test_passed);
    free(result);
    
    // Test 13: Special characters
    result = ft_substr("Hello\tWorld\n", 5, 3);
    test_passed = (result != NULL && strcmp(result, "\tWo") == 0);
    print_test_result("Special characters", test_passed);
    free(result);

    // Test 14: Start and length zero
    result = ft_substr("Hello", 0, 0);
    test_passed = (result != NULL && strcmp(result, "") == 0);
    print_test_result("Start and length zero", test_passed);
    free(result);

    // Test 15: Unicode characters (if supported)
    result = ft_substr("Hello 👋 World", 6, 4);
    test_passed = (result != NULL);  // Just check if allocation succeeded
    print_test_result("Unicode characters handling", test_passed);
    free(result);
}

int main(void) {
    printf("\nRunning ft_substr tests...\n");
    printf("================================================\n");
    test_ft_substr();
    printf("================================================\n");
    return 0;
}
