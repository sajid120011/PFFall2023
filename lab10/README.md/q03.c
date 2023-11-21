#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isPrime(int num) 
{
    if (num < 2) 
	{
        return false;
    }
    for (int i = 2; i * i <= num; ++i) 
	{
        if (num % i == 0) 
		{
            return false;
        }
    }
    return true;
}
void fillWithPrimes(int** array, int rows, int cols) 
{
    int currentNum = 2; 
    for (int i = 0; i < rows; ++i) 
	{
        for (int j = 0; j < cols; ++j) 
		{
            while (!isPrime(currentNum)) 
			{
                currentNum++;
            }
            array[i][j] = currentNum;
            currentNum++;
        }
    }
}
int main() 
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int** primeArray = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) 
	{
        primeArray[i] = (int*)malloc(cols * sizeof(int));
    }
    fillWithPrimes(primeArray, rows, cols);
    printf("2D Array with Consecutive Prime Numbers:\n");
    for (int i = 0; i < rows; ++i) 
	{
        for (int j = 0; j < cols; ++j) 
		{
            printf("%d\t", primeArray[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; ++i) 
	{
        free(primeArray[i]);
    }
    free(primeArray);
    return 0;
}
