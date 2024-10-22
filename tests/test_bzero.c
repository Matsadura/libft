#include "../libft.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

void print_memory(void *ptr, size_t len) {
    unsigned char *p = (unsigned char *)ptr;
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

void run_test(size_t size, size_t n) {
    // Allocate memory for both test cases
    void *expected = malloc(size);
    void *actual = malloc(size);
    
    // Initialize both buffers with the same pattern
    memset(expected, 0xAA, size); // 0xAA = 10101010 in binary
    memset(actual, 0xAA, size);
    
    printf("\nTest: bzero(ptr, %zu)\n", n);
    printf("Buffer size: %zu bytes\n", size);
    
    printf("\nBefore zeroing:\n");
    printf("Expected memory: ");
    print_memory(expected, size);
    printf("Actual memory:   ");
    print_memory(actual, size);
    
    // Apply bzero and ft_bzero
    bzero(expected, n);
    ft_bzero(actual, n);
    
    printf("\nAfter zeroing:\n");
    printf("Expected memory: ");
    print_memory(expected, size);
    printf("Actual memory:   ");
    print_memory(actual, size);
    
    // Compare memory contents
    printf("\nMemory content test: ");
    if (memcmp(expected, actual, size) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        printf("Differences found!\n");
        for (size_t i = 0; i < size; i++) {
            if (((unsigned char *)expected)[i] != ((unsigned char *)actual)[i]) {
                printf("Difference at byte %zu: expected 0x%02x, got 0x%02x\n",
                       i, ((unsigned char *)expected)[i], ((unsigned char *)actual)[i]);
            }
        }
    }
    
    // Verify zeroed region
    printf("Zero verification: ");
    int zero_check = 1;
    for (size_t i = 0; i < n; i++) {
        if (((unsigned char *)actual)[i] != 0) {
            zero_check = 0;
            break;
        }
    }
    printf("%s\n", zero_check ? "PASS" : "FAIL");
    
    printf("\n");
    
    // Free allocated memory
    free(expected);
    free(actual);
}

int main() {
    // Basic test cases
    run_test(10, 5);           // Partial buffer zeroing
    run_test(10, 10);          // Full buffer zeroing
    run_test(1, 1);            // Single byte
    run_test(100, 50);         // Large buffer, partial zeroing
    run_test(20, 0);           // Zero length (should not modify memory)
    run_test(1024, 512);       // Large buffer test
    
    // Test with string
    printf("String test:\n");
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    
    printf("Before - str1: %s\n", str1);
    printf("Before - str2: %s\n", str2);
    
    bzero(str1, 5);
    ft_bzero(str2, 5);
    
    printf("After  - str1: ");
    print_memory(str1, strlen("Hello, World!"));
    printf("After  - str2: ");
    print_memory(str2, strlen("Hello, World!"));
    
    if (memcmp(str1, str2, strlen("Hello, World!")) == 0) {
        printf("String test: PASS\n");
    } else {
        printf("String test: FAIL\n");
    }
    
    // Test with struct
    printf("\nStruct test:\n");
    struct {
        int a;
        char b;
        double c;
    } s1 = {42, 'X', 3.14}, s2 = {42, 'X', 3.14};
    
    printf("Before zeroing - size of struct: %zu bytes\n", sizeof(s1));
    printf("s1: ");
    print_memory(&s1, sizeof(s1));
    printf("s2: ");
    print_memory(&s2, sizeof(s2));
    
    bzero(&s1, sizeof(s1));
    ft_bzero(&s2, sizeof(s2));
    
    printf("\nAfter zeroing:\n");
    printf("s1: ");
    print_memory(&s1, sizeof(s1));
    printf("s2: ");
    print_memory(&s2, sizeof(s2));
    
    if (memcmp(&s1, &s2, sizeof(s1)) == 0) {
        printf("Struct test: PASS\n");
    } else {
        printf("Struct test: FAIL\n");
    }
    
    return 0;
}
