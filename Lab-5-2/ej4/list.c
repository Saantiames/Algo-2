#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

typedef struct _Node Node;

list empty(){
    list p;
    p = NULL;
    return p;
}

list addl(list_elem e, list l) {
    Node *p;
    p = malloc(sizeof(Node)); 
    p->elem = e;
    p->next = l;
    return p;
}

/* Operations */
bool is_empty (list l){
    bool b;
    b = (l==NULL);
    return b;
}

list_elem head (list l){
    list_elem e;
    e = l->elem;
    return e;
}

list tail (list l){
    list new_list;
    new_list = l->next;
    free(l);
    return new_list;
}

list addr (list l, list_elem e){
    Node *p, *q;

    q = malloc(sizeof(Node));
    q->elem = e;
    q->next = NULL;
    if (is_empty(l)){
        l = q;
    }
    else{
        p = l;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = q;
    }
    return l;
}

unsigned int length (list l){
    unsigned int i = 0;
    Node *p;
    p = l;
    while (p!=NULL){
        i++;
        p = p->next;
    }
    return i;
}

list concat (list l, list l0){
    Node *p;
    p = l;
    while(p!=NULL){
        p=p->next;
    }
    p = l0;
    return l;
}

list_elem index (list l, unsigned int n){
    list_elem e;
    Node *p;
    p = l;
    for (unsigned int i=0u; n>i; i++){
        p=p->next;
    }
    e = p->elem;
    return e;
}

list take (list l, unsigned int n){
    Node *p, *q;
    p = l;
    for (unsigned int i = 0u; n>i; i++){
        p=p->next;
    }
    while(p!=NULL){
        q = p;
        p = p->next;
        free(q);
    }
    return l;
}

list drop (list l, unsigned int n){
    Node *p;
    for (unsigned int i=0; n>i; i++){
        p=l;
        l=l->next;
        free(p);
    }
    return l;
}

list copy_list (list l1){
    list l;
    Node *p;
    l = empty();
    p = l1;
    while (p!=NULL){
        l = addr(l, p->elem);
        p = p->next;
    }
    return l;
}

/* Destroy */
void destroy (list l){
    Node *p, *q;
    p=l;
    while(p!=NULL){
        q=p;
        p=p->next;
        free(q);
    }
}