#include <stdio.h>
void printArray(void* array, size_t size, int dataType) 
{
    switch (dataType) 
	{
        case 1: 
            for (size_t i = 0; i < size / sizeof(int); ++i) 
			{
                int value = *((int*)((char*)array + i * sizeof(int)));
                printf("%d ", value);
            }
            break;
        case 2: 
            for (size_t i = 0; i < size / sizeof(double); ++i) 
			{
                double value = *((double*)((char*)array + i * sizeof(double)));
                printf("%lf ", value);
            }
            break;
        default:
            printf("Invalid data type\n");
            return;
    }
    printf("\n");
}

int main() 
{
	int num1,i;
	printf("Enter number of rows of array:");
	scanf("%d",&num1);
    int intArray[num1];
    double doubleArray[num1];
    for(i=0;i<num1;i++)
    {
    	scanf("%d",&intArray[i]);
	}
    for(i=0;i<num1;i++)
    {
    	scanf("%d",&doubleArray[i]);
	}
    size_t intArraySize = sizeof(intArray);
    size_t doubleArraySize = sizeof(doubleArray);
    printf("Printing intArray: ");
    printArray(intArray, intArraySize, 1);
    printf("Printing doubleArray: ");
    printArray(doubleArray, doubleArraySize, 2);
    return 0;
}
