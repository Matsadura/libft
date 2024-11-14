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

/* Global variable to track deletion count */
int g_del_count = 0;

/* Custom delete functions for testing */
void del_int(void *content) {
    g_del_count++;
    free(content);
}

void del_string(void *content) {
    g_del_count++;
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

/* Helper function to print int list */
void print_int_list(t_list *lst) {
    printf("[");
    while (lst) {
        printf("%d", lst->content ? *(int *)lst->content : 0);
        if (lst->next)
            printf(" -> ");
        lst = lst->next;
    }
    printf("]\n");
}

void test_ft_lstclear() {
    printf("\n=== Testing ft_lstclear ===\n\n");

    /* Test 1: Clear empty list */
    printf("Test 1: Clear NULL list: ");
    t_list *lst1 = NULL;
    g_del_count = 0;
    
    ft_lstclear(&lst1, del_int);
    
    if (lst1 == NULL && g_del_count == 0) {
        PASS;
        printf(" - Properly handled NULL list\n");
    } else {
        FAIL;
        printf(" - Failed to handle NULL list correctly\n");
    }

    /* Test 2: Clear single node list */
    printf("\nTest 2: Clear single node list: ");
    t_list *lst2 = create_int_node(42);
    g_del_count = 0;
    printf("Before: ");
    print_int_list(lst2);
    
    ft_lstclear(&lst2, del_int);
    
    if (lst2 == NULL && g_del_count == 1) {
        PASS;
        printf(" - Single node properly cleared\n");
    } else {
        FAIL;
        printf(" - Failed to clear single node correctly\n");
    }

    /* Test 3: Clear multiple node list */
    printf("\nTest 3: Clear multiple node list: ");
    t_list *lst3 = create_int_node(1);
    lst3->next = create_int_node(2);
    lst3->next->next = create_int_node(3);
    g_del_count = 0;
    printf("Before: ");
    print_int_list(lst3);
    
    ft_lstclear(&lst3, del_int);
    
    if (lst3 == NULL && g_del_count == 3) {
        PASS;
        printf(" - All three nodes properly cleared\n");
    } else {
        FAIL;
        printf(" - Failed to clear all nodes (del_count: %d)\n", g_del_count);
    }

    /* Test 4: Clear list with string content */
    printf("\nTest 4: Clear list with string content: ");
    t_list *lst4 = create_string_node("Hello");
    lst4->next = create_string_node("World");
    g_del_count = 0;
    
    ft_lstclear(&lst4, del_string);
    
    if (lst4 == NULL && g_del_count == 2) {
        PASS;
        printf(" - String content properly cleared\n");
    } else {
        FAIL;
        printf(" - Failed to clear string content correctly\n");
    }

    /* Test 5: Clear with NULL delete function */
    printf("\nTest 5: Clear with NULL delete function: ");
    t_list *lst5 = create_int_node(1);
    lst5->next = create_int_node(2);
    
    ft_lstclear(&lst5, NULL);
    
    if (lst5 == NULL) {
        PASS;
        printf(" - Handled NULL delete function\n");
    } else {
        FAIL;
        printf(" - Failed to handle NULL delete function\n");
    }

    /* Test 6: Clear list with NULL content */
    printf("\nTest 6: Clear list with NULL content: ");
    t_list *lst6 = (t_list *)malloc(sizeof(t_list));
    lst6->content = NULL;
    lst6->next = (t_list *)malloc(sizeof(t_list));
    lst6->next->content = NULL;
    lst6->next->next = NULL;
    g_del_count = 0;
    
    ft_lstclear(&lst6, del_string);
    
    if (lst6 == NULL && g_del_count == 2) {
        PASS;
        printf(" - Properly handled nodes with NULL content\n");
    } else {
        FAIL;
        printf(" - Failed to handle NULL content correctly\n");
    }

    /* Test 7: Large list clearing */
    printf("\nTest 7: Clear large list (1000 nodes): ");
    t_list *lst7 = NULL;
    t_list **current = &lst7;
    for (int i = 0; i < 1000; i++) {
        *current = create_int_node(i);
        current = &((*current)->next);
    }
    g_del_count = 0;
    
    ft_lstclear(&lst7, del_int);
    
    if (lst7 == NULL && g_del_count == 1000) {
        PASS;
        printf(" - Successfully cleared 1000 nodes\n");
    } else {
        FAIL;
        printf(" - Failed to clear large list (del_count: %d)\n", g_del_count);
    }
}

int main() {
    test_ft_lstclear();
    printf("\nImportant: Run with valgrind to check for memory leaks!\n");
    printf("Command: valgrind --leak-check=full ./your_program\n");
    return 0;
}
