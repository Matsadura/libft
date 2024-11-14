#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "../libft.h"

#define TEST_FILE "test_output.txt"
#define BUFFER_SIZE 1024

void print_result(int passed) {
    if (passed)
        printf("✅ ");
    else
        printf("❌ ");
}

char *read_file_content(int fd) {
    char *buffer = malloc(BUFFER_SIZE);
    if (!buffer)
        return NULL;
    
    lseek(fd, 0, SEEK_SET);  // Reset file position to start
    ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytes_read >= 0)
        buffer[bytes_read] = '\0';
    else {
        free(buffer);
        return NULL;
    }
    return buffer;
}

void test_ft_putnbr_fd() {
    printf("\n=== Testing ft_putnbr_fd ===\n\n");
    
    int fd = open(TEST_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error opening test file\n");
        return;
    }

    // Test 1: Zero
    {
        ft_putnbr_fd(0, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "0") == 0;
        print_result(passed);
        printf("Number: 0\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 2: Positive single digit
    {
        ft_putnbr_fd(7, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "7") == 0;
        print_result(passed);
        printf("Single digit positive: 7\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 3: Negative single digit
    {
        ft_putnbr_fd(-5, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "-5") == 0;
        print_result(passed);
        printf("Single digit negative: -5\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 4: Positive multiple digits
    {
        ft_putnbr_fd(42042, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "42042") == 0;
        print_result(passed);
        printf("Multiple digits positive: 42042\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 5: Negative multiple digits
    {
        ft_putnbr_fd(-42042, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "-42042") == 0;
        print_result(passed);
        printf("Multiple digits negative: -42042\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 6: INT_MAX
    {
        ft_putnbr_fd(INT_MAX, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "2147483647") == 0;
        print_result(passed);
        printf("INT_MAX: 2147483647\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 7: INT_MIN
    {
        ft_putnbr_fd(INT_MIN, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "-2147483648") == 0;
        print_result(passed);
        printf("INT_MIN: -2147483648\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 8: Sequence of numbers
    {
        ft_putnbr_fd(42, fd);
        ft_putnbr_fd(0, fd);
        ft_putnbr_fd(-42, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "420-42") == 0;
        print_result(passed);
        printf("Sequence of numbers: 42, 0, -42\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 9: Invalid file descriptor
    {
        int invalid_fd = -1;
        ft_putnbr_fd(42, invalid_fd);
        print_result(1); // Pass if no crash
        printf("Invalid file descriptor (-1)\n");
    }

    // Test 10: Large number with multiple zeroes
    {
        ft_putnbr_fd(100000, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "100000") == 0;
        print_result(passed);
        printf("Large number with multiple zeroes: 100000\n");
        free(content);
        ftruncate(fd, 0);
    }

    close(fd);
}

int main(void) {
    // Remove any existing test file
    unlink(TEST_FILE);
    
    test_ft_putnbr_fd();
    
    // Clean up
    unlink(TEST_FILE);
    return 0;
}
