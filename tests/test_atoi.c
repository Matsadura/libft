#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void print_test_result(const char *test_name, bool passed) {
    printf("Test %-50s %s\n", test_name, passed ? "✅" : "❌");
}

void test_ft_atoi(void) {
    // Test case variables
    int result;
    int expected;
    
    // Test 1: Basic positive number
    result = ft_atoi("123");
    expected = atoi("123");
    print_test_result("Basic positive number", result == expected);

    // Test 2: Basic negative number
    result = ft_atoi("-123");
    expected = atoi("-123");
    print_test_result("Basic negative number", result == expected);

    // Test 3: Zero
    result = ft_atoi("0");
    expected = atoi("0");
    print_test_result("Zero", result == expected);

    // Test 4: Leading whitespaces
    result = ft_atoi("   \t\n\v\f\r  123");
    expected = atoi("   \t\n\v\f\r  123");
    print_test_result("Leading whitespaces", result == expected);

    // Test 5: Plus sign
    result = ft_atoi("+123");
    expected = atoi("+123");
    print_test_result("Plus sign", result == expected);

    // Test 6: Multiple signs (invalid)
    result = ft_atoi("++123");
    expected = atoi("++123");
    print_test_result("Multiple signs", result == expected);

    // Test 7: Letters after number
    result = ft_atoi("123abc");
    expected = atoi("123abc");
    print_test_result("Letters after number", result == expected);

    // Test 8: Letters before number
    result = ft_atoi("abc123");
    expected = atoi("abc123");
    print_test_result("Letters before number", result == expected);

    // Test 9: Empty string
    result = ft_atoi("");
    expected = atoi("");
    print_test_result("Empty string", result == expected);

    // Test 10: Only whitespace
    result = ft_atoi("   ");
    expected = atoi("   ");
    print_test_result("Only whitespace", result == expected);

    // Test 11: INT_MAX
    char max_str[20];
    sprintf(max_str, "%d", INT_MAX);
    result = ft_atoi(max_str);
    expected = atoi(max_str);
    print_test_result("INT_MAX", result == expected);

    // Test 12: INT_MIN
    char min_str[20];
    sprintf(min_str, "%d", INT_MIN);
    result = ft_atoi(min_str);
    expected = atoi(min_str);
    print_test_result("INT_MIN", result == expected);

    // Test 13: Long number sequence
    result = ft_atoi("000000000000123");
    expected = atoi("000000000000123");
    print_test_result("Long number sequence with leading zeros", result == expected);

    // Test 14: Multiple whitespaces between sign and number
    result = ft_atoi("-   123");
    expected = atoi("-   123");
    print_test_result("Whitespace between sign and number", result == expected);

    // Test 15: Special case - just a minus
    result = ft_atoi("-");
    expected = atoi("-");
    print_test_result("Just a minus sign", result == expected);

    // Test 16: Special case - plus and minus
    result = ft_atoi("+-123");
    expected = atoi("+-123");
    print_test_result("Plus and minus signs", result == expected);

    // Test 17: Very long valid number
    result = ft_atoi("123456789");
    expected = atoi("123456789");
    print_test_result("Very long valid number", result == expected);

    // Test 18: Null terminator in middle
    char str_with_null[] = "123\0456";
    result = ft_atoi(str_with_null);
    expected = atoi(str_with_null);
    print_test_result("Null terminator in middle", result == expected);
}

int main(void) {
    printf("\nRunning ft_atoi tests...\n");
    printf("================================================\n");
    test_ft_atoi();
    printf("================================================\n");
    return 0;
}
