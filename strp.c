/* String module using Pointer notation */

#include "str.h"
#include <assert.h>

/* Return the size of a string pcSrc */
size_t Str_getLength(const char *pcSrc)
{
   const char *pcEnd;
   assert(pcSrc != NULL);
   pcEnd = pcSrc;

   /* loop through till you see the end character */
   while (*pcEnd != '\0')
      pcEnd++;
   return (size_t)(pcEnd - pcSrc);
}

/* Return a string pcDest that is a copy of string pcSrc */
char *Str_copy(char *pcDest, const char *pcSrc)
{
   char *pcStart = pcDest;
   assert(pcSrc != NULL);
   assert(pcDest != NULL);

   /* Loop through till the end of pcSrc, copy each character over */
   while (*pcSrc != '\0') {
      *pcDest = *pcSrc;
      pcDest++;
      pcSrc++;
   }
   *pcDest = '\0';

   return pcStart;
}

/* Compare two strings, return 0 if equal, positive or negative otherwise */
int Str_compare(const char *pcSrc1, const char *pcSrc2)
{
    assert(pcSrc1 != NULL);
    assert(pcSrc2 != NULL);

    /* Continue while both characters are the same and not null */
    while (*pcSrc1 == *pcSrc2) {
        if (*pcSrc1 == '\0') {
            return 0; /* Both hit the end at the same time */
        }
        pcSrc1++;
        pcSrc2++;
    }

    /* Return the difference of the characters where they became different */
    return (int)((unsigned char)*pcSrc1 - (unsigned char)*pcSrc2);
}

/* Append pcSrc to the end of pcDest, return pcDest */
char *Str_concat(char *pcDest, const char *pcSrc)
{
    char *pcStart = pcDest;
    assert(pcDest != NULL);
    assert(pcSrc != NULL);

    /* Walk pcDest to the end (the null terminator) */
    while (*pcDest != '\0') {
        pcDest++;
    }

    /* Copy pcSrc to the current pcDest position */
    while (*pcSrc != '\0') {
        *pcDest = *pcSrc;
        pcDest++;
        pcSrc++;
    }

    /* End the new combined string */
    *pcDest = '\0';

    return pcStart;
}

/* Search to see if pcSrc2 exists as a substring in pcSrc1, return the start if so, Null otherwise */
char *Str_search(const char *pcSrc1, const char *pcSrc2)
{
   const char *pcScan;
   const char *pcSearch;

   assert(pcSrc1 != NULL);
   assert(pcSrc2 != NULL);

   /* Handle Empty pcSrc2: standard strstr returns pcSrc1 */
   if (*pcSrc2 == '\0') {
      return (char *)pcSrc1;
   }

   /* Iterate through pcSrc1 */
   while (*pcSrc1 != '\0') {
      /* Use scan and search pointers to not effect pcSrc1 or pcSrc2 */
      pcScan = pcSrc1;
      pcSearch = pcSrc2;

      /* Scan ahead to see if pcSrc2 matches at this position */
      while (*pcScan != '\0' && *pcSearch != '\0' && *pcScan == *pcSearch) {
         pcScan++;
         pcSearch++;
      }

      /* Success: If we reached the end of pcSrc2 and still matching */
      if (*pcSearch == '\0') {
         return (char *)pcSrc1;
      }

      pcSrc1++;
   }

   return NULL;
}
