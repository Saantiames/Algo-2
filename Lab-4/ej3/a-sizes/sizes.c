#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);  

    data_t* pmessi = (data_t *)malloc(sizeof(data_t));
    pmessi->age = 36;
    strcpy(pmessi->name,"Leo Messi");
    pmessi->height = 169;
    
    //*pmessi = messi; 

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n\n", sizeof(messi.name)
                                     , sizeof(messi.age)
                                     , sizeof(messi.height)
                                     , sizeof(messi));

    //2.
    printf("name-dir   : %p \n"
            "age-dir   : %p \n"
            "height-dir: %p \n"
            "data_t-dir: %p \n" , (void *) &pmessi->name
                                , (void *) &pmessi->age
                                , (void *) &pmessi->height
                                , (void *) &pmessi);
    
    
    free(pmessi);

    return EXIT_SUCCESS;
}
