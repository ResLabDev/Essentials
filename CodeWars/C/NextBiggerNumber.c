/*
You have to create a function that takes a positive integer number and returns the next bigger number formed by the same digits:

12 ==> 21
513 ==> 531
2017 ==> 2071
If no bigger number can be composed using those digits, return -1:

9 ==> -1
111 ==> -1
531 ==> -1
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    unsigned long long value;
    struct node *next;
} node_t;

void insert_last(node_t *root, unsigned long long value);
void insert_sort_desc(node_t **root, unsigned long long value);
unsigned long long merge_decimal(node_t *root);
void print_list(node_t *root);
unsigned long long search_closest(node_t *root, unsigned long long value, bool *found);

unsigned long long next_bigger_number(unsigned long long n)
{
    if (!n)
        return -1;
    node_t *root = malloc (sizeof (node_t));
    if (root == NULL)
        return 0;
    root->next = NULL;

    unsigned long long digit_current, digit_next, digit_closest;
    bool is_found = false;
    bool is_init = true;
    bool closest_found = false;

    digit_current = n % 10;
    n /= 10;
    if (!n)
        return -1;
    digit_next = n % 10;
    root->value = digit_current;
    while (n)
    {
        if (!is_found)
        {
            if (digit_current > digit_next)    // Bigger found, swap digits
            {
                is_found = true;
                if (is_init)
                {
                    root->value = digit_next;
                    insert_last(root, digit_current);
                }
                else
                {
                    digit_closest = search_closest(root, digit_next, &closest_found);
                    if (!closest_found)
                    {
                        insert_sort_desc(&root, digit_next);
                        insert_last(root, digit_current);
                    }
                    else
                    {
                        insert_sort_desc(&root, digit_current);
                        insert_last(root, digit_closest);
                    }
                }
                n /= 10;
            }
            else
            {
                if (!is_init)
                    insert_sort_desc(&root, digit_current);
            }
        }
        digit_current = n % 10;
        n /= 10;
        digit_next = n % 10;
        is_init = false;
        if (is_found)
        {
            insert_last(root, digit_current);
        }
    }

    return (is_found) ? merge_decimal(root) : -1;
}

void insert_last(node_t *root, unsigned long long value)
{
    node_t *current = root;
    // Iterating over the list
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = malloc(sizeof(node_t));
    current->next->next = NULL;
    current->next->value = value;
}

void insert_sort_desc(node_t **root, unsigned long long value)
{
    node_t *current = *root;
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;

    if (current->value < value)     // If value is smaller than root, insert at the beginning
    {
        new_node->next = *root;
        *root = new_node;

        return;
    }

    while ((current->next != NULL)) // Value is greater than current OR end of the list
    {
        if (current->next->value < value)
            break;
        current = current->next;
    }
    if (current->next == NULL)      // Insert at the end
    {
        current->next = new_node;
        new_node->next = NULL;
    }
    else                            // Insert at designated location
    {
        new_node->next = current->next;
        current->next = new_node;
    }
}

unsigned long long search_closest(node_t *root, unsigned long long value, bool *found)
{
    unsigned long long ret;
    node_t *current = root;

    *found = false;
    while (current->next != NULL)
    {
        if ((current->value > value) && (current->next->value <= value))
        {
            *found = true;
            ret = current->value;
            current->value = value;
            break;
        }
        current = current->next;
    }
    return ret;
}

unsigned long long merge_decimal(node_t *root)
{
    unsigned long long res = 0, i = 1;
    node_t *current = root;
    while (current != NULL)
    {
        res += i * current->value;
        i *= 10;
        current = current->next;
    }

    return res;
}

//=====================================================

// Iterate over the list
void print_list(node_t *root)
{
    node_t *current = root;

    while (current != NULL)
    {
        printf("%llu, ", current->value);
        current = current->next;
    }
}

int main (void)
{
    printf("%llu\n", next_bigger_number(59853));
    // 8, 5, 5, 3, 9, 4, 8, 4, 8, 4, 8, 8, 9, 5,
    // 598848484_59853 -> orig
    // 598848484_93558 -> res
    // 598848484_83559 -> expected

    return 0;
}
