#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

// Test function to convert string to uppercase
void to_upper(void *content)
{
    char *str = (char *)content;
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        str++;
    }
}

// Test function to multiply integers by 2
void multiply_by_two(void *content)
{
    *(int *)content *= 2;
}

// Helper function to create a string node
t_list *create_string_node(char *str)
{
    char *content = strdup(str);
    return ft_lstnew(content);
}

// Helper function to create an integer node
t_list *create_int_node(int value)
{
    int *content = malloc(sizeof(int));
    *content = value;
    return ft_lstnew(content);
}

// Helper function to print list of strings
void print_string_list(t_list *lst)
{
    while (lst)
    {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

// Helper function to print list of integers
void print_int_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

void test_lstiter(void)
{
    printf("\n=== Testing ft_lstiter ===\n\n");
    
    // Test 1: Empty list
    printf("Test 1: Empty list\n");
    ft_lstiter(NULL, to_upper);
    printf("✅ Passed: No segmentation fault with NULL list\n");

    // Test 2: List with strings (to uppercase)
    printf("\nTest 2: Converting strings to uppercase\n");
    t_list *str_list = create_string_node("hello");
    ft_lstadd_back(&str_list, create_string_node("world"));
    ft_lstadd_back(&str_list, create_string_node("42"));
    
    printf("Before: ");
    print_string_list(str_list);
    
    ft_lstiter(str_list, to_upper);
    
    printf("After:  ");
    print_string_list(str_list);
    
    int pass = 1;
    if (strcmp(str_list->content, "HELLO") != 0) pass = 0;
    if (strcmp(str_list->next->content, "WORLD") != 0) pass = 0;
    if (strcmp(str_list->next->next->content, "42") != 0) pass = 0;
    
    printf("%s String conversion test\n", pass ? "✅ Passed:" : "❌ Failed:");

    // Test 3: List with integers (multiply by 2)
    printf("\nTest 3: Multiplying integers by 2\n");
    t_list *int_list = create_int_node(1);
    ft_lstadd_back(&int_list, create_int_node(2));
    ft_lstadd_back(&int_list, create_int_node(3));
    
    printf("Before: ");
    print_int_list(int_list);
    
    ft_lstiter(int_list, multiply_by_two);
    
    printf("After:  ");
    print_int_list(int_list);
    
    pass = 1;
    if (*(int *)int_list->content != 2) pass = 0;
    if (*(int *)int_list->next->content != 4) pass = 0;
    if (*(int *)int_list->next->next->content != 6) pass = 0;
    
    printf("%s Integer multiplication test\n", pass ? "✅ Passed:" : "❌ Failed:");

    // Cleanup
    while (str_list)
    {
        t_list *temp = str_list->next;
        free(str_list->content);
        free(str_list);
        str_list = temp;
    }
    
    while (int_list)
    {
        t_list *temp = int_list->next;
        free(int_list->content);
        free(int_list);
        int_list = temp;
    }
}

int main(void)
{
    test_lstiter();
    return (0);
}
