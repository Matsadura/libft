#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void print_test_result(const char *test_name, bool passed) {
    printf("Test %-50s %s\n", test_name, passed ? "✅" : "❌");
}

// Helper function to check if memory is zero-initialized
bool is_zero_initialized(void *ptr, size_t size) {
    unsigned char *p = (unsigned char *)ptr;
    for (size_t i = 0; i < size; i++) {
        if (p[i] != 0) {
            return false;
        }
    }
    return true;
}

void test_ft_calloc(void) {
    void *ptr;
    void *std_ptr;
    bool test_passed;
    
    // Test 1: Basic allocation (integers)
    ptr = ft_calloc(5, sizeof(int));
    test_passed = (ptr != NULL && is_zero_initialized(ptr, 5 * sizeof(int)));
    print_test_result("Basic allocation (integers)", test_passed);
    free(ptr);

    // Test 2: Basic allocation (chars)
    ptr = ft_calloc(10, sizeof(char));
    test_passed = (ptr != NULL && is_zero_initialized(ptr, 10 * sizeof(char)));
    print_test_result("Basic allocation (chars)", test_passed);
    free(ptr);

    // Test 3: Zero count
    ptr = ft_calloc(0, sizeof(int));
    std_ptr = calloc(0, sizeof(int));
    // Both should return a valid pointer that can be freed, or both NULL
    test_passed = ((ptr == NULL && std_ptr == NULL) || (ptr != NULL && std_ptr != NULL));
    print_test_result("Zero count", test_passed);
    free(ptr);
    free(std_ptr);

    // Test 4: Zero size
    ptr = ft_calloc(5, 0);
    std_ptr = calloc(5, 0);
    test_passed = ((ptr == NULL && std_ptr == NULL) || (ptr != NULL && std_ptr != NULL));
    print_test_result("Zero size", test_passed);
    free(ptr);
    free(std_ptr);

    // Test 5: One element
    ptr = ft_calloc(1, 1);
    test_passed = (ptr != NULL && is_zero_initialized(ptr, 1));
    print_test_result("One element", test_passed);
    free(ptr);

    // Test 6: Large allocation
    ptr = ft_calloc(1024, sizeof(int));
    test_passed = (ptr != NULL && is_zero_initialized(ptr, 1024 * sizeof(int)));
    print_test_result("Large allocation", test_passed);
    free(ptr);

    // Test 7: Overflow check
    ptr = ft_calloc(SIZE_MAX, SIZE_MAX);
    test_passed = (ptr == NULL); // Should return NULL due to overflow
    print_test_result("Overflow check (SIZE_MAX, SIZE_MAX)", test_passed);
    free(ptr);

    // Test 8: Overflow check with more subtle values
    ptr = ft_calloc(SIZE_MAX, 2);
    test_passed = (ptr == NULL); // Should return NULL due to overflow
    print_test_result("Overflow check (SIZE_MAX, 2)", test_passed);
    free(ptr);

    // Test 9: Write test
    int *int_ptr = (int *)ft_calloc(5, sizeof(int));
    if (int_ptr != NULL) {
        // Try writing to the allocated memory
        for (int i = 0; i < 5; i++) {
            int_ptr[i] = i;
        }
        // Verify written values
        test_passed = true;
        for (int i = 0; i < 5; i++) {
            if (int_ptr[i] != i) {
                test_passed = false;
                break;
            }
        }
    } else {
        test_passed = false;
    }
    print_test_result("Write and read test", test_passed);
    free(int_ptr);

    // Test 10: Array of pointers
    void **ptr_array = (void **)ft_calloc(10, sizeof(void *));
    test_passed = (ptr_array != NULL && is_zero_initialized(ptr_array, 10 * sizeof(void *)));
    print_test_result("Array of pointers", test_passed);
    free(ptr_array);

    // Test 11: Alignment test (for doubles)
    double *d_ptr = (double *)ft_calloc(5, sizeof(double));
    test_passed = (d_ptr != NULL && 
                  is_zero_initialized(d_ptr, 5 * sizeof(double)) &&
                  ((uintptr_t)d_ptr % sizeof(double) == 0)); // Check alignment
    print_test_result("Alignment test (doubles)", test_passed);
    free(d_ptr);

    // Test 12: Very small allocation
    ptr = ft_calloc(1, 1);
    test_passed = (ptr != NULL && is_zero_initialized(ptr, 1));
    print_test_result("Very small allocation (1 byte)", test_passed);
    free(ptr);
}

int main(void) {
    printf("\nRunning ft_calloc tests...\n");
    printf("================================================\n");
    test_ft_calloc();
    printf("================================================\n");
    return 0;
}
