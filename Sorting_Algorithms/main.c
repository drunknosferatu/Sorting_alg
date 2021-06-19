#include "sorting.h"
#include <time.h>



typedef void (*algorithm)(List *);              // Ponteiro para os algoritmos de ordenacao
                                                // exceto quicksort, pois este tem mais parametros que os outros

typedef void (*quick)(List *, long, long);      // Ponteiro para o quicksort



double MeasureRuntime(algorithm alg, List l);   // Mede o tempo de execussão empirico de um algoritmo de ordenacao


double QuickMeasureRuntime(quick alg, List l);   // Mede o tempo de execussão empirico do quicksort



int main(void){
    
    
   /*******************TESTE****************************************************
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
    //RadixSort(&arr);
    QuickSort(&arr, 0, arr.length - 1);
    printList(arr);
    destroyList(&arr);
    ***************************************************************************/
    /***************************TESTE*******************************************
    List arr;
    
    for(long i = 1000; i <= maxSize; i *= 10)
    {
        buildList(&arr);
        srand(time(NULL));
        for(long j = 0; j < i; j++)
        {
            int k = insert(&arr, rand() % (maxSize - 1));
            if(k == Error)
                break;
        }
        printf("%.10lf\n", MeasureRuntime(HeapSort, arr));
        destroyList(&arr);
    }
     */
   return 0;
}



double MeasureRuntime(algorithm alg, List l)
{
    clock_t mTime;
    mTime = clock();
    alg(&l);
    mTime = clock() - mTime;
    return (double) mTime * 1000.0 / (double) CLOCKS_PER_SEC;
}


double QuickMeasureRuntime(quick alg, List l)
{
    clock_t mTime;
    mTime = clock();
    alg(&l, 0, l.length - 1);
    mTime = clock() - mTime;
    return (double) mTime * 1000.0 / (double) CLOCKS_PER_SEC;
}
