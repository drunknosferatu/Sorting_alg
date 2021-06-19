#include "List.h"


void buildList(List *l)
{
	l->elements = (tpElem*)malloc(maxSize * sizeof(tpElem));
	l->length = 0;
}


int insert(List *l, tpElem elem)
{
    if(l->length >= maxSize)
        return Error;
    else
    {
        l->elements[(l->length)] = elem;
        (l->length)++;
    }
    return Success;
}


void printList(List l)
{
    long i;
    for(i = 0; i < l.length; i++)
        printf("%d\t", l.elements[i]);
    printf("\n");
}


void destroyList(List *l)
{
    l->length = 0;
    free(l->elements);
}



void swap(List *l, long i, long j)
{
    tpElem aux = l->elements[i];
    l->elements[i] = l->elements[j];
    l->elements[j] = aux;
}
