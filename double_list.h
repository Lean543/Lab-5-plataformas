
typedef struct Node {

    int data;

    struct Node* prev;
    struct Node* next;

} Node;

void insertbeginning(Node** cabeza, int data);

void insertfinaly(Node** cabeza, int data);

void Printlistadelante(Node* cabeza);

void Eliminatenode(Node** cabeza, int dataeliminate);

void Searchnode(Node** cabeza, int datasearch);

void insertnode(Node** cabeza, int data, int position);

void Printlistatras(Node* cabeza);

void freelist(Node* head);



