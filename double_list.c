#include <stdio.h>
#include <stdlib.h>


typedef struct Node {

    int data;

    struct Node* prev;
    struct Node* next;

} Node;

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

    Node* temp = *cabeza;   //Hace un nodo temporal que se le asigna la dirección de memoria del nodo head en ese momento (Hay 2 nodos head iguales pero con diferente nombre)

    while (temp->next != NULL) {  // Recorre cada dirección al nodo posterior del posterior y así sucesivamente del nodo head, el que tenga esta dirección como null es el último nodo de la lista (tail)

        temp = temp->next;  // Al final temp se iguala a la dirección de tail y sale del ciclo

    }

    temp->next = newNode;   // Asigna la dirección nodo posterior del antiguo tail (que está con el nombre de temp) la dirección del nuevo nodo

    newNode->prev = temp;    // Asigna la dirección nodo anterior del nuevo tail la dirección del antiguo tail

}

void Printlistadelante(Node * cabeza) {

    printf("Lista impresa hacia adelante:\n");

    Node* temp = cabeza;   //Hace un nodo temporal que se iguala al nodo head en ese momento (Hay 2 nodos head iguales pero con diferente nombre)

    while (temp->next != NULL) {  // Recorre cada dirección al nodo posterior del posterior y así sucesivamente del nodo head, el que tenga esta dirección como null es el último nodo de la lista (tail) y no imprime mas

        printf("%d\n", temp->data);

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

    //Imprimir lista

    Printlistadelante(head);

    freelist(head);

    return 0;
}