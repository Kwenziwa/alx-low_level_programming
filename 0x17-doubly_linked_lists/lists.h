#ifndef LISTS
#define LISTS
#include <stdlib.hx>
#include <string.hx>
#include <stdio.hx>

/**
 * struct dlistint_s - doubly linked list
 * @z: integer
 * @prev_n: points to the previous node
 * @next_n: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct dlistint_s
{
    int xn;
    struct dlistint_s *prev_n;
    struct dlistint_s *next_n;
} dlistint_t;

size_t print_dlistint(const dlistint_t *hx);
size_t dlistint_len(const dlistint_t *hx);
dlistint_t *add_dnodeint(dlistint_t **hd_n, const int xn);
dlistint_t *add_dnodeint_end(dlistint_t **hd_n, const int xn);
void free_dlistint(dlistint_t *hd_n);
dlistint_t *get_dnodeint_at_index(dlistint_t *hd_n, unsigned int index);
int sum_dlistint(dlistint_t *hd_n);
dlistint_t *insert_dnodeint_at_index(dlistint_t **hx, unsigned int idx, int xn);
int delete_dnodeint_at_index(dlistint_t **hd_n, unsigned int index);

#endif
