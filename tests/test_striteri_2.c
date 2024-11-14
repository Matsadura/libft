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

// Test functions to pass to ft_striteri
void to_upper(unsigned int i, char *c) {
    (void)i;  // Unused parameter
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

void to_index_char(unsigned int i, char *c) {
    *c = '0' + (i % 10);
}

void alternate_case(unsigned int i, char *c) {
    if (i % 2 == 0) {
        if (*c >= 'a' && *c <= 'z')
            *c = *c - 32;
    } else {
        if (*c >= 'A' && *c <= 'Z')
            *c = *c + 32;
    }
}

void add_index_to_char(unsigned int i, char *c) {
    if (*c >= 'a' && *c <= 'z')
        *c = 'a' + ((*c - 'a' + i) % 26);
}

void test_ft_striteri() {
    printf("\n=== Testing ft_striteri ===\n\n");

    // Test 1: Basic uppercase conversion
    {
        char str1[] = "hello";
        char expected1[] = "HELLO";
        ft_striteri(str1, &to_upper);
        int passed = (strcmp(str1, expected1) == 0);
        print_result(passed);
        printf("Basic uppercase conversion\n");
    }

    // Test 2: Replace with indices
    {
        char str2[] = "test";
        char expected2[] = "0123";
        ft_striteri(str2, &to_index_char);
        int passed = (strcmp(str2, expected2) == 0);
        print_result(passed);
        printf("Replace with indices\n");
    }

    // Test 3: Alternate case
    {
        char str3[] = "hello world";
        char expected3[] = "HeLlO wOrLd";
        ft_striteri(str3, &alternate_case);
        int passed = (strcmp(str3, expected3) == 0);
        print_result(passed);
        printf("Alternate case\n");
    }

    // Test 4: Empty string
    {
        char str4[] = "";
        char expected4[] = "";
        ft_striteri(str4, &to_upper);
        int passed = (strcmp(str4, expected4) == 0);
        print_result(passed);
        printf("Empty string\n");
    }

    // Test 5: NULL string
    {
        ft_striteri(NULL, &to_upper);
        print_result(1); // Pass if no segfault occurred
        printf("NULL string (no crash)\n");
    }

    // Test 6: NULL function
    {
        char str6[] = "test";
        char expected6[] = "test";
        ft_striteri(str6, NULL);
        int passed = (strcmp(str6, expected6) == 0);
        print_result(passed);
        printf("NULL function\n");
    }

    // Test 7: String with special characters
    {
        char str7[] = "Hello! @World#";
        char expected7[] = "HELLO! @WORLD#";
        ft_striteri(str7, &to_upper);
        int passed = (strcmp(str7, expected7) == 0);
        print_result(passed);
        printf("String with special characters\n");
    }

    // Test 8: Single character
    {
        char str8[] = "x";
        char expected8[] = "X";
        ft_striteri(str8, &to_upper);
        int passed = (strcmp(str8, expected8) == 0);
        print_result(passed);
        printf("Single character\n");
    }

    // Test 9: Index-based modification
    {
        char str9[] = "abcdefg";
        char expected9[] = "acegikm";
        ft_striteri(str9, &add_index_to_char);
        int passed = (strcmp(str9, expected9) == 0);
        print_result(passed);
        printf("Index-based character modification\n");
    }

    // Test 10: Long string
    {
        char str10[1000];
        char expected10[1000];
        memset(str10, 'a', 999);
        memset(expected10, 'A', 999);
        str10[999] = '\0';
        expected10[999] = '\0';
        
        ft_striteri(str10, &to_upper);
        int passed = (strcmp(str10, expected10) == 0);
        print_result(passed);
        printf("Long string (1000 chars)\n");
    }
}

int main(void) {
    test_ft_striteri();
    return 0;
}
