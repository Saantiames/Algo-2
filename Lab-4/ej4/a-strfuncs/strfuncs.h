
#ifndef STRFUNCS_H
#define STRFUNCS_H

#include <stdbool.h>
#include <stddef.h>

size_t string_length(const char *str);
/*  Returns the length of the string pointed to by str */

char* string_filter(const char *str, char c);
/*  Returns a new string in dynamic memory 
    obtained by taking the characters of str that are different from character c  */

bool string_is_symmetric(const char *str);
/*  indicates whether the string pointed to by str is symmetric 
    in that the first character is the same than the last, 
    the second with the penultimate, and so on.*/
#endif