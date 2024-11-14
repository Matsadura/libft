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

void test_ft_lstlast() {
    printf("\n=== Testing ft_lstlast ===\n\n");

    /* Test 1: NULL list */
    printf("Test 1: NULL list: ");
    t_list *lst1 = NULL;
    t_list *last1 = ft_lstlast(lst1);
    
    if (last1 == NULL) {
        PASS;
        printf(" - Correctly returned NULL for empty list\n");
    } else {
        FAIL;
        printf(" - Expected NULL, got non-NULL value\n");
    }

    /* Test 2: Single node list */
    printf("\nTest 2: Single node list: ");
    t_list *lst2 = create_node(42);
    printf("List: ");
    print_list(lst2);
    
    t_list *last2 = ft_lstlast(lst2);
    if (last2 == lst2 && (int)(long)last2->content == 42) {
        PASS;
        printf(" - Correctly returned single node\n");
        printf("Last node content: %d\n", (int)(long)last2->content);
    } else {
        FAIL;
        printf(" - Failed to return correct last node\n");
    }
    free_list(lst2);

    /* Test 3: Multiple nodes */
    printf("\nTest 3: Multiple nodes list: ");
    t_list *lst3 = create_node(1);
    lst3->next = create_node(2);
    lst3->next->next = create_node(3);
    lst3->next->next->next = create_node(4);
    printf("List: ");
    print_list(lst3);
    
    t_list *last3 = ft_lstlast(lst3);
    if (last3 && (int)(long)last3->content == 4 && last3->next == NULL) {
        PASS;
        printf(" - Correctly returned last node\n");
        printf("Last node content: %d\n", (int)(long)last3->content);
    } else {
        FAIL;
        printf(" - Failed to return correct last node\n");
    }
    free_list(lst3);

    /* Test 4: Long list */
    printf("\nTest 4: Long list (100 nodes): ");
    t_list *lst4 = create_node(0);
    t_list *current = lst4;
    
    for (int i = 1; i < 100; i++) {
        current->next = create_node(i);
        current = current->next;
    }
    
    printf("List (first few nodes): ");
    current = lst4;
    printf("[");
    for (int i = 0; i < 5 && current; i++) {
        printf("%d", (int)(long)current->content);
        if (current->next && i < 4)
            printf(" -> ");
        current = current->next;
    }
    printf(" -> ... -> 99]\n");
    
    t_list *last4 = ft_lstlast(lst4);
    if (last4 && (int)(long)last4->content == 99 && last4->next == NULL) {
        PASS;
        printf(" - Correctly returned last node\n");
        printf("Last node content: %d\n", (int)(long)last4->content);
    } else {
        FAIL;
        printf(" - Failed to return correct last node\n");
    }
    free_list(lst4);

    /* Test 5: Modified list */
    printf("\nTest 5: Modified list: ");
    t_list *lst5 = create_node(1);
    lst5->next = create_node(2);
    printf("Original list: ");
    print_list(lst5);
    
    t_list *last5_before = ft_lstlast(lst5);
    lst5->next->next = create_node(3);  // Add new node after getting last
    printf("Modified list: ");
    print_list(lst5);
    
    t_list *last5_after = ft_lstlast(lst5);
    
    if (last5_before != last5_after) {
        PASS;
        printf(" - Correctly returns different last nodes before/after modification\n");
        printf("Last node before modification: %d\n", (int)(long)last5_before->content);
        printf("Last node after modification: %d\n", (int)(long)last5_after->content);
    } else {
        FAIL;
        printf(" - Failed to update last node after list modification\n");
    }
    free_list(lst5);
}

int main() {
    test_ft_lstlast();
    return 0;
}
