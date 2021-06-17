#include "sorting.h"



int main(void){
    List arr;
    buildList(&arr); 
    int i, j;
    tpElem x;
    for(i = 0; i < maxSize; i++)
    {
       x = rand() % maxSize;
       j = insert(&arr, x);
       if(j == Error)
        {    
            printf("Error!\n");
            break;
        }    
    }
    printList(arr);
    RadixSort(&arr);
    printList(arr);
    destroyList(&arr);
   return 0;
}
