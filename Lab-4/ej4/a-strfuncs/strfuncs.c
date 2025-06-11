#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t string_length(const char *str){
    size_t i = 0;
    while (*str !='\0'){
        i++;
        str = &str[1];
    }
    return i;
}

char* string_filter(const char *str, char c){

    int length = string_length(str);

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

bool string_is_symmetric(const char *str)
{

    char *original = string_filter(str, ' ');
    int length = string_length(original);      
    char *reversed = malloc((length + 1) * sizeof(char));

    original = string_filter(str, ' ');

    //Do the reversed word (without spaces)
    for (int i = 0; i < length; ++i) {
        reversed[i] = original[length - 1 - i];
    }
    reversed[length] = '\0';
    //End reversed word
    //
    //Check if the reversed is equal to the original
    bool result = true;
    
    for(int i = 0; i<length && result; ++i){
        if(original[i] != reversed[i]){
            result = false;
        }
    }
    //end check
    //
    //free memory
    free(original);
    free(reversed);

    return result;
}