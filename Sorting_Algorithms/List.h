#include <stdio.h>
#include <stdlib.h>

#define maxSize 10000000

#define Success 1
#define Error   0


typedef int tpElem;                        // Podem mudar o nome deste tipo



typedef struct                             //Definicao do tipo List
{
    tpElem *elements;
    long length;
}List;

void buildList(List *l);                   // Cria lista como tamanho inicial igual a 0

int insert(List *l, tpElem elem);          // Insere elementos na lista

void printList(List l);                   // Imprime os elementos da lista

void destroyList(List *l);                 // Libera a memoria alocada para a lista e a destroi

void swap(List *l, long i, long j);          // Troca dois elementos de posicao em uma lista
