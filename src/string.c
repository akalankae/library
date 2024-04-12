/*******************************************************************************
 * File name: string.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 12 Apr 24
 * Last modified: 12 Apr 24 10.00 PM
 * Description: My custom string functions standard C libray does not provide.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* C standard library has strpbrk(s, accept) function: "string pointer break"
 * This gives a ptr to first char in `s` that is found in `accept`, if not NULL.
 * But does not have a function that does the opposite. ie. a function that gives
 * a ptr to last char in `s` that is found in `accept`. So here it goes!
 */
char*
strrpbrk(const char* s, const char* accept)
{
  char* rpbrk = NULL;
  while (*s != '\0') {
    for (const char* a = accept; *a != '\0'; a++) {
      if (*a == *s) {
        rpbrk = (char*)s;
      }
    }
    s++;
  }

  return rpbrk;
}

/* C standard libray has the strstr(haystack, needle) function: "string substring"
 * This give a ptr to first occurence of substring `needle` in the string `haystack`, if
 * `needle` is not found in the `haystack`, otherwise it returns NULL.
 * But C libray does not give a function that does the opposite. ie. a function
 * that gives the last occurence of the substring `needle`.  So here it goes!
 */
char*
strrstr(const char* haystack, const char* needle)
{
  const char* last_pos = NULL;
  const char* pos = haystack;

  while ((pos = strstr(pos, needle))) {
    last_pos = pos;
    pos += strlen(needle);
  }

  return (void*)last_pos;
}
