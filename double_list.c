#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"


void insertbeginning(Node** cabeza, int data){

    //Crea un nuevo nodo

    Node * newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){

        printf("Falló reservando memoria\n");

        return;

    }

    //Desde aquí asigna el nuevo nodo como cabeza
    //Asigna direcciones prev y posterior del nuevo nodo cabeza como null y asigna su data

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*cabeza == NULL) {   // Asegura que la dirección del nodo cabeza no apunta a null porque osinó asignará el next del nuevo nodo cabeza como null y así sucesivamente
        *cabeza = newNode;  // Si pasa eso hay que asignar el nodo cabeza a un nodo que tenga un espacio de memoria definida (newnode si tiene un espacio de memoria definido ya asignado aunque no tenga nada). Si no se hace lo que pasará es que se le asignará null y cuando alguna función necesite acceder a la dirección del nuevo nodo no la va a encontrar y habrá un segmentation fault (me pasó)
        return;
    }

    (*cabeza)->prev = newNode;  //dirección de nodo anterior del antiguo nodo cabeza se reemplaza por la dirección del nuevo nodo cabeza

    newNode->next = *cabeza;   //dirección posterior del nuevo nodo cabeza se reemplaza por la dirección del prev nodo cabeza

    *cabeza = newNode;   //Nodo cabeza asignado y lista echa

}


void insertfinaly(Node** cabeza, int data){

    //Crea un nuevo nodo

    Node * newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){

        printf("Falló reservando memoria\n");

        return;

    }

    //Desde aquí asigna el nuevo nodo como tail
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    Node* target = *cabeza;   //Hace un puntero temporal que se le asigna la dirección de memoria del nodo cabeza en ese momento
    
    while (target->next != NULL) {  // Recorre cada dirección al nodo posterior del posterior y así sucesivamente del nodo cabeza, el que tenga esta dirección como null es el último nodo de la lista (tail)

        target = target->next;  // Al final target se iguala a la dirección de tail y sale del ciclo (se hace un puntero a tail)

    }

    target->next = newNode;

    newNode->prev = target;    // Asigna la dirección nodo anterior del nuevo tail la dirección del antiguo tail
    

}


void insertnode(Node** cabeza, int data, int position){

    //Crea un nuevo nodo

    Node * newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL){

        printf("Falló reservando memoria\n");

        return;

    }
    //Desde aquí asigna el nuevo nodo como cabeza
    //Asigna direcciones anterior y posterior del nuevo nodo cabeza como null y asigna su data

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 0){

        if (*cabeza == NULL) {   // Asegura que la dirección del nodo cabeza no apunta a null porque osinó asignará el next del nuevo nodo cabeza como null y así sucesivamente
            *cabeza = newNode;  // Si pasa eso hay que asignar el nodo cabeza a un nodo que tenga un espacio de memoria definida (newnode si tiene un espacio de memoria definido ya asignado aunque no tenga nada). Si no se hace lo que pasará es que se le asignará null y cuando alguna función necesite acceder a la dirección del nuevo nodo no la va a encontrar y habrá un segmentation fault (me pasó)
            return;
        }

        (*cabeza)->prev = newNode;  //dirección de nodo anterior del antiguo nodo cabeza se reemplaza por la dirección del nuevo nodo cabeza

        newNode->next = *cabeza;   //dirección posterior del nuevo nodo cabeza se reemplaza por la dirección del prev nodo cabeza

        *cabeza = newNode;   //Nodo cabeza asignado y lista echa

        return;

    }

    Node* target = *cabeza;   //Hace un puntero temporal que se iguala al nodo cabeza en ese momento

    int z = 0;
    for (z = 0; z < position - 1; z++){

        target = target->next;

    }

    newNode->next = target->next;

    newNode->prev = target;

    (target->next)->prev = newNode;

    target->next = newNode;
    
}

void Eliminatenode(Node** cabeza, int dataeliminate){

    Node* target = *cabeza;

    while (target->next != NULL) {  

        if (target->data == dataeliminate){

            if (target == *cabeza) {

                (target->next)->prev = NULL;

                *cabeza = target->next;

                return;

            }

            (target->next)->prev = target->prev;

            (target->prev)->next = target->next;

            free(target);

            return;

        }

        target = target->next;

    }

}

void Searchnode(Node ** cabeza, int datasearch) {

    Node* target = *cabeza;   //Hace un nodo temporal que se iguala al nodo cabeza en ese momento

    int y = 0;

    printf("El nodo o nodos que contienen esa data son: \n");

    while (target->next != NULL) {  // Recorre cada dirección al nodo posterior del posterior y así sucesivamente del nodo cabeza, el que tenga esta dirección como null es el último nodo de la lista (tail) y no imprime mas

        y ++;

        if (target->data == datasearch){

            printf("Nodo %d\n", y);

        }

        target = target->next;

    }

}

void Printlistadelante(Node * cabeza) {

    Node* target = cabeza;   //Hace un nodo temporal que se iguala al nodo cabeza en ese momento

    while (target->next != NULL) {  // Recorre cada dirección al nodo posterior del posterior y así sucesivamente del nodo cabeza, el que tenga esta dirección como null es el último nodo de la lista (tail) y no imprime mas

        printf("%d\n", target->data);

        target = target->next;

    }

    printf("%d\n", target->data);

}

void Printlistatras(Node * cabeza) {

    Node* target = cabeza;   //Hace un nodo temporal que se iguala al nodo cabeza en ese momento

    while (target->next != NULL) {  // Recorre cada dirección al nodo posterior del posterior y así sucesivamente del nodo cabeza, el que tenga esta dirección como null es el último nodo de la lista (tail) y no imprime mas

        target = target->next;

    }

    while (target->prev != NULL) {  // Recorre cada dirección al nodo anterior del posterior y así sucesivamente del nodo tail

        printf("%d\n", target->data);

        target = target->prev;

    }

    printf("%d\n", target->data);

}

void freelist(Node* cabeza){

    Node * actual = cabeza;

    Node * next;

    while(actual != NULL){

        next = actual->next;
        free(actual);
        actual = next;

    }

}
