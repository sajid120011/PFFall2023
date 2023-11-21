#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 800
#define N 800
void multiplyAndDivide(int** array, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
	{
        for (int j = 0; j < cols; ++j) 
		{
            array[i][j] = (array[i][j] * 3) / 2;
        }
    }
}
int** createArraySingleMalloc(int rows, int cols) 
{
    int** array = (int**)malloc(rows * sizeof(int*) + rows * cols * sizeof(int));
    if (array == NULL) 
	{
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; ++i) 
	{
        array[i] = (int*)(array + rows) + i * cols;
    }
    return array;
}
int** createArrayDoubleMalloc(int rows, int cols) 
{
    int** array = (int**)malloc(rows * sizeof(int*));
    if (array == NULL) 
	{
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; ++i) 
	{
        array[i] = (int*)malloc(cols * sizeof(int));
        if (array[i] == NULL) 
		{
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
    }
    return array;
}
void freeArray(int** array, int rows) 
{
    for (int i = 0; i < rows; ++i) 
	{
        free(array[i]);
    }
    free(array);
}

int main() 
{
    clock_t start, end;
    int** arraySingleMalloc100 = createArraySingleMalloc(100, 100);
    start = clock();
    multiplyAndDivide(arraySingleMalloc100, 100, 100);
    end = clock();
    printf("Time for 100x100 Single Malloc: %f seconds\n", ((double)end - start) / CLOCKS_PER_SEC);
    freeArray(arraySingleMalloc100, 100);
    int** arrayDoubleMalloc100 = createArrayDoubleMalloc(100, 100);
    start = clock();
    multiplyAndDivide(arrayDoubleMalloc100, 100, 100);
    end = clock();
    printf("Time for 100x100 Double Malloc: %f seconds\n", ((double)end - start) / CLOCKS_PER_SEC);
    freeArray(arrayDoubleMalloc100, 100);
    // Timing for a 500x500 and 800x800 array
    // ... (similar procedure as above)
    return 0;
}
