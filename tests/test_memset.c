#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_memory(void *ptr, size_t len) {
    unsigned char *p = (unsigned char *)ptr;
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

void run_test(size_t size, int c, size_t len) {
    // Allocate memory for both test cases
    void *expected = malloc(size);
    void *actual = malloc(size);
    
    // Initialize memory with a pattern to see changes
    memset(expected, 0xFF, size);
    memset(actual, 0xFF, size);
    
    // Run both functions
    void *exp_ret = memset(expected, c, len);
    void *act_ret = ft_memset(actual, c, len);
    
    printf("\nTest: memset(ptr, %d ('\\x%02x'), %zu)\n", c, (unsigned char)c, len);
    printf("Buffer size: %zu bytes\n", size);
    
    printf("\nExpected memory: ");
    print_memory(expected, size);
    printf("Actual memory:   ");
    print_memory(actual, size);
    
    // Compare return values
    printf("\nReturn value test: ");
    if (exp_ret == expected && act_ret == actual) {
        printf("PASS (Both return original pointer)\n");
    } else {
        printf("FAIL (Return values don't match)\n");
    }
    
    // Compare memory contents
    printf("Memory content test: ");
    if (memcmp(expected, actual, size) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
    
    printf("\n");
    
    // Free allocated memory
    free(expected);
    free(actual);
}

int main() {
    // Test cases
    run_test(10, 'A', 5);          // Partial buffer fill with character
    run_test(10, 0, 10);           // Full buffer fill with zeros
    run_test(10, 0xFF, 10);        // Full buffer fill with 0xFF
    run_test(20, '0', 15);         // Large buffer, partial fill
    run_test(1, 'x', 1);           // Single byte
    run_test(100, '\0', 50);       // Larger buffer with null characters
    run_test(10, -1, 7);           // Negative value (should use last byte)
    run_test(10, 256+'A', 8);      // Value > 255 (should truncate)
    run_test(16, 0x42, 16);        // Full buffer with hex value
    
    // Test with string
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    printf("String test with 'Hello, World!'\n");
    printf("Before - str1: %s\n", str1);
    printf("Before - str2: %s\n", str2);
    
    memset(str1, '*', 5);
    ft_memset(str2, '*', 5);
    
    printf("After  - str1: %s\n", str1);
    printf("After  - str2: %s\n", str2);
    if (strcmp(str1, str2) == 0) {
        printf("String test: PASS\n");
    } else {
        printf("String test: FAIL\n");
    }
    
    return 0;
}
