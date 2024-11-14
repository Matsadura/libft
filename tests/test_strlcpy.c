#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to create a filled buffer
char *create_filled_buffer(size_t size, char fill) {
    char *buf = (char *)malloc(size);
    memset(buf, fill, size);
    return buf;
}

void print_buffer(const char *buf, size_t size) {
    printf("\"");
    for (size_t i = 0; i < size; i++) {
        if (buf[i] == '\0') {
            printf("\\0");
        } else if (buf[i] < 32 || buf[i] > 126) {
            printf("\\x%02x", (unsigned char)buf[i]);
        } else {
            printf("%c", buf[i]);
        }
    }
    printf("\"\n");
}

void run_test(const char *src, size_t dst_size, const char *test_name) {
    // Create two identical destination buffers
    char *dst1 = create_filled_buffer(dst_size, 'X');
    char *dst2 = create_filled_buffer(dst_size, 'X');

    printf("\n=== Test: %s ===\n", test_name);
    printf("Source string: ");
    print_buffer(src, strlen(src) + 1);
    printf("Destination size: %zu\n", dst_size);

    printf("\nBefore copy:\n");
    printf("dst1 (strlcpy):    ");
    print_buffer(dst1, dst_size);
    printf("dst2 (ft_strlcpy): ");
    print_buffer(dst2, dst_size);

    // Perform copies and store return values
    size_t ret1 = strlcpy(dst1, src, dst_size);
    size_t ret2 = ft_strlcpy(dst2, src, dst_size);

    printf("\nAfter copy:\n");
    printf("dst1 (strlcpy):    ");
    print_buffer(dst1, dst_size);
    printf("dst2 (ft_strlcpy): ");
    print_buffer(dst2, dst_size);

    printf("\nReturn values:\n");
    printf("strlcpy:    %zu\n", ret1);
    printf("ft_strlcpy: %zu\n", ret2);

    // Compare results
    printf("\nTests:\n");

    // Test 1: Return value check
    printf("Return value test:     ");
    if (ret1 == ret2) {
        printf("PASS\n");
    } else {
        printf("FAIL (should return %zu, got %zu)\n", ret1, ret2);
    }

    // Test 2: Content check
    printf("Content test:          ");
    if (memcmp(dst1, dst2, dst_size) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        printf("Differences found:\n");
        for (size_t i = 0; i < dst_size; i++) {
            if (dst1[i] != dst2[i]) {
                printf("Byte %zu: expected '%c' (0x%02x), got '%c' (0x%02x)\n",
                       i,
                       dst1[i] >= 32 && dst1[i] <= 126 ? dst1[i] : '.',
                       (unsigned char)dst1[i],
                       dst2[i] >= 32 && dst2[i] <= 126 ? dst2[i] : '.',
                       (unsigned char)dst2[i]);
            }
        }
    }

    // Test 3: Null termination check (when dstsize > 0)
    if (dst_size > 0) {
        printf("Null termination test: ");
        if (dst2[dst_size - 1] == '\0' || (dst_size > 0 && dst2[dst_size - 1] == 'X')) {
            printf("PASS\n");
        } else {
            printf("FAIL (last byte should be null or untouched)\n");
        }
    }

    printf("\n");
    free(dst1);
    free(dst2);
}

int main() {
    // Test 1: Basic case - normal string copy
    run_test("Hello, World!", 20, "Basic string copy");

    // Test 2: Exact size (including null terminator)
    run_test("Hello", 6, "Exact buffer size");

    // Test 3: Destination size smaller than source
    run_test("Hello, World!", 5, "Truncated copy");

    // Test 4: Empty string source
    run_test("", 10, "Empty source string");

    // Test 5: Single character
    run_test("X", 2, "Single character");

    // Test 6: Zero size destination
    run_test("Hello", 0, "Zero destination size");

    // Test 7: Destination size of 1 (should only write null terminator)
    run_test("Hello", 1, "Destination size 1");

    // Test 8: String with special characters
    run_test("Hello\n\t\r\0World", 20, "String with special characters");

    // Test 9: Long string
    char *long_str = create_filled_buffer(1000, 'A');
    long_str[999] = '\0';
    run_test(long_str, 50, "Long string truncation");
    free(long_str);

    // Test 10: Destination size exactly one less than source length
    run_test("Hello!", 5, "Destination size one less than needed");

    // Test 11: String with multiple null terminators
    char multi_null[] = {'H', 'e', 'l', '\0', 'l', 'o', '\0'};
    run_test(multi_null, 10, "String with multiple null terminators");

    // Test 12: Very small destination size with long source
    run_test("This is a very long string that will be heavily truncated", 3,
             "Heavy truncation");

    // Test 13: All printable ASCII characters
    char ascii[128];
    for (int i = 32; i < 127; i++) {
        ascii[i - 32] = i;
    }
    ascii[95] = '\0';
    run_test(ascii, 100, "All printable ASCII characters");

    // Test 14: Maximum boundary test
    char *large_src = create_filled_buffer(1000, 'A');
    char *large_dst = create_filled_buffer(1000, 'X');
    large_src[999] = '\0';
    printf("\n=== Large Buffer Boundary Test ===\n");
    size_t ret = ft_strlcpy(large_dst, large_src, 1000);
    printf("Return value for 1000-byte copy: %zu (expected %zu)\n",
           ret, strlen(large_src));
    free(large_src);
    free(large_dst);

    return 0;
}
