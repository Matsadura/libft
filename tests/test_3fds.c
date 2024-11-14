#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
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

void test_ft_putstr_fd() {
    printf("\n=== Testing ft_putstr_fd ===\n\n");
    int fd = open(TEST_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error opening test file\n");
        return;
    }

    // Test 1: Basic string
    {
        ft_putstr_fd("Hello World", fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "Hello World") == 0;
        print_result(passed);
        printf("Basic string output\n");
        free(content);
        ftruncate(fd, 0);  // Clear file
    }

    // Test 2: Empty string
    {
        ft_putstr_fd("", fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "") == 0;
        print_result(passed);
        printf("Empty string\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 3: NULL string
    {
        ft_putstr_fd(NULL, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "") == 0;
        print_result(passed);
        printf("NULL string handling\n");
        free(content);
        ftruncate(fd, 0);
    }

    close(fd);
}

void test_ft_putendl_fd() {
    printf("\n=== Testing ft_putendl_fd ===\n\n");
    int fd = open(TEST_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error opening test file\n");
        return;
    }

    // Test 1: Basic string with newline
    {
        ft_putendl_fd("Hello World", fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "Hello World\n") == 0;
        print_result(passed);
        printf("Basic string output with newline\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 2: Empty string with newline
    {
        ft_putendl_fd("", fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "\n") == 0;
        print_result(passed);
        printf("Empty string with newline\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 3: Multiple lines
    {
        ft_putendl_fd("Line 1", fd);
        ft_putendl_fd("Line 2", fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "Line 1\nLine 2\n") == 0;
        print_result(passed);
        printf("Multiple lines\n");
        free(content);
        ftruncate(fd, 0);
    }

    close(fd);
}

void test_ft_putnbr_fd() {
    printf("\n=== Testing ft_putnbr_fd ===\n\n");
    int fd = open(TEST_FILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("Error opening test file\n");
        return;
    }

    // Test 1: Basic positive number
    {
        ft_putnbr_fd(42, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "42") == 0;
        print_result(passed);
        printf("Basic positive number\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 2: Zero
    {
        ft_putnbr_fd(0, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "0") == 0;
        print_result(passed);
        printf("Zero\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 3: Negative number
    {
        ft_putnbr_fd(-42, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "-42") == 0;
        print_result(passed);
        printf("Negative number\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 4: INT_MAX
    {
        ft_putnbr_fd(2147483647, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "2147483647") == 0;
        print_result(passed);
        printf("INT_MAX\n");
        free(content);
        ftruncate(fd, 0);
    }

    // Test 5: INT_MIN
    {
        ft_putnbr_fd(-2147483648, fd);
        char *content = read_file_content(fd);
        int passed = content && strcmp(content, "-2147483648") == 0;
        print_result(passed);
        printf("INT_MIN\n");
        free(content);
        ftruncate(fd, 0);
    }

    close(fd);
}

int main(void) {
    // Remove any existing test file
    unlink(TEST_FILE);
    
    test_ft_putstr_fd();
    test_ft_putendl_fd();
    test_ft_putnbr_fd();

    // Clean up
    unlink(TEST_FILE);
    return 0;
}
