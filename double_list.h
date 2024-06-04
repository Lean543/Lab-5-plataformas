
typedef struct Node {

    int data;

    struct Node* prev;
    struct Node* next;

} Node;

void insertbeginning(Node** cabeza, char data);

void insertfinaly(Node** cabeza, char data);

void Printlistadelante(Node * cabeza);

void Eliminatenode(Node** cabeza, char dataeliminate);

void Searchnode(Node** cabeza, char datasearch);

void insertnode(Node** cabeza, char data, int position);

void freelist(Node* head);



