#include <iostream>
using namespace std;

struct No {
    int data;
    No *next;
};

No *inserir(No* head, int num) {
    No *novoNo = new No{num, NULL};
    novoNo->next = head;
    return novoNo;
}

No *reverterList(No *head) {
    No *anterior = NULL;
    No *atual = head;
    No *next = NULL;

    while (atual != NULL) {
        next = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = next;
    }

    return anterior;
}

void printList(No *head) {
    No *atual = head;
    while (atual != NULL) {
        cout << atual->data << endl;
        atual = atual->next;
    }
    cout << "NULL" << endl;
}

int main() {
    No *lista = NULL;

    lista = inserir(lista, 1);
    lista = inserir(lista, 2);
    lista = inserir(lista, 3);
    lista = inserir(lista, 4);
    lista = inserir(lista, 5);

    cout << "Lista original:" << endl;
    printList(lista);

    lista = reverterList(lista);

    cout << "Lista invertida:" << endl;
    printList(lista);

    while (lista != NULL) {
        No *temp = lista;
        lista = lista->next;
        delete temp;
    }

    return 0;
}
