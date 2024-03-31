// Header file for personal library

// Get length of array
#define ARRLEN(arr) (sizeof(arr) / sizeof(arr[0]))

// Get random integer in range `start` to `end` inclusive. i.e. (start, end)
#define RANDRANGE(start, end) ((rand() % (end - (start - 1))) + start)

char *const rstrip(char *const s);
