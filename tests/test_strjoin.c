#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_test_result(const char *test_name, bool passed) {
    printf("Test %-50s %s\n", test_name, passed ? "✅" : "❌");
}

void test_ft_strjoin(void) {
    char *result;
    bool test_passed;
    
    // Test 1: Basic string joining
    result = ft_strjoin("Hello ", "World");
    test_passed = (result != NULL && strcmp(result, "Hello World") == 0);
    print_test_result("Basic string joining", test_passed);
    free(result);

    // Test 2: Empty first string
    result = ft_strjoin("", "Hello");
    test_passed = (result != NULL && strcmp(result, "Hello") == 0);
    print_test_result("Empty first string", test_passed);
    free(result);

    // Test 3: Empty second string
    result = ft_strjoin("Hello", "");
    test_passed = (result != NULL && strcmp(result, "Hello") == 0);
    print_test_result("Empty second string", test_passed);
    free(result);

    // Test 4: Both empty strings
    result = ft_strjoin("", "");
    test_passed = (result != NULL && strcmp(result, "") == 0);
    print_test_result("Both empty strings", test_passed);
    free(result);

    // Test 5: NULL first string
    result = ft_strjoin(NULL, "Hello");
    test_passed = (result == NULL);
    print_test_result("NULL first string", test_passed);
    free(result);

    // Test 6: NULL second string
    result = ft_strjoin("Hello", NULL);
    test_passed = (result == NULL);
    print_test_result("NULL second string", test_passed);
    free(result);

    // Test 7: Both NULL strings
    result = ft_strjoin(NULL, NULL);
    test_passed = (result == NULL);
    print_test_result("Both NULL strings", test_passed);
    free(result);

    // Test 8: Special characters
    result = ft_strjoin("Hello\n", "\tWorld");
    test_passed = (result != NULL && strcmp(result, "Hello\n\tWorld") == 0);
    print_test_result("Special characters", test_passed);
    free(result);

    // Test 9: Very long strings
    char long_str1[1000];
    char long_str2[1000];
    memset(long_str1, 'a', 998);
    memset(long_str2, 'b', 998);
    long_str1[998] = '\0';
    long_str2[998] = '\0';
    result = ft_strjoin(long_str1, long_str2);
    test_passed = (result != NULL && 
                  strlen(result) == 1996 &&
                  result[0] == 'a' &&
                  result[998] == 'b' &&
                  result[1995] == 'b');
    print_test_result("Very long strings", test_passed);
    free(result);

    // Test 10: Single character strings
    result = ft_strjoin("a", "b");
    test_passed = (result != NULL && strcmp(result, "ab") == 0);
    print_test_result("Single character strings", test_passed);
    free(result);

    // Test 11: String with null characters in middle
    char str_with_null1[] = "Hello\0World";
    char str_with_null2[] = "Test\0Case";
    result = ft_strjoin(str_with_null1, str_with_null2);
    test_passed = (result != NULL && strcmp(result, "HelloTest") == 0);
    print_test_result("Strings with null characters", test_passed);
    free(result);

    // Test 12: Unicode characters (if supported)
    result = ft_strjoin("Hello 👋", " World 🌍");
    test_passed = (result != NULL); // Just check if allocation succeeded
    print_test_result("Unicode characters", test_passed);
    free(result);

    // Test 13: Multiple spaces
    result = ft_strjoin("   Hello   ", "   World   ");
    test_passed = (result != NULL && strcmp(result, "   Hello      World   ") == 0);
    print_test_result("Multiple spaces", test_passed);
    free(result);

    // Test 14: Numbers and special characters
    result = ft_strjoin("123!@#", "$%^456");
    test_passed = (result != NULL && strcmp(result, "123!@#$%^456") == 0);
    print_test_result("Numbers and special characters", test_passed);
    free(result);

    // Test 15: Memory leak check with repeated joins
    char *temp1 = ft_strjoin("Hello", " ");
    char *temp2 = ft_strjoin(temp1, "World");
    test_passed = (temp2 != NULL && strcmp(temp2, "Hello World") == 0);
    print_test_result("Chained joins", test_passed);
    free(temp1);
    free(temp2);
}

int main(void) {
    printf("\nRunning ft_strjoin tests...\n");
    printf("================================================\n");
    test_ft_strjoin();
    printf("================================================\n");
    return 0;
}
