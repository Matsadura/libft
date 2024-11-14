#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void print_test_result(const char *test_name, bool passed) {
    printf("Test %-50s %s\n", test_name, passed ? "✅" : "❌");
}

// Helper function to create expected string for verification
char *int_to_str(int n) {
    char buffer[33];
    sprintf(buffer, "%d", n);
    return strdup(buffer);
}

void test_ft_itoa(void) {
    char *result;
    char *expected;
    bool test_passed;
    
    // Test 1: Zero
    result = ft_itoa(0);
    test_passed = (result != NULL && strcmp(result, "0") == 0);
    print_test_result("Zero", test_passed);
    free(result);

    // Test 2: Positive single digit
    result = ft_itoa(5);
    test_passed = (result != NULL && strcmp(result, "5") == 0);
    print_test_result("Positive single digit", test_passed);
    free(result);

    // Test 3: Negative single digit
    result = ft_itoa(-5);
    test_passed = (result != NULL && strcmp(result, "-5") == 0);
    print_test_result("Negative single digit", test_passed);
    free(result);

    // Test 4: Positive multiple digits
    result = ft_itoa(123);
    test_passed = (result != NULL && strcmp(result, "123") == 0);
    print_test_result("Positive multiple digits", test_passed);
    free(result);

    // Test 5: Negative multiple digits
    result = ft_itoa(-123);
    test_passed = (result != NULL && strcmp(result, "-123") == 0);
    print_test_result("Negative multiple digits", test_passed);
    free(result);

    // Test 6: INT_MAX
    result = ft_itoa(INT_MAX);
    expected = int_to_str(INT_MAX);
    test_passed = (result != NULL && strcmp(result, expected) == 0);
    print_test_result("INT_MAX", test_passed);
    free(result);
    free(expected);

    // Test 7: INT_MIN
    result = ft_itoa(INT_MIN);
    expected = int_to_str(INT_MIN);
    test_passed = (result != NULL && strcmp(result, expected) == 0);
    print_test_result("INT_MIN", test_passed);
    free(result);
    free(expected);

    // Test 8: Power of 10
    result = ft_itoa(1000);
    test_passed = (result != NULL && strcmp(result, "1000") == 0);
    print_test_result("Power of 10", test_passed);
    free(result);

    // Test 9: Negative power of 10
    result = ft_itoa(-1000);
    test_passed = (result != NULL && strcmp(result, "-1000") == 0);
    print_test_result("Negative power of 10", test_passed);
    free(result);

    // Test 10: Number with trailing zeros
    result = ft_itoa(100001);
    test_passed = (result != NULL && strcmp(result, "100001") == 0);
    print_test_result("Number with trailing zeros", test_passed);
    free(result);

    // Test 11: Alternating digits
    result = ft_itoa(12345);
    test_passed = (result != NULL && strcmp(result, "12345") == 0);
    print_test_result("Alternating digits", test_passed);
    free(result);

    // Test 12: Small negative number
    result = ft_itoa(-1);
    test_passed = (result != NULL && strcmp(result, "-1") == 0);
    print_test_result("Small negative number", test_passed);
    free(result);

    // Test 13: Boundary near INT_MAX
    result = ft_itoa(INT_MAX - 1);
    expected = int_to_str(INT_MAX - 1);
    test_passed = (result != NULL && strcmp(result, expected) == 0);
    print_test_result("Boundary near INT_MAX", test_passed);
    free(result);
    free(expected);

    // Test 14: Boundary near INT_MIN
    result = ft_itoa(INT_MIN + 1);
    expected = int_to_str(INT_MIN + 1);
    test_passed = (result != NULL && strcmp(result, expected) == 0);
    print_test_result("Boundary near INT_MIN", test_passed);
    free(result);
    free(expected);

    // Test 15: Memory allocation for exact size
    result = ft_itoa(42);
    test_passed = (result != NULL && 
                  strcmp(result, "42") == 0 && 
                  strlen(result) == 2);
    print_test_result("Memory allocation exact size", test_passed);
    free(result);

    // Test 16: Series of numbers
    int test_numbers[] = {1, -1, 10, -10, 100, -100};
    test_passed = true;
    for (size_t i = 0; i < sizeof(test_numbers) / sizeof(int); i++) {
        result = ft_itoa(test_numbers[i]);
        expected = int_to_str(test_numbers[i]);
        if (result == NULL || strcmp(result, expected) != 0) {
            test_passed = false;
            break;
        }
        free(result);
        free(expected);
    }
    print_test_result("Series of numbers", test_passed);
}

int main(void) {
    printf("\nRunning ft_itoa tests...\n");
    printf("================================================\n");
    test_ft_itoa();
    printf("================================================\n");
    return 0;
}
