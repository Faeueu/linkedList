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

void printList(No *head) {
    No *atual = head;
    while (atual != NULL) {
        cout << atual->data << endl;
        atual = atual->next;
    }
    cout << "NULL" << endl;
}

void inverter(No* &head, int inicio, int fim) {
    if (head == NULL || (head)->next == NULL || inicio >= fim) {
        return;
    }

    No *dummy = new No{-1, NULL};
    dummy->next = head;
    No *anterior = dummy;
    No *atual = head;

    int posicao = 1;
    while (posicao < inicio) {
        anterior = atual;
        atual = atual->next;
        posicao++;
    }

    No *inicioIntervalo = atual;
    No *next = NULL;
    No *fimIntervalo = NULL;
    while (posicao <= fim) {
        next = atual->next;
        atual->next = fimIntervalo;
        fimIntervalo = atual;
        atual = next;
        posicao++;
    }

    anterior->next = fimIntervalo;
    inicioIntervalo->next = atual;

    head = dummy->next;
    delete dummy;
}


int main() {
    No *lista = NULL;

    inserir(lista, 10);
    inserir(lista, 20);
    inserir(lista, 30);
    inserir(lista, 40);
    inserir(lista, 50);

    cout << "Lista original:" << endl;
    printList(lista);

    int inicio = 2;
    int fim = 4;
    inverter(lista, inicio, fim);
    cout << endl;

    cout << "Lista invertida de " << inicio << " a " << fim << ":" << endl;
    printList(lista);

    while (lista != NULL) {
        No* temp = lista;
        lista = lista->next;
        delete temp;
    }

    return 0;
}
