#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};

list empty(){
    list l = malloc(sizeof(list));
    l->size = 0;
    return l;
}

list addl(elem e, list l) {
    
    assert(l->size < MAX_LENGTH);
    for(int i = l->size; i>0;--i){
        l->elems[i] = l->elems[i-1]; 
    }
    l->elems[0] = e;
    l->size +=1;
    return l;
}

/* Operations */
bool is_empty (list l){
    return l->size==0;
}

elem head (list l){
    assert(!is_empty(l));
    return l->elems[0];
}

list tail (list l){
    for(int i = 1; i<=l->size;++i){
        l->elems[i-1] = l->elems[i];
    }
    l->size--;
    return l;
}

list addr (list l, elem e){
    assert(!is_empty(l));
    l->elems[l->size+1] = e;
    l->size++;
    return l;
}

unsigned int leength (list l){
    return l->size;
}

list concat (list l, list l0){
    assert(l->size+l0->size < MAX_LENGTH);

    for(int i = 0; i < l0->size; ++i){
        l->elems[i+l0->size] = l0->elems[i];
    }
    l->size += l0->size-1;
    return l;
}

elem index (list l, unsigned int n){
    assert(n<length(l));
    elem ret = l->elems[n-1];

    return ret;
}

list take (list l, unsigned int n){
    l->size = n;
    return l;
}

list drop (list l, unsigned int n){
    
}

list copy_list (list l1){

}

/* Destroy */
void destroy (list l){

}