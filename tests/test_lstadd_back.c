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

/* Helper function to verify list integrity */
int verify_list_content(t_list *lst, int *expected, int size) {
    for (int i = 0; i < size; i++) {
        if (!lst || (int)(long)lst->content != expected[i])
            return 0;
        lst = lst->next;
    }
    return lst == NULL; // Should be at the end of the list
}

void test_ft_lstadd_back() {
    printf("\n=== Testing ft_lstadd_back ===\n\n");

    /* Test 1: Adding to NULL list */
    printf("Test 1: Adding to empty list: ");
    t_list *lst1 = NULL;
    t_list *new1 = create_node(42);
    
    ft_lstadd_back(&lst1, new1);
    printf("Result: ");
    print_list(lst1);
    
    if (lst1 == new1 && (int)(long)lst1->content == 42 && lst1->next == NULL) {
        PASS;
        printf(" - Node correctly added to empty list\n");
    } else {
        FAIL;
        printf(" - Failed to add node to empty list\n");
    }
    free_list(lst1);

    /* Test 2: Adding to existing list */
    printf("\nTest 2: Adding to existing list: ");
    t_list *lst2 = create_node(1);
    lst2->next = create_node(2);
    t_list *new2 = create_node(3);
    
    printf("Before: ");
    print_list(lst2);
    ft_lstadd_back(&lst2, new2);
    printf("After:  ");
    print_list(lst2);
    
    int expected2[] = {1, 2, 3};
    if (verify_list_content(lst2, expected2, 3)) {
        PASS;
        printf(" - Node correctly added at the end\n");
    } else {
        FAIL;
        printf(" - Failed to add node at the end\n");
    }
    free_list(lst2);

    /* Test 3: Adding NULL node */
    printf("\nTest 3: Adding NULL node: ");
    t_list *lst3 = create_node(1);
    t_list *original = lst3;
    
    printf("Before: ");
    print_list(lst3);
    ft_lstadd_back(&lst3, NULL);
    printf("After:  ");
    print_list(lst3);
    
    if (lst3 == original && lst3->next == NULL) {
        PASS;
        printf(" - List unchanged when adding NULL node\n");
    } else {
        FAIL;
        printf(" - List wrongly modified when adding NULL node\n");
    }
    free_list(lst3);

    /* Test 4: Multiple additions */
    printf("\nTest 4: Multiple consecutive additions: ");
    t_list *lst4 = NULL;
    
    printf("\nAdding nodes 1 through 5:\n");
    for (int i = 1; i <= 5; i++) {
        t_list *new_node = create_node(i);
        ft_lstadd_back(&lst4, new_node);
        printf("After adding %d: ", i);
        print_list(lst4);
    }
    
    int expected4[] = {1, 2, 3, 4, 5};
    if (verify_list_content(lst4, expected4, 5)) {
        PASS;
        printf(" - All nodes added correctly in sequence\n");
    } else {
        FAIL;
        printf(" - Failed in sequential additions\n");
    }
    free_list(lst4);

    /* Test 5: Adding to list with one node */
    printf("\nTest 5: Adding to single-node list: ");
    t_list *lst5 = create_node(1);
    t_list *new5 = create_node(2);
    
    printf("Before: ");
    print_list(lst5);
    ft_lstadd_back(&lst5, new5);
    printf("After:  ");
    print_list(lst5);
    
    int expected5[] = {1, 2};
    if (verify_list_content(lst5, expected5, 2)) {
        PASS;
        printf(" - Node correctly added to single-node list\n");
    } else {
        FAIL;
        printf(" - Failed to add to single-node list\n");
    }
    free_list(lst5);

    /* Test 6: Adding node with existing next pointer */
    printf("\nTest 6: Adding node with existing next pointer: ");
    t_list *lst6 = create_node(1);
    t_list *new6 = create_node(2);
    new6->next = create_node(99); // This should be ignored
    
    printf("Before: ");
    print_list(lst6);
    ft_lstadd_back(&lst6, new6);
    printf("After:  ");
    print_list(lst6);
    
    int expected6[] = {1, 2, 99};
    if (verify_list_content(lst6, expected6, 3)) {
        PASS;
        printf(" - Node added with its existing next pointer preserved\n");
    } else {
        FAIL;
        printf(" - Failed to handle node with existing next pointer\n");
    }
    free_list(lst6);
}

int main() {
    test_ft_lstadd_back();
    return 0;
}
