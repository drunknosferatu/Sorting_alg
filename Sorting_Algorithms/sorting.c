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

void CountingSort(List *l,List *aux, long max){
	long i;
	long *c=(long*) malloc((max+1)*sizeof(tpElem));//creates an auxiliary array
	for(i=0;i<=max;i++) c[i]=0;//fills it with zeroes(calloc was not used due to efficiency improvement)
	long *sorted=(long*) malloc (l->length*sizeof(tpElem));//creates other auxiliary array
	for(i=0;i<l->length;i++) c[aux->elements[i]]++;//fills c with indexes
	for(i=1;i<=max;i++) c[i]=c[i]+c[i-1];//modify the indexes to account for the number of occurences of the previous numbers
	for(i=(l->length-1);i>=0;i--){//sorts
	       	sorted[c[aux->elements[i]]-1]=l->elements[i];
		c[aux->elements[i]]--;
	}
	l->elements=sorted;//does the permutations
	free(c);
}
//*****************************************************************************

//**************************** RADIX SORT**************************************
void RadixSort(List *l){
	long max=l->elements[0];
	long i,j,mag,k,aux;
	for (i=1;i<l->length;i++)//this for loop finds the maximum value of the array 
	    if(max<l->elements[i]) 
	        max=l->elements[i];
	for (mag=0;max/(long)(pow(10,mag))!=0;mag++);//this for loop determines the magnitude of the max value
	mag--;
	List temp;
	buildList(&temp);
	temp.length=l->length;
	for(i=0;i<=mag;i++){
		for(k=0;k<l->length;k++){ 
			temp.elements[k]=l->elements[k];//this is just some numerical "parsing"
			for(j=mag;j>i;j--) 
			    temp.elements[k]%=(long)pow(10,j);
			temp.elements[k]/=pow(10,j);
		}
		CountingSort(l,&temp,max);//sends the "parsed" array along with the original to be sorted
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


//*******************************BUBBLE SORT**************************************************
void BubbleSort(List *l){
    for (long i = 0; i < l->length; i++){
        for (long j = 0; j < ((l->length)-i); j++){
            if (l->elements[j] > l->elements[j+1]){
                swap(l, j, j + 1);
            }
        }
    }
}

void OptimizedBubbleSort(List *l){
    int swapped = 1;

    for (long i = 0; i < l->length; i++){
        while (swapped == 1){
            swapped = 0;
            for (long j = 0; j < ((l->length)-i); j++){
                if (l->elements[j] > l->elements[j+1]){
                    swapped = 1;
                    swap(l, j, j + 1);
                }
            }
        }
    }
}

//****************************************************************************
