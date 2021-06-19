#include "List.h"


//***********************HeapSort************************************************************
void MaxHeapfy(List *l, long i);            // Mantem a propriedade de max-heap


void BuildMaxHeap(List *l);                // Constroe uma max-heap a partir de uma lista


void HeapSort(List *l);                     // Ordena, em ordem crescente, os elementos da lista


//*********************************************************************************************

void CountingSort(List *l,List *aux, int max);

void RadixSort(List *l);



int RandomInteger (long low, long high);                 // Funcao que gera numeros aleatorios. Foi criada 
                                                         // por Eric Roberts, autor do livro The Art and Science of C

long partition(List *l, long ini, long end);

long random_partition(List *l, long ini, long end);

void quicksort(List *l, long ini, long end);