/* String module using Array notation */
#include <stddef.h>
#include <assert.h>
#include "str.h"

/* Get the length of a char array (string), return as size_t */
size_t Str_getLength(const char pcSrc[]) 
{
   size_t uLength = 0;
   assert(pcSrc != NULL);

   /* Loop through till you see the end of the string character */
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

/* Copy pcSrc into pcDest, assume enough space has been allocated */
char *Str_copy(char pcDest[], const char pcSrc[]) 
{
   size_t i = 0;
   assert(pcSrc != NULL);
   assert(pcDest != NULL);

   
   /* Loop through till then end of the pcSrc string, assign each value into pcDest */
   while (pcSrc[i] != '\0') {
       pcDest[i] = pcSrc[i];
       i++;
   }
   pcDest[i] = '\0'; /* End pcDest */

   return pcDest;
}


/* Append pcSrc onto the end of pcDest */
char *Str_concat(char pcDest[], const char pcSrc[]) {
    size_t pcDest_length;
    size_t i = 0;

    assert(pcSrc != NULL); 
    assert(pcDest != NULL);

    pcDest_length = Str_getLength(pcDest); /* The point we will start appending onto */ 

    /* For each character in pcSrc, add it to the end on pcDest until the end */
    while (pcSrc[i] != '\0') {
        pcDest[pcDest_length + i] = pcSrc[i];
        i++;
    }

    pcDest[pcDest_length + i] = '\0'; /* End pcDest */

    return pcDest;
}

/* Compare two strings, pcSrc1 - pcSrc2, if equal return 0 */
int Str_compare(const char pcSrc1[], const char pcSrc2[])
{
    size_t i = 0;

    assert(pcSrc1 != NULL);
    assert(pcSrc2 != NULL);

    /* For each character until the end see if they are equal or not */
    while (pcSrc1[i] != '\0' || pcSrc2[i] != '\0') {
        char char1 = pcSrc1[i];
        char char2 = pcSrc2[i];

        /* If not equal we can end early */
        if (char1 != char2) {
            return (int)(char1 - char2);
        }
        i++;
    }
    
    /* Loop ends once one string ends, if both end this returns 0
     * if only one ends this isn't 0 and returns the normal comparison value */
    return (int)(pcSrc1[i] - pcSrc2[i]);

}

/* Search to see if the substring pcSrc2 exists in string pcSrc1, if so return the pointer to the start
 * Otherwise, return NULL */
char *Str_search(const char pcSrc1[], const char pcSrc2[])
{
    size_t length2;
    size_t i = 0;

    assert(pcSrc1 != NULL);
    assert(pcSrc2 != NULL);

    length2 = Str_getLength(pcSrc2);

    /* Edge case: If pcSrc2 is empty, return pcSrc1 (nothing is the start of anything else) */
    if (length2 == 0) {
        return (char *)pcSrc1;
    }

    /* Loop thru pcSrc1 to see if there is any viable start points for pcSrc2 */
    while (pcSrc1[i] != '\0') {
        size_t j = 0; 
        
        /* Check if pcSrc2 matches the substring starting at pcSrc1 index i */
        while (pcSrc2[j] != '\0') {
            if (pcSrc1[i + j] != pcSrc2[j]) {
                break;
            }
            j++;
        }

        /* If j reached length2, we found a complete match */
        if (j == length2) {
            return (char *)&pcSrc1[i];
        }

        i++;
    }

    return NULL;
}
