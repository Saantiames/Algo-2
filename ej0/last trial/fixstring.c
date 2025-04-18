#include <stdbool.h>
#include <assert.h>
#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    //Idea: Find a '/0' char in an array of char
    int i = 1;
    while(s[i-1] != '\0' && i<100){
        
        ++i;
    }
    return i-1;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    
    bool cond = true;
    //the lenght of s1 or s2 can be important
    //but in this case it isnt since 
    //if s1 ends bus s2 doesn't in the pos n
    //then the comparison is ('/0' == x)
    //that is false, so this algorithm doesn't care of order



    // for(int i = 0; i<fstring_length(s1) && cond; ++i){
    int i = 0;
    while(cond && i< 100){
        if(s1[i]!=s2[i]){
            cond = false;
        }
        ++i;
    }
    return cond;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {

    bool result = false;
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            result = true;
        }
        i++;
    }

    return result;
}
    

