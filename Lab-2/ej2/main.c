#include <stdio.h>
#include <stdlib.h>
#include "cima.h"

int main(void) {
    int a[] = {-2, 8, 9, 10, 1};
    int length = 5;
    int result;

    result = cima(a, length);
    printf("%s\n", tiene_cima(a,length) ? "true" : "false");
    printf("Resultado: %i\n", result);

    return EXIT_SUCCESS;
}
