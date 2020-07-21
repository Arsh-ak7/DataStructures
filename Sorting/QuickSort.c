#include<stdio.h> 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
//Taking Last element as pivot
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];  
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); //Sort elements that come before partition
        quickSort(arr, pi + 1, high); //Sort elements after partition
    } 
} 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
} 

int main() 
{ 
    int arr[] = {10, 7, 8, 9, 1, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n-1); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
} 

//Time Complexity -> O(n^2) for worst case , O(nlogn) for best and avg case. Inplace and Unstable.