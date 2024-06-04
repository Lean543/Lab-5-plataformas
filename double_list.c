#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"


void insertbeginning(Node** cabeza, char data){

    //Crea un nuevo nodo

    Node * newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){

        printf("Falló reservando memoria\n");

        return;

    }

    //Desde aquí asigna el nuevo nodo como head
    //Asigna direcciones anterior y posterior del nuevo nodo head como null y asigna su data

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*cabeza == NULL) {   // Asegura que la dirección del nodo head no apunta a null porque osinó asignará el next del nuevo nodo head como null y así sucesivamente
        *cabeza = newNode;  // Si pasa eso hay que asignar el nodo head a un nodo que tenga un espacio de memoria definida (newnode si tiene un espacio de memoria definido ya asignado aunque no tenga nada). Si no se hace lo que pasará es que se le asignará null y cuando alguna función necesite acceder a la dirección del nuevo nodo no la va a encontrar y habrá un segmentation fault (me pasó)
        return;
    }

    (*cabeza)->prev = newNode;  //dirección de nodo anterior del antiguo nodo head se reemplaza por la dirección del nuevo nodo head

    newNode->next = *cabeza;   //dirección posterior del nuevo nodo head se reemplaza por la dirección del anterior nodo head

    *cabeza = newNode;   //dirección que apuntaba a la anterior head se le asigna la dirección de memoria del nuevo nodo head

}


void insertfinaly(Node** cabeza, char data){

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

    if (*cabeza == NULL) {
        *cabeza = newNode;
        return;
    }

    Node* temp = *cabeza;   //Hace un nodo temporal que se le asigna la dirección de memoria del nodo head en ese momento

    while (temp->next != NULL) {  // Recorre cada dirección al nodo posterior del posterior y así sucesivamente del nodo head, el que tenga esta dirección como null es el último nodo de la lista (tail)

        temp = temp->next;  // Al final temp se iguala a la dirección de tail y sale del ciclo

    }

    temp->next = newNode;   // Asigna la dirección nodo posterior del antiguo tail (que está con el nombre de temp) la dirección del nuevo nodo

    newNode->prev = temp;    // Asigna la dirección nodo anterior del nuevo tail la dirección del antiguo tail

}

void insertnode(Node** cabeza, char data, int position){

    //Crea un nuevo nodo

    Node * newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){

        printf("Falló reservando memoria\n");

        return;

    }

    //Desde aquí asigna el nuevo nodo como head
    //Asigna direcciones anterior y posterior del nuevo nodo head como null y asigna su data

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    int z;

    Node* temp = *cabeza;   //Hace un nodo temporal que se iguala al nodo head en ese momento

    for (z = 1; z < position; z++){

        temp = temp->next;

    }

    (temp->prev)->next = newNode;  

    (temp->next)->prev = newNode;  

    newNode->next = temp->next;
    newNode->prev = temp;

}

void Printlistadelante(Node * cabeza) {

    Node* temp = cabeza;   //Hace un nodo temporal que se iguala al nodo head en ese momento

    while (temp->next != NULL) {  // Recorre cada dirección al nodo posterior del posterior y así sucesivamente del nodo head, el que tenga esta dirección como null es el último nodo de la lista (tail) y no imprime mas

        printf("%d\n", temp->data);

        temp = temp->next;

    }

}

void Eliminatenode(Node** cabeza, char dataeliminate){

    Node* temp = *cabeza;

    while (temp->next != NULL) {  

        if (temp->data == dataeliminate){

            if (*cabeza == NULL || temp == NULL) return;

            if (*cabeza == temp) {
                *cabeza = temp->next;
            }

            if (temp->next != NULL) {
                (temp->next)->prev = temp->prev;
            }

            if (temp->prev != NULL) {
                (temp->prev)->next = temp->next;
            }

            free(temp);

            return;
        }

        temp = temp->next;

    }

}

void Searchnode(Node ** cabeza, char datasearch) {

    Node* temp = *cabeza;   //Hace un nodo temporal que se iguala al nodo head en ese momento

    int y = 0;

    printf("El nodo o nodos que contienen esa data son: \n");

    while (temp->next != NULL) {  // Recorre cada dirección al nodo posterior del posterior y así sucesivamente del nodo head, el que tenga esta dirección como null es el último nodo de la lista (tail) y no imprime mas

        y ++;

        if (temp->data == datasearch){

            printf("Nodo %d\n", y);
        }

        temp = temp->next;

    }

}



void freelist(Node* head){

    Node * actual = head;

    Node * next;

    while(actual != NULL){

        next = actual->next;
        free(actual);
        actual = next;

    }

}
