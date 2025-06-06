#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */

    /* PRECONDITION: 
       0 <= izq < der < length of the array

     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
    printf("Izq: %d\nDer: %d\nA[]:%n",izq,der,a);
    int ppiv = izq;
    int i = izq+1;
    int j = der;
    
    while(i<=j){
        if(goes_before(a[i],a[ppiv])){
            ++i;
        }else if(goes_before(a[ppiv],a[j])){
            --j;
        }else{
            swap(a,i,j);
            i++;
            j--;
        }
    }
    swap(a,ppiv,j);
    ppiv = j;
    printf("Izq: %d\nDer: %d\nA[]:%n",izq,der,a);
    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    int ppiv = 0;
    if(izq<der){
        ppiv = partition(a,izq,der);
        quick_sort_rec(a,izq,ppiv-1);
        quick_sort_rec(a,ppiv+1,der);
    }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}