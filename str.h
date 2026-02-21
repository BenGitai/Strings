#ifndef STR_H
#define STR_H

size_t Str_getLength(const char pcSrc[]);
char *Str_copy(char pcDest[], const char pcSrc[]);
char *Str_concat(char pcDest[], const char pcSrc[]);
int Str_compare(const char pcSrc1[], const char pcSrc2[]);
char *Str_search(const char pcSrc1[], const char pcSrc2[]);

#endif
