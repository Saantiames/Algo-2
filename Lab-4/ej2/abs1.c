#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    int* p;
    p = y;
    if(x>0){
        *p = x;
    }else{
        *p = -x;
    }
}

int main(void) {
    int a=0, res=0;
    a=-10;
    absolute(a,&res);
    printf("y = %d\n", res);
    return EXIT_SUCCESS;
}

