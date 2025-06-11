#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(struct _counter));
    c->count = 0;
    return c;
}

void counter_inc(counter c) {
    c->count++;
}

bool counter_is_init(counter c) {
    counter in = counter_init();
    bool ret = false;
    if (c->count == in->count){
        ret = true;
    }
    return ret;
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count--;

}

counter counter_copy(counter c) {
    counter ret= malloc(sizeof(struct _counter));

    ret->count= c->count;
    return ret;
}

void counter_destroy(counter c) {
    free(c);
}
