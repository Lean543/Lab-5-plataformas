#include <stdio.h>
#include "double_list.h"

int main(){

    Node * head = NULL; //nuevo nodo sin nada

    //Se crea una lista doblemente enlazada con un nodo head

    int data = 1;
    insertbeginning(&head, data);


    //inserta un nodo tail
    data = 100;
    insertfinaly(&head, data);

    //Imprimir lista original
    printf("Lista impresa hacia adelante:\n");
    Printlistadelante(head);


    //inserta un nodo en alguna posición
    data = 364;
    int position = 1;
    insertnode(&head, data, position);

    //inserta un nodo en alguna posición
    data = 221;
    position = 2;
    insertnode(&head, data, position);

    //inserta un nodo en alguna posición
    data = 74;
    position = 0;
    insertnode(&head, data, position);

    //Imprimir lista
    printf("Lista impresa hacia adelante:\n");
    Printlistadelante(head);


    //Eliminar nodo por data
    int dataeliminate = 221;
    Eliminatenode(&head, dataeliminate);


    //inserta un nodo en alguna posición
    data = 55;
    position = 2;
    insertnode(&head, data, position);


    //imprimir lista sin un nodo y un nodo mas
    printf("Lista impresa hacia adelante (Un nodo eliminado y otro agregado):\n");
    Printlistadelante(head);


    //Buscar nodo por data
    int datasearch = 364;
    Searchnode(&head, datasearch);


    //Imprimir lista hacia atrás
    printf("Lista impresa hacia atrás (con nuevo nodo insertado):\n");
    data = 55;
    position = 4;
    insertnode(&head, data, position);
    Printlistatras(head);


    //Buscar nodo por data
    datasearch = 55;
    Searchnode(&head, datasearch);


    freelist(head);
    return 0;
}