/*
* File Name: 0-print_listint.c
* Author: @Kwenziwa
* Description: Function that prints all the elements of a listint_t list.
*/

#include "lists.h"
#include <stdio.h>

size_t print_listint(const listint_t *h)
{
    size_t nodes_num = 0;

    while (h)
    {
        nodes_n++;
        printf("%d\n", h->n);
        h = h->next;
    }

    return (nodes_num);
}


