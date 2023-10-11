#include <iostream>
using namespace std;

struct No {
    int data;
    No* next;
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

bool palindromo(No *head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    int tamanho = 0;
    No *atual = head;
    while (atual != NULL) {
        tamanho++;
        atual = atual->next;
    }

    int metade[tamanho / 2];
    int indice = 0;
    atual = head;

    while (indice < tamanho / 2) {
        metade[indice] = atual->data;
        atual = atual->next;
        indice++;
    }

    if (tamanho % 2 != 0) {
        atual = atual->next;
    }

    while (atual != NULL) {
        if (atual->data != metade[indice - 1]) {
            return false;
        }
        atual = atual->next;
        indice--;
    }

    return true;
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
    inserir(lista, 2);
    inserir(lista, 1);

    cout << "Lista original:" << endl;
    printList(lista);

    bool resultado = palindromo(lista);

    if (resultado) {
        cout << "A lista e um palindromo." << endl;
    } else {
        cout << "A lista nao e um palindromo." << endl;
    }

    while (lista != NULL) {
        No *temp = lista;
        lista = lista->next;
        delete temp;
    }

    return 0;
}
