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

int contagem(No *head, int vezes) {
    int contador = 0;
    No *atual = head;

    while (atual != NULL) {
        if (atual->data == vezes) {
            contador++;
        }
        atual = atual->next;
    }

    return contador;
}

void printlista(No *head) {
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
    inserir(lista, 4);
    inserir(lista, 2);

    cout << "lista:" << endl;
    printlista(lista);

    int vezes = 2;
    int ocorrencia = contagem(lista, vezes);

    cout << "O numero " << vezes<< " aparece " << ocorrencia << " vezes na lista" << endl;


    while (lista != NULL) {
        No *temp = lista;
        lista = lista->next;
        delete temp;
    }

    return 0;
}
