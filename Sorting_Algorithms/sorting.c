#include "sorting.h"
#include <math.h>
//*********************HeapSort*********************************************

void MaxHeapfy(List *l, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;
    if(left < l->length && l->elements[left] > l->elements[i])
        largest = left;
    else
        largest = i;
    if(right < l->length && l->elements[right] > l->elements[largest])
        largest = right;
    if(largest != i)
    {
        swap(l, i, largest);
        MaxHeapfy(l, largest);
    }
}



void BuildMaxHeap(List *l)
{
    int i;
    for(i = (l->length / 2) - 1; i >= 0; i--)
        MaxHeapfy(l, i);
    
}


void HeapSort(List *l)
{
    int aux = l->length;
    BuildMaxHeap(l);
    while(l->length > 1)
    {
        swap(l, 0, l->length - 1);
        l->length--;
        MaxHeapfy(l, 0);
    }
    l->length = aux;
}

//*****************************************************************************



//**************************COUNTING SORT*****************************************

void CountingSort(List *l, List *aux, int max){
	int i;
	tpElem *c = (tpElem*) malloc((max+1) * sizeof(tpElem));
	for(i = 0; i <= max; i++) c[i] = 0;
	tpElem *sorted = (tpElem*) malloc (l->length * sizeof(tpElem));
	for(i = 0;i < l->length; i++) c[aux->elements[i]]++;
	for(i = 1; i <= max; i++) c[i] = c[i] + c[i-1];
	for(i = (l->length-1); i >= 0; i--){
	       	sorted[c[aux->elements[i]] - 1] = l->elements[i];
		c[aux->elements[i]]--;
	}
	l->elements = sorted;
	free(c);
}
//*****************************************************************************

//**************************** RADIX SORT**************************************
void RadixSort(List *l){
	int max = l->elements[0];
	int i, j, ordem, k, aux;
	for (i = 1; i < l->length; i++) if(max < l->elements[i]) max = l->elements[i];
	for (ordem = 0; max / (int)(pow(10, ordem)) != 0;ordem++);
	ordem--;
	List temp;
	buildList(&temp);
	temp.length = l->length;
	for(i = 0; i <= ordem; i++){
		for(k = 0;k < l->length; k++){ 
			temp.elements[k] = l->elements[k];
			for(j = ordem; j > i; j--) temp.elements[k] %= (int)pow(10, j);
			temp.elements[k] /= pow(10, j);
		}
		CountingSort(l, &temp, max);
	}
	free(temp.elements);
}

