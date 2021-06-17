#include "sorting.h"
#include <time.h>


int main(void){
    List arr;
    buildList(&arr); 
    int i, j;
    tpElem x;
    srand(time(NULL));
    for(i = 0; i < maxSize; i++)
    {
       x = rand() % (maxSize - 1);
       j = insert(&arr, x);
       if(j == Error)
        {    
            printf("Error!\n");
            break;
        }    
    }
    printList(arr);
    //RadixSort(&arr);
    quicksort(&arr, 0, arr.length - 1);
    printList(arr);
    destroyList(&arr);
   return 0;
}
