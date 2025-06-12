#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

/* declaro list como un puntero hacia un Nodo */
struct _Node {
    int elem;
    struct _Node *next;
};

typedef struct _Node* list;
typedef int list_elem;

/* Constructors */
list empty();
/* Crea una lista vacia */

list addl (list_elem e, list l);
/* Agrega un elemento al inicio de la lista */

/* Operations */
bool is_empty (list l);
/* Devuelve si una lista es vacia */

list_elem head (list l);
/* Devuelve el primer elemento de la lista l */

list tail (list l);
/* Elimina el primer elemento de una lista */

list addr (list l, list_elem e);
/* Agrega el elemento e al final de la lista l */

unsigned int length (list l);
/* Devuelve la cantidad de elementos de la lista l*/

list concat (list l, list l0);
/* Agrega al final de l todos los elementos de l0 en el mismo orden. */

list_elem index (list l, unsigned int n);
/* Devuelve el n-ésimo elemento de la lista l */

list take (list l, unsigned int n);
/* Deja en l sólo los primeros n elementos, eliminando el resto*/

list drop (list l, unsigned int n);
/* Elimina los primeros n elementos de l */

list copy_list (list l1);
/*Copia todos los elementos de l1 en una nueva lista*/

/* Destroy */
void destroy (list l);
/* Libera memoria en caso que sea necesario. */

#endif