#include "sorting.h"
#include <time.h>



typedef void (*algorithm)(List *);              // Ponteiro para os algoritmos de ordenacao
                                                // exceto quicksort, pois este tem mais parametros que os outros

typedef void (*quick)(List *, long, long);      // Ponteiro para o quicksort



double* MeasureRuntime(algorithm alg, List l);   // Mede o tempo de execussão empirico de um algoritmo de ordenacao


double* QuickMeasureRuntime(quick alg, List l);   // Mede o tempo de execussão empirico do quicksort



int main(void){
    List arr;
    int k;
    double* results = malloc(3 * sizeof(double));
    for(int method = 1; method < 2 ; method++)
    {
	for(long i = 1000; i <= maxSize; i *= 10)
	{
		buildList(&arr);
		srand(time(NULL));
		for(long j = 0; j < i; j++)
        	{
            		k = insert(&arr, rand() % (i - 1));
            		if(k == Error)
                		break;
        	}
		switch(method)
		{	
			case 1:
				results = MeasureRuntime(HeapSort, arr);
				break;
			case 2:
				results = MeasureRuntime(BubbleSort, arr);
				break;
			case 3:
				results = QuickMeasureRuntime(QuickSort, arr);
				break;
			case 4:
        			results = MeasureRuntime(OptimizedBubbleSort, arr);
				break;
			case 5:
				results = MeasureRuntime(RadixSort, arr);
				break;
		}
		destroyList(&arr);
		printf("Time at magnitude %ld for Method number %d:\n", i, method); 
		printf("Random: %.10lf\n", results[0]);
		printf("Sorted: %.10lf\n", results[1]);
		printf("Inverted: %.10lf\n\n", results[2]);
    	}
     }
    free(results);
    return 0;
}



double* MeasureRuntime(algorithm alg, List l)
{
    clock_t mTime;
    double *results = (double*) malloc(3 * sizeof(double));
    mTime = clock();
    alg(&l);
    results[0] = (double) (clock() - mTime) * 1000.0 / (double) CLOCKS_PER_SEC;
    mTime = clock();
    alg(&l);
    results[1] = (double) (clock() - mTime) * 1000.0 / (double) CLOCKS_PER_SEC;
    for(long i = 0; i < (l.length)/2 ; i++) swap(&l, i, (l.length - 1) - i);
    mTime = clock();
    alg(&l);
    results[2] = (double) (clock() - mTime) * 1000.0 / (double) CLOCKS_PER_SEC;
    return results;
}


double* QuickMeasureRuntime(quick alg, List l)
{
    clock_t mTime;
    double *results = (double*) malloc(3 * sizeof(double));
    mTime = clock();
    alg(&l, 0, l.length - 1);
    results[0] = (double) (clock() - mTime) * 1000.0 / (double) CLOCKS_PER_SEC;
    mTime = clock();
    alg(&l, 0, l.length - 1);
    results[1] = (double) (clock() - mTime) * 1000.0 / (double) CLOCKS_PER_SEC;
    for(long i = 0; i < (l.length)/2 ; i++) swap(&l, i, (l.length - 1) - i);
    mTime = clock();
    alg(&l, 0, l.length - 1);
    results[2] = (double) (clock() - mTime) * 1000.0 / (double) CLOCKS_PER_SEC;
    return results;
}
