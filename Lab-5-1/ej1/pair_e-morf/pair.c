#include "pair.h"
#include <stdlib.h>

struct s_pair_t
{
    elem fst;
    elem snd;
};


pair_t pair_new(elem x, elem y){
    pair_t p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

int pair_first(pair_t p){
    return p->fst;
}
int pair_second(pair_t p){
    return p->snd;
}
pair_t pair_swapped(pair_t p){
    pair_t ret = malloc(sizeof(struct s_pair_t));
    ret->fst = p->snd;
    ret->snd = p->fst;

    return ret;
}

void pair_destroy(pair_t p){
    free(p);
}