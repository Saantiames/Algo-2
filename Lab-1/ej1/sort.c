#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    //insertion sort: 
    //compare one by one until it finds a smaller element, then swap
    array_dump(a,length);
    for(unsigned int j = i; j>0 ; --j){
        if(goes_before(a[j],a[j-1])){
            swap(a,j-1,j);
        }
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
        //Invariant control
        assert(array_is_sorted(a,i));
        printf("A is sorted until A[%d]: \n",i-1);
    }
}
