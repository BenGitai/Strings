/* String header file */

#ifndef STR_H
#define STR_H

#include <stddef.h>

/* Return the length of a string pcSrc (char array) as size_t, can't be NULL */
size_t Str_getLength(const char pcSrc[]);

/* Copy string from pcSrc to pcDest, must not be NULL, return the copy */
char *Str_copy(char pcDest[], const char pcSrc[]);

/* Append pcSrc onto the end pcDest, return the new pcDest, both can't be NULL */
char *Str_concat(char pcDest[], const char pcSrc[]);

/* Compare pcSrc1 and pcSrc2, return 0 if equal, positive if pcSrc1 is bigger and negative if pcSrc2 is */
int Str_compare(const char pcSrc1[], const char pcSrc2[]);

/* Return the pointer to the start of the substring pcSrc2 inside pcSrc1 or NULL if none exist */
char *Str_search(const char pcSrc1[], const char pcSrc2[]);

#endif
