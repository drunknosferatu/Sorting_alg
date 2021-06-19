#include "sorting.h"
#include <math.h>
//*********************HeapSort*********************************************

void MaxHeapfy(List *l, long i)
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

void CountingSort(List *l, List *aux, long max){
	int i;
	tpElem *c = (tpElem*) malloc((max + 1) * sizeof(tpElem));
	for(i = 0; i <= max; i++) c[i] = 0;
	tpElem *sorted = (tpElem*) malloc (l->length * sizeof(tpElem));
	for(i = 0;i < l->length; i++) c[aux->elements[i]]++;
	for(i = 1; i <= max; i++) c[i] = c[i] + c[i-1];
	for(i = (l->length-1); i >= 0; i--)
        {
	       	sorted[c[aux->elements[i]] - 1] = l->elements[i];
		c[aux->elements[i]]--;
	}
	l->elements = sorted;
	free(c);
}
//*****************************************************************************

//**************************** RADIX SORT**************************************
void RadixSort(List *l)
{
	long max = l->elements[0];
	long i, j, ordem, k;
	for (i = 1; i < l->length; i++) if(max < l->elements[i]) max = l->elements[i];
	for (ordem = 0; max / (long)(pow(10, ordem)) != 0;ordem++);
	ordem--;
	List temp;
	buildList(&temp);
	temp.length = l->length;
	for(i = 0; i <= ordem; i++)
        {
		for(k = 0;k < l->length; k++)
                { 
			temp.elements[k] = l->elements[k];
			for(j = ordem; j > i; j--) temp.elements[k] %= (long)pow(10, j);
			temp.elements[k] /= pow(10, j);
		}
		CountingSort(l, &temp, max);
	}
	free(temp.elements);
}


//*******************************QuickSort*******************************************
int RandomInteger (long low, long high)
{
    int k;
    double d;
    
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}



long Partition(List *l, long ini, long end)
{
    long pivot = l->elements[end];
    long i = ini - 1;
    for (long j = ini; j < end ; j++)
    {
        if (l->elements[j] <= pivot)
        {
            i++;
            swap(l, i, j);
        }
    }
    swap(l, i + 1, end);
    return i + 1;
}



long RandomPartition(List *l, long ini, long end)
{
    long k = RandomInteger(ini, end);
    swap(l, k, end);
    return Partition(l, ini, end);
}



void QuickSort(List *l, long ini, long end)
{
    long pivot;
    if (ini < end)
    {
        pivot = RandomPartition(l, ini, end);
        QuickSort(l, ini, pivot - 1);
        QuickSort(l, pivot + 1, end);
    }

}

//********************************************************************************************
