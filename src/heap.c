/*******************************************************************************
 * File name: heap.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 31 Mar 24
 * Last modified: 31 Mar 24 03.25 AM
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

static void append_heap_list(void *p)
{
    struct heap *curr = HEAP_LIST;
    struct heap *new = malloc(sizeof(struct heap)); // ? could be NULL

    if (new == NULL)
    {
        perror("malloc");
        exit(1);
    }
    new->addr = p;
    new->next = NULL;

    if (curr == NULL)
        HEAP_LIST = new;
    else
    {
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = new;
    }
}

void *my_malloc(size_t bytes)
{
    void *p = malloc(bytes);

    if (p != NULL)
        append_heap_list(p);

    return p;
}
