#include "List.h"


//***********************HeapSort************************************************************
void MaxHeapfy(List *l, long i);            // Mantem a propriedade de max-heap


void BuildMaxHeap(List *l);                // Constroe uma max-heap a partir de uma lista


void HeapSort(List *l);                     // Ordena, em ordem crescente, os elementos da lista


//*********************************************************************************************


//**************************COUNTING SORT - RADIX SORT*****************************************
void CountingSort(List *l, List *aux, long max);

void RadixSort(List *l);

//*********************************************************************************************


//*******************************QuickSort*******************************************
int RandomInteger (long low, long high);                 // Funcao que gera numeros aleatorios. Foi criada 
                                                         // por Eric Roberts, autor do livro The Art and Science of C

long Partition(List *l, long ini, long end);

long RandomPartition(List *l, long ini, long end);

void QuickSort(List *l, long ini, long end);

void BubbleSort(List *l);

void OptimizedBubbleSort(List *l);

//*******************************************************************************************
