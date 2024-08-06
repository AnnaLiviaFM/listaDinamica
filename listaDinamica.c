/*
───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───
───█▒▒░░░░░░░░░▒▒█───                Listas
────█░░█░░░░░█░░█────                
─▄▄──█░░░▀█▀░░░█──▄▄─
█░░█─▀▄░░░░░░░▄▀─█░░█                          By Anna Livia

*/

#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista Dinâmica
typedef struct Lista{
    int dado;
    struct Lista* prox;
}Lista;

// Criar uma lista vazia
Lista* criarLista(){
    return NULL;
}

// Verificar se a lista está vazia
int ehVazia(Lista* fim){
    return fim == NULL;
}

// Obter o tamanho da lista
int getTamanho(Lista* fim){
    int tam = 0;
    while (fim != NULL){
        tam++;
        fim = fim->prox;
    }
    return tam;
}

// Obter o valor de um elemento em uma posição determinada
int valorElemento(Lista* fim, int pos){
    if (pos < 1){
        fprintf(stderr, "Posição inválida\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < pos; i++){
        if (fim == NULL){
            fprintf(stderr, "Posição inválida\n");
            exit(EXIT_FAILURE);
        }
        fim = fim->prox;
    }
    if (fim == NULL){
        fprintf(stderr, "Posição inválida\n");
        exit(EXIT_FAILURE);
    }
    return fim->dado;
}

// Modificar o valor de um elemento
void modificarValor(Lista* fim, int pos, int valor){
    if (pos < 1){
        fprintf(stderr, "Posição inválida\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < pos; i++){
        if (fim == NULL){
            fprintf(stderr, "Posição inválida\n");
            exit(EXIT_FAILURE);
        }
        fim = fim->prox;
    }
    if (fim == NULL){
        fprintf(stderr, "Posição inválida\n");
        exit(EXIT_FAILURE);
    }
    fim->dado = valor;
}

// Inserir um elemento
void insereElemento(Lista** fim, int pos, int valor){
    if (pos < 1){
        fprintf(stderr, "Posição inválida\n");
        exit(EXIT_FAILURE);
    }
    Lista* novoNo = (Lista*)malloc(sizeof(Lista));
    novoNo->dado = valor;
    if (pos == 1){
        novoNo->prox = *fim;
        *fim = novoNo;
    }else{
        Lista* prev = *fim;
        for (int i = 1; i < pos - 1; i++){
            if (prev == NULL) {
                free(novoNo);
                fprintf(stderr, "Posição inválida\n");
                exit(EXIT_FAILURE);
            }
            prev = prev->prox;
        }
        novoNo->prox = prev->prox;
        prev->prox = novoNo;
    }
}

// Retirar um elemento
void removeElemento(Lista** fim, int pos){
    if (pos < 1){
        fprintf(stderr, "Posição inválida\n");
        exit(EXIT_FAILURE);
    }
    if (pos == 1){
        Lista* temp = *fim;
        *fim = (*fim)->prox;
        free(temp);
    }else{
        Lista* prev = *fim;
        for (int i = 1; i < pos - 1; i++){
            if (prev == NULL) {
                fprintf(stderr, "Posição inválida\n");
                exit(EXIT_FAILURE);
            }
            prev = prev->prox;
        }
        if (prev->prox == NULL){
            fprintf(stderr, "Posição inválida\n");
            exit(EXIT_FAILURE);
        }
        Lista* temp = prev->prox;
        prev->prox = temp->prox;
        free(temp);
    }
}

// Imprimir os elementos da lista
void mostraLista(Lista* fim){
    while (fim != NULL){
        printf("%d ", fim->dado);
        fim = fim->prox;
    }
    printf("\n");
}

// Main e testes
int main(){
    Lista* list = criarLista();

    insereElemento(&list, 1, 10);
    insereElemento(&list, 2, 20);
    insereElemento(&list, 3, 30);
    mostraLista(list); 
    // Saída esperada: 10 20 30

    printf("Tamanho da lista: %d\n", getTamanho(list)); 
    // Saída esperada: 3

    printf("Elemento na posição 2: %d\n", valorElemento(list, 2)); 
    // Saída esperada: 20

    modificarValor(list, 2, 25);
    mostraLista(list); 
    // Saída esperada: 10 25 30

    removeElemento(&list, 2);
    mostraLista(list); 
    // Saída esperada: 10 30

    printf("Lista está vazia: %s\n", ehVazia(list) ? "Sim" : "Não"); 
    // Saída esperada: Não

    removeElemento(&list, 1);
    removeElemento(&list, 1);
    printf("Lista está vazia: %s\n", ehVazia(list) ? "Sim" : "Não"); 
    // Saída esperada: Sim

    return 0;
}