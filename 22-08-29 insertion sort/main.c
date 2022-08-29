//#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int size){
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main(){
    int arr[] = { 15, 10, 16, 7, 8 };
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    printArray(arr, size);
}
