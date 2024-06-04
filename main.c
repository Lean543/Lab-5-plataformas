#include <stdio.h>
#include "double_list.h"

int main(){

    int i;

    Node * head = NULL; //nuevo nodo sin nada

    //Se crea una lista doblemente enlazada agregando 3 nodos al inicio

    for (i = 0; i <= 3; i++){

        int data = 56;

        insertbeginning(&head, data);

    }

    //Agrega 2 nodos al final

    for (i = 0; i <= 2; i++){

        int data = 77;

        insertfinaly(&head, data);

    }

    //Imprimir lista original

    printf("Lista impresa hacia adelante:\n");

    Printlistadelante(head);

    //Eliminar nodo por data

    int dataeliminate = 56;

    Eliminatenode(&head, dataeliminate);

    //imprimir lista sin un nodo

    printf("Lista impresa hacia adelante (Un nodo eliminado):\n");

    Printlistadelante(head);

    //Buscar nodo por data
    
    int datasearch = 77;

    Searchnode(&head, datasearch);

    //insertar nodo en una posición

    int data = 88;

    int position = 3;

    insertnode(&head, data, position);

    printf("Lista impresa hacia adelante (Nuevo nodo insertado):\n");

    Printlistadelante(head);


    freelist(head);

    return 0;
}