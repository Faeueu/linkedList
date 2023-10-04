#include <iostream>
using namespace std;

struct No {
    int data;
    No *next;
};

No *inserir(No *head, int num) {
    No *novoNo = new No{num, NULL};
    novoNo->next = head;
    return novoNo;
}

void printList(No *head) {
    No *atual = head;
    while (atual != NULL) {
        cout << atual->data << endl;
        atual = atual->next;
    }
    cout << "NULL" << endl;
}

No *inverter(No *head, int inicio, int fim) {
    if (head == NULL || head->next == NULL || inicio >= fim) {
        return head;
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
    No *proximo = NULL;
    No *fimIntervalo = NULL;
    while (posicao <= fim) {
        proximo = atual->next;
        atual->next = fimIntervalo;
        fimIntervalo = atual;
        atual = proximo;
        posicao++;
    }

    anterior->next = fimIntervalo;
    inicioIntervalo->next = atual;

    head = dummy->next;
    delete dummy;

    return head;
}

int main() {
    No *lista = NULL;

    lista = inserir(lista, 10);
    lista = inserir(lista, 20);
    lista = inserir(lista, 30);
    lista = inserir(lista, 40);
    lista = inserir(lista, 50);

    cout << "Lista original:" << endl;
    printList(lista);

    int inicio = 2;
    int fim = 4;
    lista = inverter(lista, inicio, fim);
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
