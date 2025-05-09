#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    int* p;
    p = y;
    if(x>0){
        *p = x;
    }else{
        *p = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    a=-10;
    absolute(a,&res);
    printf("y = %d\n", res);
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

