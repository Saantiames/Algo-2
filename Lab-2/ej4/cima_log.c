#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */


int bsearch_rec(int a[], int izq, int der){

    int mid;
    int ret;
    mid = (izq+der)/2;

    if ( izq == der ){
        ret = mid;

    }else if(a[mid] < a[mid+1]){
        ret = bsearch_rec(a,mid+1, der);
    }else {
        ret = bsearch_rec(a,izq, mid);
    }

    return ret;
}
int cima_log(int a[], int length) {

    int cima = bsearch_rec(a, 0, length);

    return cima;
}
