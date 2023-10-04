#include <iostream>
using namespace std;

struct No {
    int data;
    No *next;
};

No *inserir(No *head, int num) {
    No* novoNo = new No{num, NULL};
    novoNo->next = head;
    return novoNo;
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
    lista = inserir(lista, 1);
    lista = inserir(lista, 2);
    lista = inserir(lista, 3);
    lista = inserir(lista, 2);
    lista = inserir(lista, 4);
    lista = inserir(lista, 2);

    cout << "lista:" << endl;
    printlista(lista);

    int vezes = 2;
    int ocorrencia = contagem(lista, vezes);

    cout << "O numero " << vezes<< " ocorre " << ocorrencia << " vezes na lista" << endl;


    while (lista != NULL) {
        No *temp = lista;
        lista = lista->next;
        delete temp;
    }

    return 0;
}
