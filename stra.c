#include "str.h"

size_t Str_getLength(const char pcSrc[]) 
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

char *Str_copy(char pcDest[], const char pcSrc[]) 
{
   size_t i = 0;
   assert(pcSrc != NULL);
   
   while (pcSrc[i] != '\0') {
       pcDest[i] = pcSrc[i];
       i++;
   }
   pcDest[i] = '\0';

   return pcDest;
}

char *Str_concat(char pcDest[], const char pcSrc[])
{
    assert(pcSrc != NULL);
    assert(pcDest != NULL);

    size_t pcDest_length = Str_getLength(pcDest);

    size_t i = 0;

    while (pcSrc[i] != '\0') {
        pcDest[pcDest_length + i] = pcSrc[i];
        i++;
    }

    pcDest[pcDest_length + i] = '\0';

    return pcDest;
}

int Str_compare(const char pcSrc1[], const char pcSrc2[])
{
    size_t i = 0;

    while (pcSrc1[i] != '\0' || pcSrc2[i] != '\0') {
        char char1 = pcSrc1[i];
        char char2 = pcSrc2[i];
        if (char1 != char2) {
            return (char1 - char2);
        }
        i++;
    }
    
    if (pcSrc1[i] == '\0' && pcSrc2[i] == '\0') {
        return 0
    }
    else if (pcSrc1[i] == '\0') {
        return pcSrc2[i];
    }
    else {
        return pcSrc1[i];
    }

}

char *Str_search(const char pcSrc1[], const char pcSrc2[])
{
    size_t length2 = Str_getLength(pcSrc2) + 1;

    size_t i = 0;

    while (pcSrc1[i] != '\0') {
       size_t j = 0; 
        while (pcSrc2[j] != '\0') {
            char char1 = pcSrc1[i + j];
            char char2 = pcSrc2[j];
            if (char1 != char2) {
                break;
            }
            j++;
        }

        if (j == length2) {
            return (char *) &pcSrc1[i];
        }

        i++;
    }

    return NULL;
}
