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

// Helper function to create and initialize a buffer with a pattern
unsigned char *create_buffer(size_t size) {
    unsigned char *buf = (unsigned char *)malloc(size);
    for (size_t i = 0; i < size; i++) {
        buf[i] = (unsigned char)(i & 0xFF);
    }
    return buf;
}

void run_overlap_test(size_t buf_size, size_t overlap_size, size_t offset, const char *test_name) {
    // Create two identical buffers for testing
    unsigned char *buf1 = create_buffer(buf_size);
    unsigned char *buf2 = create_buffer(buf_size);
    
    printf("\nTest: %s\n", test_name);
    printf("Buffer size: %zu, Overlap size: %zu, Offset: %zu\n", buf_size, overlap_size, offset);
    
    printf("\nInitial buffers:\n");
    printf("Buffer 1: ");
    print_memory(buf1, buf_size);
    printf("Buffer 2: ");
    print_memory(buf2, buf_size);
    
    // Perform moves
    memmove(buf1 + offset, buf1, overlap_size);
    ft_memmove(buf2 + offset, buf2, overlap_size);
    
    printf("\nAfter move:\n");
    printf("Standard memmove: ");
    print_memory(buf1, buf_size);
    printf("Your ft_memmove:  ");
    print_memory(buf2, buf_size);
    
    // Compare results
    printf("\nTest result: ");
    if (memcmp(buf1, buf2, buf_size) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        printf("Differences found:\n");
        for (size_t i = 0; i < buf_size; i++) {
            if (buf1[i] != buf2[i]) {
                printf("Byte %zu: expected 0x%02x, got 0x%02x\n",
                       i, buf1[i], buf2[i]);
            }
        }
    }
    
    printf("\n");
    free(buf1);
    free(buf2);
}

void run_standard_test(const void *src, size_t n, const char *test_name) {
    void *dst1 = malloc(n);
    void *dst2 = malloc(n);
    
    // Initialize destinations with pattern
    memset(dst1, 0xAA, n);
    memset(dst2, 0xAA, n);
    
    printf("\nTest: %s\n", test_name);
    printf("Size: %zu bytes\n", n);
    
    printf("\nSource memory:     ");
    print_memory(src, n);
    printf("Initial dst1:      ");
    print_memory(dst1, n);
    printf("Initial dst2:      ");
    print_memory(dst2, n);
    
    // Perform moves
    void *ret1 = memmove(dst1, src, n);
    void *ret2 = ft_memmove(dst2, src, n);
    
    printf("\nAfter move:\n");
    printf("Standard memmove:  ");
    print_memory(dst1, n);
    printf("Your ft_memmove:   ");
    print_memory(dst2, n);
    
    // Compare results
    printf("\nTests:\n");
    printf("Return value test: %s\n", 
           ((ret1 == dst1) && (ret2 == dst2)) ? "PASS" : "FAIL");
    printf("Content test:      %s\n",
           (memcmp(dst1, dst2, n) == 0) ? "PASS" : "FAIL");
    
    printf("\n");
    free(dst1);
    free(dst2);
}

int main() {
    // Test 1: Basic non-overlapping tests
    const char *str = "Hello, World!";
    run_standard_test(str, strlen(str) + 1, "Basic string test");
    
    int numbers[] = {1, 2, 3, 4, 5};
    run_standard_test(numbers, sizeof(numbers), "Integer array test");
    
    // Test 2: Overlapping tests - forward
    run_overlap_test(20, 10, 5, "Forward overlap test");  // Source before destination
    
    // Test 3: Overlapping tests - backward
    run_overlap_test(20, 10, -5, "Backward overlap test");  // Source after destination
    
    // Test 4: Edge cases
    run_overlap_test(10, 10, 0, "Full buffer overlap test");  // Complete overlap
    run_overlap_test(100, 1, 50, "Single byte move test");    // Single byte
    run_standard_test(str, 0, "Zero length test");            // Zero length
    
    // Test 5: Large buffer test
    size_t large_size = 1024;
    unsigned char *large_buf = create_buffer(large_size);
    run_standard_test(large_buf, large_size, "Large buffer test");
    free(large_buf);
    
    // Test 6: Specific overlap scenarios
    printf("\nSpecific overlap scenarios:\n");
    
    // Test 6.1: Partial overlap with source at start
    char buf1[] = "abcdefghijklmnopqrstuvwxyz";
    char buf2[] = "abcdefghijklmnopqrstuvwxyz";
    printf("Original buffer:     %s\n", buf1);
    memmove(buf1 + 3, buf1, 10);
    ft_memmove(buf2 + 3, buf2, 10);
    printf("After std memmove:   %s\n", buf1);
    printf("After ft_memmove:    %s\n", buf2);
    printf("Result: %s\n\n", (strcmp(buf1, buf2) == 0) ? "PASS" : "FAIL");
    
    // Test 6.2: Partial overlap with destination at start
    char buf3[] = "abcdefghijklmnopqrstuvwxyz";
    char buf4[] = "abcdefghijklmnopqrstuvwxyz";
    printf("Original buffer:     %s\n", buf3);
    memmove(buf3, buf3 + 3, 10);
    ft_memmove(buf4, buf4 + 3, 10);
    printf("After std memmove:   %s\n", buf3);
    printf("After ft_memmove:    %s\n", buf4);
    printf("Result: %s\n", (strcmp(buf3, buf4) == 0) ? "PASS" : "FAIL");
    
    return 0;
}
