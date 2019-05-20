#include <stdio.h>

int main(void)
{
  printf("Hello World !!!");
  return 1;
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
