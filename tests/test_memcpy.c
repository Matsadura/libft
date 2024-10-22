#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_memory(const void *ptr, size_t len) {
    const unsigned char *p = (const unsigned char *)ptr;
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");
}

void run_test(const void *src, size_t n, const char *test_name) {
    // Allocate memory for destination buffers
    void *dst1 = malloc(n);
    void *dst2 = malloc(n);

    // Initialize destination buffers with a pattern
    memset(dst1, 0xAA, n);
    memset(dst2, 0xAA, n);

    printf("\nTest: %s\n", test_name);
    printf("Size: %zu bytes\n", n);

    printf("\nSource memory:      ");
    print_memory(src, n);
    printf("Initial dst1:       ");
    print_memory(dst1, n);
    printf("Initial dst2:       ");
    print_memory(dst2, n);

    // Perform copy operations
    void *ret1 = memcpy(dst1, src, n);
    void *ret2 = ft_memcpy(dst2, src, n);

    printf("\nAfter copy:\n");
    printf("Standard memcpy:    ");
    print_memory(dst1, n);
    printf("Your ft_memcpy:     ");
    print_memory(dst2, n);

    // Compare results
    printf("\nTests:\n");

    // Test 1: Return value check
    printf("Return value test:  ");
    if ((ret1 == dst1) && (ret2 == dst2)) {
        printf("PASS\n");
    } else {
        printf("FAIL (should return destination pointer)\n");
    }

    // Test 2: Content check
    printf("Content test:       ");
    if (memcmp(dst1, dst2, n) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        printf("Differences found:\n");
        for (size_t i = 0; i < n; i++) {
            if (((unsigned char *)dst1)[i] != ((unsigned char *)dst2)[i]) {
                printf("Byte %zu: expected 0x%02x, got 0x%02x\n",
                       i, ((unsigned char *)dst1)[i], ((unsigned char *)dst2)[i]);
            }
        }
    }

    printf("\n");

    // Free allocated memory
    free(dst1);
    free(dst2);
}

// Test structure copy
struct test_struct {
    int a;
    char b;
    double c;
    char str[10];
};

int main() {
    // Test 1: Basic string copy
    const char *str = "Hello, World!";
    run_test(str, strlen(str) + 1, "String copy test");

    // Test 2: Zero bytes copy
    run_test(str, 0, "Zero bytes copy test");

    // Test 3: Single byte copy
    char single_byte = 'X';
    run_test(&single_byte, 1, "Single byte copy test");

    // Test 4: Integer array copy
    int int_array[] = {1, 2, 3, 4, 5};
    run_test(int_array, sizeof(int_array), "Integer array copy test");

    // Test 5: Structure copy
    struct test_struct ts = {42, 'A', 3.14, "test"};
    run_test(&ts, sizeof(struct test_struct), "Structure copy test");

    // Test 6: Binary data copy
    unsigned char binary[] = {0xFF, 0x00, 0xAA, 0x55, 0x0F, 0xF0};
    run_test(binary, sizeof(binary), "Binary data copy test");

    // Test 7: Large buffer copy
    size_t large_size = 1024;
    void *large_buf = malloc(large_size);
    for (size_t i = 0; i < large_size; i++) {
        ((unsigned char *)large_buf)[i] = (unsigned char)(i & 0xFF);
    }
    run_test(large_buf, large_size, "Large buffer copy test");
    free(large_buf);

    // Test 8: NULL terminator in middle of buffer
    char null_str[] = "Hello\0World";
    run_test(null_str, sizeof(null_str), "NULL terminator test");

    // Test 9: All bits set
    unsigned char all_bits_set = 0xFF;
    run_test(&all_bits_set, sizeof(all_bits_set), "All bits set test");

    // Test 10: Mixed data test
    struct {
        int a;
        char b[5];
        double c;
    } mixed_data = {123, "test", 45.67};
    run_test(&mixed_data, sizeof(mixed_data), "Mixed data test");

    return 0;
}
