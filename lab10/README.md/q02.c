#include <stdio.h>
void swap(void* a, void* b, size_t size) 
{
    unsigned char* byte_a = (unsigned char*)a;
    unsigned char* byte_b = (unsigned char*)b;
    for (size_t i = 0; i < size; ++i) 
    {
        byte_a[i] ^= byte_b[i];
        byte_b[i] ^= byte_a[i];
        byte_a[i] ^= byte_b[i];
    }
}
int main() 
{
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After swap: x = %d, y = %d\n", x, y);
    double a = 3.14, b = 6.28;
    printf("Before swap: a = %lf, b = %lf\n", a, b);
    swap(&a, &b, sizeof(double));
    printf("After swap: a = %lf, b = %lf\n", a, b);
    return 0;
}
