#include <stdio.h> 
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j;
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
  
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int arr[] = {6, 31, 72, 2, 41,87}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 

//Time Complexity -> O(n^2) , Space -> O(1), Unstable , inplace.

void stableSelectionSort(int a[], int n) 
{
    for (int i = 0; i < n - 1; i++)  
    {
        int min = i; 
        for (int j = i + 1; j < n; j++) 
            if (a[min] > a[j]) 
                min = j;
        int key = a[min]; 
        while (min > i)  
        { 
            a[min] = a[min - 1]; 
            min--; 
        } 
        a[i] = key; 
    } 
} 