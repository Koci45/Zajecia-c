#include <stdio.h>
#include <math.h>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void copyArray(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void printAllPermutations(int arr[], int size, int start)
{
    int temp;   
    
    if(size == 1){
        printf("%d", arr[0]);
    }

    if(start == 0){
        printArray(arr, size);
        printf("\n");
    }

    if(start < size - 1){
        
        for(int i = start; i < size; i++)
        {
            int *copy = malloc(size * sizeof(int));
            copyArray(arr, copy, size);
            temp = copy[start];
            copy[start] = copy[i];
            copy[i] = temp;
            if(i != start)
            {
                printArray(copy, size);
                printf("\n");       
            }
            printAllPermutations(copy, size, start+1);
        }
    } 
}


int main() {

    int arr[] = {1,2,3,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printAllPermutations(arr, size, 0);

    return 0;
}
