#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

/* Colors for output */
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

/* Test result macros */
#define PASS printf("%s✅ PASS%s", GREEN, RESET)
#define FAIL printf("%s❌ FAIL%s", RED, RESET)

/* Global variable to track deletion */
int g_del_called = 0;

/* Custom delete functions for testing */
void del_int(void *content) {
    g_del_called++;
    free(content);
}

void del_string(void *content) {
    g_del_called++;
    if (content)
        free(content);
}

/* Helper function to create a node with int content */
t_list *create_int_node(int value) {
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    
    int *content = (int *)malloc(sizeof(int));
    if (!content) {
        free(node);
        return NULL;
    }
    *content = value;
    
    node->content = content;
    node->next = NULL;
    return node;
}

/* Helper function to create a node with string content */
t_list *create_string_node(const char *str) {
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    
    char *content = strdup(str);
    if (!content) {
        free(node);
        return NULL;
    }
    
    node->content = content;
    node->next = NULL;
    return node;
}

void test_ft_lstdelone() {
    printf("\n=== Testing ft_lstdelone ===\n\n");

    /* Test 1: Basic deletion of single node with int content */
    printf("Test 1: Delete single node with int content: ");
    g_del_called = 0;
    t_list *node1 = create_int_node(42);
    t_list *next1 = create_int_node(43);
    node1->next = next1;
    
    ft_lstdelone(node1, del_int);
    
    if (g_del_called == 1) {
        PASS;
        printf(" - Content properly deleted and del function called once\n");
    } else {
        FAIL;
        printf(" - Del function called %d times instead of once\n", g_del_called);
    }
    // Clean up remaining node
    ft_lstdelone(next1, del_int);

    /* Test 2: Deletion of node with string content */
    printf("\nTest 2: Delete node with string content: ");
    g_del_called = 0;
    t_list *node2 = create_string_node("Hello World");
    
    ft_lstdelone(node2, del_string);
    
    if (g_del_called == 1) {
        PASS;
        printf(" - String content properly deleted\n");
    } else {
        FAIL;
        printf(" - Del function not called correctly\n");
    }

    /* Test 3: NULL node */
    printf("\nTest 3: Delete NULL node: ");
    g_del_called = 0;
    
    ft_lstdelone(NULL, del_int);
    
    if (g_del_called == 0) {
        PASS;
        printf(" - Properly handled NULL node\n");
    } else {
        FAIL;
        printf(" - Incorrectly tried to delete NULL node\n");
    }

    /* Test 4: Node with NULL content */
    printf("\nTest 4: Delete node with NULL content: ");
    g_del_called = 0;
    t_list *node4 = (t_list *)malloc(sizeof(t_list));
    node4->content = NULL;
    node4->next = NULL;
    
    ft_lstdelone(node4, del_string);
    
    if (g_del_called == 1) {
        PASS;
        printf(" - Properly handled node with NULL content\n");
    } else {
        FAIL;
        printf(" - Failed to call del function on NULL content\n");
    }

    /* Test 5: NULL delete function */
    printf("\nTest 5: Delete with NULL delete function: ");
    t_list *node5 = create_int_node(42);
    
    ft_lstdelone(node5, NULL);
    PASS;
    printf(" - No crash with NULL delete function\n");

    /* Test 6: Verify next node preservation */
    printf("\nTest 6: Verify next node preservation: ");
    g_del_called = 0;
    t_list *node6 = create_int_node(42);
    t_list *next6 = create_int_node(43);
    node6->next = next6;
    int next_value = *(int *)next6->content;
    
    ft_lstdelone(node6, del_int);
    
    if (g_del_called == 1 && next6->content && *(int *)next6->content == next_value) {
        PASS;
        printf(" - Next node preserved correctly\n");
    } else {
        FAIL;
        printf(" - Next node was modified or deleted\n");
    }
    // Clean up remaining node
    ft_lstdelone(next6, del_int);
}

int main() {
    test_ft_lstdelone();
    printf("\nNote: Use valgrind to verify there are no memory leaks!\n");
	system("leaks lstdelone_output");
    return 0;
}
