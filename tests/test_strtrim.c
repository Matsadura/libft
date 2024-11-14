#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_test_result(const char *test_name, bool passed) {
    printf("Test %-50s %s\n", test_name, passed ? "✅" : "❌");
}

void test_ft_strtrim(void) {
    char *result;
    bool test_passed;
    
    // Test 1: Basic trimming from both ends
    result = ft_strtrim("   Hello World   ", " ");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Basic trim spaces from both ends", test_passed);
    free(result);

    // Test 2: Multiple character set
    result = ft_strtrim("...Hello World...", ".");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Multiple same characters trim", test_passed);
    free(result);

    // Test 3: Mixed character set
    result = ft_strtrim("...###Hello World...###", ".#");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Mixed character set trim", test_passed);
    free(result);

    // Test 4: Empty string input
    result = ft_strtrim("", " ");
    test_passed = (result != NULL && strcmp(result, "") == 0);
    print_test_result("Empty string input", test_passed);
    free(result);

    // Test 5: Empty set
    result = ft_strtrim("Hello World", "");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Empty set", test_passed);
    free(result);

    // Test 6: NULL string
    result = ft_strtrim(NULL, " ");
    test_passed = (result == NULL);
    print_test_result("NULL string", test_passed);
    free(result);

    // Test 7: NULL set
    result = ft_strtrim("Hello World", NULL);
    test_passed = (result == NULL);
    print_test_result("NULL set", test_passed);
    free(result);

    // Test 8: String consisting only of trim characters
    result = ft_strtrim("   ", " ");
    test_passed = (result != NULL && strcmp(result, "") == 0);
    print_test_result("String of only trim characters", test_passed);
    free(result);

    // Test 9: No trim needed
    result = ft_strtrim("Hello World", "xyz");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("No trim needed", test_passed);
    free(result);

    // Test 10: Trim only from start
    result = ft_strtrim("...Hello World", ".");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Trim only from start", test_passed);
    free(result);

    // Test 11: Trim only from end
    result = ft_strtrim("Hello World...", ".");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Trim only from end", test_passed);
    free(result);

    // Test 12: Complex character set
    result = ft_strtrim("!@#$%Hello World!@#$%", "!@#$%");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Complex character set", test_passed);
    free(result);

    // Test 13: Very long string
    char *long_str = (char *)malloc(1000);
    memset(long_str, '.', 998);
    strcpy(long_str + 499, "Hello World");
    strcat(long_str + 499 + 11, "...");
    result = ft_strtrim(long_str, ".");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Very long string", test_passed);
    free(result);
    free(long_str);

    // Test 14: Single character string and set
    result = ft_strtrim("a", "a");
    test_passed = (result != NULL && strcmp(result, "") == 0);
    print_test_result("Single character string and set", test_passed);
    free(result);

    // Test 15: Alternating characters
    result = ft_strtrim("ababHello Worldabab", "ab");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Alternating characters", test_passed);
    free(result);

    // Test 16: Special characters in string
    result = ft_strtrim("   Hello\tWorld\n   ", " \t\n");
    test_passed = (result != NULL && strcmp(result, "Hello\tWorld") == 0);
    print_test_result("Special characters in string", test_passed);
    free(result);

    // Test 17: Unicode characters (if supported)
    result = ft_strtrim("👋Hello World🌍", "👋🌍");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Unicode characters", test_passed);
    free(result);

    // Test 18: Set includes string characters
    result = ft_strtrim("Hello World", "Hld");
    test_passed = (result != NULL && strcmp(result, "ello Wor") == 0);
    print_test_result("Set includes string characters", test_passed);
    free(result);
}

int main(void) {
    printf("\nRunning ft_strtrim tests...\n");
    printf("================================================\n");
    test_ft_strtrim();
    printf("================================================\n");
    return 0;
}
