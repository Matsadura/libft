#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libft.h"

void print_result(int passed) {
    if (passed)
        printf("✅ ");
    else
        printf("❌ ");
}

// Helper function to safely free allocated memory
void safe_free(void *ptr) {
    if (ptr)
        free(ptr);
}

void test_ft_lstnew() {
    printf("\n=== Testing ft_lstnew ===\n\n");

    // Test 1: Create node with string content
    {
        char *str = strdup("test string");
        t_list *node = ft_lstnew(str);
        int passed = (node != NULL && 
                     node->content == str && 
                     strcmp((char *)node->content, "test string") == 0 && 
                     node->next == NULL);
        print_result(passed);
        printf("Node with string content\n");
        safe_free(str);
        safe_free(node);
    }

    // Test 2: Create node with NULL content
    {
        t_list *node = ft_lstnew(NULL);
        int passed = (node != NULL && 
                     node->content == NULL && 
                     node->next == NULL);
        print_result(passed);
        printf("Node with NULL content\n");
        safe_free(node);
    }

    // Test 3: Create node with integer content
    {
        int *num = malloc(sizeof(int));
        *num = 42;
        t_list *node = ft_lstnew(num);
        int passed = (node != NULL && 
                     node->content == num && 
                     *(int *)node->content == 42 && 
                     node->next == NULL);
        print_result(passed);
        printf("Node with integer content\n");
        safe_free(num);
        safe_free(node);
    }

    // Test 4: Create node with char content
    {
        char *c = malloc(sizeof(char));
        *c = 'A';
        t_list *node = ft_lstnew(c);
        int passed = (node != NULL && 
                     node->content == c && 
                     *(char *)node->content == 'A' && 
                     node->next == NULL);
        print_result(passed);
        printf("Node with char content\n");
        safe_free(c);
        safe_free(node);
    }

    // Test 5: Create node with empty string
    {
        char *empty_str = strdup("");
        t_list *node = ft_lstnew(empty_str);
        int passed = (node != NULL && 
                     node->content == empty_str && 
                     strcmp((char *)node->content, "") == 0 && 
                     node->next == NULL);
        print_result(passed);
        printf("Node with empty string\n");
        safe_free(empty_str);
        safe_free(node);
    }

    // Test 6: Create node with large content
    {
        char *large_str = malloc(1000);
        memset(large_str, 'A', 999);
        large_str[999] = '\0';
        t_list *node = ft_lstnew(large_str);
        int passed = (node != NULL && 
                     node->content == large_str && 
                     strlen((char *)node->content) == 999 && 
                     node->next == NULL);
        print_result(passed);
        printf("Node with large content (1000 bytes)\n");
        safe_free(large_str);
        safe_free(node);
    }

    // Test 7: Create node with struct content
    {
        struct test_struct {
            int x;
            char y;
            double z;
        } *test_struct = malloc(sizeof(struct test_struct));
        
        test_struct->x = 42;
        test_struct->y = 'B';
        test_struct->z = 3.14;
        
        t_list *node = ft_lstnew(test_struct);
        struct test_struct *content = (struct test_struct *)node->content;
        
        int passed = (node != NULL && 
                     node->content == test_struct && 
                     content->x == 42 && 
                     content->y == 'B' && 
                     content->z == 3.14 && 
                     node->next == NULL);
        print_result(passed);
        printf("Node with struct content\n");
        safe_free(test_struct);
        safe_free(node);
    }

    // Test 8: Create multiple nodes and check independence
    {
        int *num1 = malloc(sizeof(int));
        int *num2 = malloc(sizeof(int));
        *num1 = 42;
        *num2 = 84;
        
        t_list *node1 = ft_lstnew(num1);
        t_list *node2 = ft_lstnew(num2);
        
        int passed = (node1 != NULL && 
                     node2 != NULL && 
                     node1 != node2 && 
                     node1->content != node2->content && 
                     *(int *)node1->content == 42 && 
                     *(int *)node2->content == 84 && 
                     node1->next == NULL && 
                     node2->next == NULL);
        print_result(passed);
        printf("Multiple independent nodes\n");
        safe_free(num1);
        safe_free(num2);
        safe_free(node1);
        safe_free(node2);
    }

    // Test 9: Memory allocation failure simulation (if possible on your system)
    printf("Note: Memory allocation failure test may not be reliable on all systems\n");
    {
        // This test is implementation-dependent and may not work on all systems
        size_t huge_size = (size_t)-1;  // Maximum size_t value
        void *huge_content = malloc(1);  // Just a dummy content
        t_list *node = ft_lstnew(huge_content);
        int passed = (node == NULL);  // Should fail to allocate
        print_result(passed);
        printf("Memory allocation failure handling\n");
        safe_free(huge_content);
    }
}

int main(void) {
    test_ft_lstnew();
    return 0;
}
