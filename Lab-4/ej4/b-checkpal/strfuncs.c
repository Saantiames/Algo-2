#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t string_length(const char *str){
    size_t i = 0;
    while (*str !='\0'){
        i++;
        str++;
    }
    return i;
}

char* string_filter(const char *str, char c){

    size_t length = string_length(str);

    char* ret = (char*)malloc(length+1 * sizeof(char));
    char* write = ret;

    while (*str != '\0') {
        if (*str != c) {
            *write = *str;
            write++;
        }
        str++;
    }
    *write = '\0';
    return ret;
}

bool string_is_symmetric(const char *str){

    // char *original = str;
    size_t length = string_length(str);      
    char *reversed = malloc((length + 1) * sizeof(char));

    //Do the reversed word 
    for (size_t i = 0; i < length; ++i) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';
    //End reversed word
    //
    //Check if the reversed is equal to the original
    //if the current character is a space
    //just skip it
    bool result = true;
    size_t i = 0, j = 0;

    while (i < length && j < length && result) {
        while (i < length && str[i] == ' ') i++;
        while (j < length && reversed[j] == ' ') j++;

        if (i < length && j < length) {
            if (str[i] != reversed[j]) {
                result = false;
            }
            i++;
            j++;
        }
    }
    //end check
    //
    //free memory
    // free(original);
    free(reversed);

    return result;
}