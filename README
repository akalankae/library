# Personal static library of compiled C/C++ code

# Name: libpersonal.a

## Contents

1. heap.c
    - Automatically free dynamic memory when exiting the program.
    - You need to register each chunk of dynamic memory (i.e. ptr received from 
    malloc) to be freed at program termination, by adding it to the global 
    linked list that tracks the dynamic memory the program received.
    - You can use `append_heap_list()` function to do this.
    - Instead you can use custom malloc function that does this automatically
    - However, you MUST register the free'ing function `free_heap_list()` with 
    atexit()
    - If you do this, however the program exits, it would still free the heap
    - Even if you lost the reference to malloc'd memory, it would be in the list
    of malloc'd memory to be cleared, and thus would be freed.

2. util.c
    - rstrip(): removes all whitespace from trailing end of given string.
