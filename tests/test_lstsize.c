#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

/* Colors for output */
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

/* Test result macros */
#define PASS printf("%s✅ PASS%s", GREEN, RESET)
#define FAIL printf("%s❌ FAIL%s", RED, RESET)

/* Helper function to create a new node */
t_list *create_node(int content) {
    t_list *node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = (void *)(long)content;
    node->next = NULL;
    return node;
}

/* Helper function to print list */
void print_list(t_list *head) {
    printf("[");
    while (head) {
        printf("%d", (int)(long)head->content);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("]\n");
}

/* Helper function to free list */
void free_list(t_list *head) {
    t_list *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void test_ft_lstsize() {
    printf("\n=== Testing ft_lstsize ===\n\n");

    /* Test 1: Empty list (NULL) */
    printf("Test 1: Empty list: ");
    t_list *lst1 = NULL;
    int size1 = ft_lstsize(lst1);
    
    if (size1 == 0) {
        PASS;
        printf(" - Correctly returned 0 for empty list\n");
    } else {
        FAIL;
        printf(" - Expected 0, got %d\n", size1);
    }

    /* Test 2: Single node */
    printf("\nTest 2: Single node list: ");
    t_list *lst2 = create_node(42);
    printf("List: ");
    print_list(lst2);
    
    int size2 = ft_lstsize(lst2);
    if (size2 == 1) {
        PASS;
        printf(" - Correctly returned 1 for single node\n");
    } else {
        FAIL;
        printf(" - Expected 1, got %d\n", size2);
    }
    free_list(lst2);

    /* Test 3: Multiple nodes (5 nodes) */
    printf("\nTest 3: Five node list: ");
    t_list *lst3 = create_node(1);
    lst3->next = create_node(2);
    lst3->next->next = create_node(3);
    lst3->next->next->next = create_node(4);
    lst3->next->next->next->next = create_node(5);
    printf("List: ");
    print_list(lst3);
    
    int size3 = ft_lstsize(lst3);
    if (size3 == 5) {
        PASS;
        printf(" - Correctly returned 5 for five nodes\n");
    } else {
        FAIL;
        printf(" - Expected 5, got %d\n", size3);
    }
    free_list(lst3);

    /* Test 4: Large list (1000 nodes) */
    printf("\nTest 4: Large list (1000 nodes): ");
    t_list *lst4 = NULL;
    t_list *current = NULL;
    int expected_size = 1000;
    
    // Create first node
    lst4 = create_node(0);
    current = lst4;
    
    // Create remaining nodes
    for (int i = 1; i < expected_size; i++) {
        current->next = create_node(i);
        current = current->next;
    }
    
    int size4 = ft_lstsize(lst4);
    if (size4 == expected_size) {
        PASS;
        printf(" - Correctly counted %d nodes\n", expected_size);
    } else {
        FAIL;
        printf(" - Expected %d, got %d\n", expected_size, size4);
    }
    printf("First few nodes: ");
    current = lst4;
    printf("[");
    for (int i = 0; i < 5 && current; i++) {
        printf("%d", (int)(long)current->content);
        if (current->next && i < 4)
            printf(" -> ");
        current = current->next;
    }
    printf(" -> ...]\n");
    free_list(lst4);

    /* Test 5: Circular list detection (not required but good practice) */
    printf("\nTest 5: Circular list (optional test): ");
    t_list *lst5 = create_node(1);
    lst5->next = create_node(2);
    lst5->next->next = create_node(3);
    lst5->next->next->next = lst5; // Creating a circle
    
    int size5 = ft_lstsize(lst5);
    if (size5 == 3) {
        PASS;
        printf(" - Correctly counted nodes even with circular reference\n");
    } else {
        printf(" - Note: This test is optional, your implementation might vary\n");
    }
    
    // Special cleanup for circular list
    lst5->next->next->next = NULL;
    free_list(lst5);
}

int main() {
    test_ft_lstsize();
    return 0;
}
