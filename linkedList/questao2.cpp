#include <iostream>
using namespace std;

struct No {
    int data;
    No *next;
};

void inserir(No* &head, int num) {
    No *novoNo = new No;

    novoNo->data = num;
    novoNo->next = head;

    head = novoNo;
}

void reverterList(No* &head) {
    No* anterior = NULL;
    No* atual = head;
    No* next = NULL;

    while (atual != NULL) {
        next = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = next;
    }

    head = anterior;
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

    inserir(lista, 1);
    inserir(lista, 2);
    inserir(lista, 3);
    inserir(lista, 4);
    inserir(lista, 5);

    cout << "Lista original:" << endl;
    printList(lista);

    reverterList(lista);

    cout << "Lista invertida:" << endl;
    printList(lista);

    while (lista != NULL) {
        No *temp = lista;
        lista = lista->next;
        delete temp;
    }

    return 0;
}
