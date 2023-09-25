#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail shaker sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;
    
    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        current = *list;

        while (current->next != NULL) {
            if (current->n > current->next->n) {
                swap_nodes(current, current->next, list);
                print_list(*list);
                swapped = 1;
            }
            else
                current = current->next;
        }

        if (swapped == 0)
            break;

        swapped = 0;
        current = current->prev;

        while (current->prev != NULL) {
            if (current->n < current->prev->n) {
                swap_nodes(current->prev, current, list);
                print_list(*list);
                swapped = 1;
            }
            else
                current = current->prev;
        }
    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 * @list: Pointer to the head of the list
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
    listint_t *temp;

    if (node1->prev)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next)
        node2->next->prev = node1;

    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
    temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;
}

