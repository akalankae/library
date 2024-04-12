/* heap.h
 * Declarations for heap memory deallocation utilities
 */
#include <stddef.h>

struct heap
{
  void        *addr; // ptr to chunk of allocated heap memory
  struct heap *next; // ptr to next node in the list
};

void
free_heap_list(void);

void
append_heap_list(void *p);

void *
my_malloc(size_t b);
