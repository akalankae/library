/*******************************************************************************
 * File name: heap.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 31 Mar 24
 * Last modified: 01 Apr 24 12.35 PM
 * Description: Automate the deallocation of dynamic memory reserved by the
 * program.
 ******************************************************************************/
#include "../include/heap.h"
#include <stdio.h>
#include <stdlib.h>

static struct heap *HEAP_LIST = NULL;

void free_heap_list(void)
{
    struct heap *curr, *next;

    for (curr = HEAP_LIST; curr != NULL; curr = next)
    {
        next = curr->next;
        free(curr->addr);
        free(curr);
    }
}

void
append_heap_list(void *p)
{
    struct heap **last_node_p = &HEAP_LIST;
    struct heap *new = malloc(sizeof(struct heap));

    if (new == NULL)
    {
        perror("malloc");
        exit(1);
    }
    new->addr = p;
    new->next = NULL;

    while (*last_node_p != NULL)
        last_node_p = &((*last_node_p)->next);

    *last_node_p = new;
}

void *my_malloc(size_t bytes)
{
    void *p = malloc(bytes);

    if (p != NULL)
        append_heap_list(p);

    return p;
}
