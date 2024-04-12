#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H

// strrpbrk() function locates the last occurence in the string `s` of any of
// the bytes in the string `accept`.  This does the opposite of strpbrk() C
// standard library function.
// RETURN VALUE: pointer to the byte in `s` that matches one of the bytes in
// `accept`, or NULL if no such byte is found.
char*
strrpbrk(const char* s, const char* accept);

// Find last occurence of substring `needle` in string `haystack`
// If `needle` is not found in `haystack` return NULL.
// strrstr() function finds the last occurence of the substring `needle` in the
// string `haystack`.  The terminating '\0' bytes are not compared.  This does
// the opposite of strstr() C standard library function.
// RETURN VALUE: pointer to the beginning of the located substring, or NULL if
// substring was not found.
char*
strrstr(const char* haystack, const char* needle);

#endif // INCLUDE_STRING_H
