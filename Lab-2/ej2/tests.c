#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 10
#define N_TESTCASES_CIMA 10

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
      { {8}         , 1, true },
      { {1,2,3}     , 3 , true},
      { {1,2,3,2}   , 4 , true},
      { {1,2,3,1,3} , 5 , false},
      { {1,5,-1}    , 3, true},
      { {9,3,2,1}   , 4 , true},
      { {6,7,6}     , 3 , true},
      { {10,9,10}   , 3 , false},
      { {1,2,3,8,7} , 5 , true},
      { {1,2}       , 2 , true}

    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}         , 1 , 1 },
        { {1,2,3}     , 3 , 3},
        { {1,2,3,2}   , 4 , 3},
        { {1,2,3,1,3} , 5 , 0},
        { {1,5,-1}    , 3 , 2},
        { {9,3,2,1}   , 4 , 1},
        { {6,7,6}     , 3 , 2},
        { {10,9,10}   , 3 , 0},
        { {1,2,3,8,7} , 5 , 4},
        { {1,2}       , 2 , 2}

    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
