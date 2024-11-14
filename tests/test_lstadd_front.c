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

void test_ft_lstadd_front() {
    printf("\n=== Testing ft_lstadd_front ===\n\n");

    /* Test 1: Adding to NULL list */
    printf("Test 1: Adding to empty list: ");
    t_list *lst1 = NULL;
    t_list *new1 = create_node(42);
    ft_lstadd_front(&lst1, new1);
    
    if (lst1 && (int)(long)lst1->content == 42 && lst1->next == NULL) {
        PASS;
        printf(" - New node became head\n");
    } else {
        FAIL;
        printf(" - Failed to add to empty list\n");
    }
    print_list(lst1);
    free_list(lst1);

    /* Test 2: Adding to existing list */
    printf("\nTest 2: Adding to existing list: ");
    t_list *lst2 = create_node(2);
    lst2->next = create_node(3);
    t_list *new2 = create_node(1);
    printf("\nBefore: ");
    print_list(lst2);
    
    ft_lstadd_front(&lst2, new2);
    printf("After:  ");
    print_list(lst2);
    
    if (lst2 && (int)(long)lst2->content == 1 && 
        (int)(long)lst2->next->content == 2) {
        PASS;
        printf(" - Node correctly added at front\n");
    } else {
        FAIL;
        printf(" - Failed to add to existing list\n");
    }
    free_list(lst2);

    /* Test 3: Adding NULL node */
    printf("\nTest 3: Adding NULL node: ");
    t_list *lst3 = create_node(1);
    t_list *original = lst3;
    ft_lstadd_front(&lst3, NULL);
    
    if (lst3 == original) {
        PASS;
        printf(" - List unchanged when adding NULL\n");
    } else {
        FAIL;
        printf(" - List wrongly modified when adding NULL\n");
    }
    print_list(lst3);
    free_list(lst3);

    /* Test 4: Multiple additions */
    printf("\nTest 4: Multiple additions: ");
    t_list *lst4 = NULL;
    t_list *new4;
    for (int i = 5; i > 0; i--) {
        new4 = create_node(i);
        ft_lstadd_front(&lst4, new4);
    }
    
    printf("\nResult: ");
    print_list(lst4);
    
    int is_correct = 1;
    t_list *current = lst4;
    for (int i = 1; i <= 5 && current; i++) {
        if ((int)(long)current->content != i)
            is_correct = 0;
        current = current->next;
    }
    
    if (is_correct) {
        PASS;
        printf(" - Multiple nodes added correctly\n");
    } else {
        FAIL;
        printf(" - Failed in multiple additions\n");
    }
    free_list(lst4);
}

int main() {
    test_ft_lstadd_front();
    return 0;
}
