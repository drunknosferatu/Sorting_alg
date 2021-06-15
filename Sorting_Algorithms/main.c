#include "sorting.h"



int main(void){
    List *arr=(List*) malloc(sizeof(List));
    buildList(arr); 
    int i, j;
    tpElem x;
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &x);
       j = insert(arr, x);
       if(j == Error)
        {    
            printf("Error!\n");
            break;
        }    
    }
    printList(arr);
    CountingSort(arr);
    printList(arr);
   return 0;
}
