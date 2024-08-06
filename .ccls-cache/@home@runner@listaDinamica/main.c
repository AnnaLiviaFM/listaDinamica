/*
───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───
───█▒▒░░░░░░░░░▒▒█───                Listas
────█░░█░░░░░█░░█────                
─▄▄──█░░░▀█▀░░░█──▄▄─
█░░█─▀▄░░░░░░░▄▀─█░░█                          By Anna Livia

*/

#include <stdio.h>
#include <stdlib.h>

struct no{
  int dado;
  struct no *prox;
} n;

void criar(struct no**);
void destruir(struct no**);
int ehVazia(struct no*);
void inserir(struct no**, int);
int insereFim(struct no**);
void mostrar(struct no*);
void remover(struct no**);



void criar(struct no **l){
 *l = NULL;
}
void destruir(struct no **l){
  while(*l){
    struct no *aux = *l;
    *l = (*l)->prox;
    free(aux);
  }
}

int ehVazia(struct no *l){
  return l == NULL;
}

void inserir(struct no **l, int dado){
  struct no *novo = (struct no*) malloc(sizeof(struct no));
  if(!novo) return;

  novo->dado = dado;
  novo->prox = *l;

  *l = novo;
}

int insereFim(struct no **l){
  struct no *novo, *aux;
  novo = (struct no*) malloc(sizeof(struct no));
  if(novo != 0){
    scanf("%d",&novo->dado);
    novo->prox = 0;

    for(aux = *l; aux, aux->prox; aux=aux->prox);
    if(aux == 0){
      *l = novo;
    }else{
      aux->prox = novo;
    }
  }

void mostrar(struct no *l){
  for(;l;l=l->prox){
    printf("%d ", l->dado);
  } puts("");
}

void remover(struct no **l){
  if(!*l) return;
  struct no *aux = (*l)->prox;
  free(*l);
  *l = aux;
}

int main(void) {
  struct no *lista;
  criar(&lista);

  for(int i = 0; i < 5; i++){
     inserir(&lista, i);
  }

  mostrar(lista);
  // for(int i = 0; i < 3; i++){
  //    remover(&lista);
  // }
  // mostrar(lista);

  destruir(&lista);
  mostrar(lista);
  return 0;
}