#include <stdio.h>
#include "../libft.h"
#include <string.h>
#include <stdbool.h>

void print_test_result(const char *test_name, bool passed) {
    printf("Test %-50s %s\n", test_name, passed ? "✅" : "❌");
}

void test_ft_strnstr(void) {
    // Test case variables
    char *result;
    char *expected;
    
    // Test 1: Basic needle found
    char str1[] = "Hello World";
    char needle1[] = "World";
    result = ft_strnstr(str1, needle1, strlen(str1));
    expected = strstr(str1, needle1);
    print_test_result("Basic needle found", result == expected);

    // Test 2: Empty needle
    result = ft_strnstr(str1, "", strlen(str1));
    print_test_result("Empty needle", result == str1);

    // Test 3: Needle not found
    char needle2[] = "Goodbye";
    result = ft_strnstr(str1, needle2, strlen(str1));
    print_test_result("Needle not found", result == NULL);

    // Test 4: len shorter than needle
    result = ft_strnstr(str1, needle1, 3);
    print_test_result("Length shorter than needle", result == NULL);

    // Test 5: len is 0
    result = ft_strnstr(str1, needle1, 0);
    print_test_result("Zero length", result == NULL);

    // Test 6: Needle longer than haystack
    char str2[] = "Hi";
    char needle3[] = "Hello";
    result = ft_strnstr(str2, needle3, strlen(str2));
    print_test_result("Needle longer than haystack", result == NULL);

    // Test 7: Multiple occurrences
    char str3[] = "hello hello hello";
    char needle4[] = "hello";
    result = ft_strnstr(str3, needle4, strlen(str3));
    expected = strstr(str3, needle4);
    print_test_result("Multiple occurrences (first)", result == expected);

    // Test 8: Partial match but len stops
    result = ft_strnstr("Hello World", "World", 8);
    print_test_result("Partial match but len stops", result == NULL);

    // Test 9: NULL haystack with len 0
    result = ft_strnstr(NULL, "test", 0);
    print_test_result("NULL haystack with len 0", result == NULL);

    // Test 10: Case sensitivity
    result = ft_strnstr("Hello World", "world", strlen("Hello World"));
    print_test_result("Case sensitivity", result == NULL);

    // Test 11: Needle at the end
    char str4[] = "Testing at end test";
    char needle5[] = "test";
    result = ft_strnstr(str4, needle5, strlen(str4));
    expected = strstr(str4, needle5);
    print_test_result("Needle at the end", result == expected);

    // Test 12: Special characters
    char str5[] = "Hello\n\tWorld";
    char needle6[] = "\n\t";
    result = ft_strnstr(str5, needle6, strlen(str5));
    expected = strstr(str5, needle6);
    print_test_result("Special characters", result == expected);
}

int main(void) {
    printf("\nRunning ft_strnstr tests...\n");
    printf("================================================\n");
    test_ft_strnstr();
    printf("================================================\n");
    return 0;
}
