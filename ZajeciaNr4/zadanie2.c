#include <stdio.h>
#include <math.h>

void bubbleSort(int arr[], int size)
{
    int swapped = 0;
    int temp;

    for(int i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            swapped = 1;
            }
        }

        if(swapped == 0)
        {
        break;
        }
    }   
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int binarySearch(int arr[], int left, int right, int goal){
    if(left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == goal)
        {
             return mid;
        }     

        if (arr[mid] > goal)
        {
            return binarySearch(arr, left, mid - 1, goal);
        }
                 
        return binarySearch(arr, mid + 1, right, goal);
    }
    return -1;
}

int main() {

    int arr[] = { 14, 57, 39, 4, 72, 91, 23, 66, 30, 53, 79, 15, 86, 11, 50, 64, 25, 93, 73, 71, 12, 63, 3, 27, 89, 56, 7, 98, 61, 32, 40, 35, 18, 31, 68, 8, 60, 20, 58, 45, 94, 16, 84, 2, 80, 42, 19, 37, 95, 48, 6, 28, 36, 85, 65, 74, 17, 97, 67, 96, 21, 70, 46, 83, 75, 13, 77, 34, 92, 10, 29, 9, 87, 78, 54, 55, 69, 33, 41, 81, 38, 24, 0, 59, 1, 22, 26, 90, 47, 51, 62, 76, 43, 88, 49, 82, 5, 52, 44, 99, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    int index = binarySearch(arr, 0, size, 10);
    printf("%d", index);

    return 0;
}
