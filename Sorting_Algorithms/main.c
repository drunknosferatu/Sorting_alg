#include "sorting.h"
#include <time.h>



typedef void (*algorithm)(List *);              // Ponteiro para os algoritmos de ordenacao
                                                // exceto quicksort, pois este tem mais parametros que os outros

typedef void (*quick)(List *, long, long);      // Ponteiro para o quicksort



double MeasureRuntime(algorithm alg, List l);   // Mede o tempo de execussão empirico de um algoritmo de ordenacao


double QuickMeasureRuntime(quick alg, List l);   // Mede o tempo de execussão empirico do quicksort



int main(void){
    List arr;
    int k;
    for(int method=1;method<6;method++)
    {
	for(long i=1000, i<=maxSize,i*=10)
	{
		buildList(&arr);
		srand(time(NULL));
		for(long j = 0; j < i; j++)
        	{
            		k = insert(&arr, rand() % (maxSize - 1));
            		if(k == Error)
                		break;
        	}
		switch(method)
		{	
			case 1:
 	       			printf("%.10lf\n", MeasureRuntime(HeapSort, arr));
				printf("%.10lf\n", MeasureRuntime(HeapSort, arr));
				for(long l = 0; l < (arr->length)/2 ; l++) swap(&arr, l, (arr->length - 1) - l);
				printf("%.10lf\n", MeasureRuntime(HeapSort, arr);
				break;
			case 2:
        			printf("%.10lf\n", MeasureRuntime(RadixSort, arr));
				printf("%.10lf\n", MeasureRuntime(RadixSort, arr));
				for(long l = 0; l < (arr->length)/2 ; l++) swap(&arr, l, (arr->length - 1) - l);
				printf("%.10lf\n", MeasureRuntime(RadixSort, arr);
				break;
			case 3:
        			printf("%.10lf\n", MeasureRuntime(BubbleSort, arr));
				printf("%.10lf\n", MeasureRuntime(BubbleSort, arr));
				for(long l = 0; l < (arr->length)/2 ; l++) swap(&arr, l, (arr->length - 1) - l);
				printf("%.10lf\n", MeasureRuntime(BubbleSort, arr);
				break;
			case 4:
        			printf("%.10lf\n", MeasureRuntime(OptimizedBubbleSort, arr));
				printf("%.10lf\n", MeasureRuntime(OptimizedBubbleSort, arr));
				for(long l = 0; l < (arr->length)/2 ; l++) swap(&arr, l, (arr->length - 1) - l);
				printf("%.10lf\n", MeasureRuntime(OptimizedBubbleSort, arr);
				break;
			case 5:
        			printf("%.10lf\n", MeasureRuntime(QuickSort, arr));
				printf("%.10lf\n", MeasureRuntime(QuickSort, arr));
				for(long l = 0; l < (arr->length)/2 ; l++) swap(&arr, l, (arr->length - 1) - l);
				printf("%.10lf\n", MeasureRuntime(QuickSort, arr);
				break;
		}
		destroyList(&arr);
    	}
     }
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
