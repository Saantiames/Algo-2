#include <stdio.h>;
#include <stdbool.h>;
#include <assert.h>;
#define N 5

struct bound_data{
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data boundCheck(int value, int arr[], unsigned int length){
    
    //Devuelve si un valor "value" 
    // 1- es minimo
    // 2- es máximo
    // 3- existe
    // 4- que posición existe (-1 si no existe)
    // Caso que no exista, devuelve
    // false, false, false ,-1

    struct bound_data ret;

    ret.is_upperbound = false;
    ret.is_lowerbound = false;
    ret.exists = false;
    ret.where = -1;

    int lowest  = find_bound(arr, length, 1);
    int greatest = find_bound(arr, length, 0);

    if(value == lowest){
        ret.is_lowerbound = true;
    }

    if(value == greatest){
        ret.is_upperbound = true;
    }

    for(int i = 0; i<length; i++){
        if(value == arr[i]){
            ret.exists = true;
            ret.where = i;
        }
    }

    return ret;
}

int findBound(int arr[], unsigned int length, int option){

    //Esta funcion me busca el menor o el mayor de un array NO VACÍO, en funcion de si su argumento option es 
    // 0--> mayor
    // 1--> menor
    
    //primero n empieza siendo el 0'esimo elemento
    //luego se verifica desde i = 1 hasta length

    assert(option != 0 || option != 1);
    assert(length !=0);

    int n = arr[0];

    if(option == 0){
        //buscar mayor
        for(int i = 1; i<length; i++){
            if(arr[i]<n){
                n = arr[i];
            }
        }
    }else{
        //buscar menor
        for(int i = 1; i<length; i++){
            if(arr[i]>n){
                n = arr[i];
            }
        }
    }

    return n;
}

void addGiladas(int arr[], int length){
    for(int i = 0; i<length; i++){

        printf("\n Ingrese el valor --> ");
        scanf("%d", &arr[i]);

    }
}

// struct bound_data printData(struct bound_data data){

//     int t1 = 0;
//     int t2 = 0;
//     int t3 = 0;
    
//     if(data.is_lowerbound){
//         t1= 1;
//     }

//     if(data.is_upperbound){
//         t2= 1;
//     }

//     if(data.exists){
//         t3= 1;
//     }
//     printf("")
// }

int main(){

    int arr[N];
    addGiladas(arr,N);
    int number;
    printf("\n Ingrese el numero que quiere buscar y lala --> ");
    scanf("%d",&number);
    
    struct bound_data data = boundCheck(number, arr,N);

    printf("%d", data.is_upperbound); 
    printf("%d", data.is_lowerbound); 
    printf("%d", data.exists);  
    printf("%u", data.where);   

    
    return 0;
}