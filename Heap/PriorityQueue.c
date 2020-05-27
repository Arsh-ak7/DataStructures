#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int heap_size = 0;
int arr_size = 20;

void Maxheapify(int* arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l<n && arr[l]>arr[largest])
        largest = l;
    if (r<n && arr[r]>arr[largest])
        largest = r;
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        Maxheapify(arr, n, largest);
    }
}

void buildMaxHeap(int* arr) {
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        Maxheapify(arr, heap_size, i);
    }
}

int maximum(int* arr) {
    return arr[0];
}
//Down program is like Pop
int extractMax(int* arr) {
    int maxm = arr[0];
    arr[0] = arr[heap_size-1];
    heap_size--;
    Maxheapify(arr, heap_size, 0);
    return maxm;
}

int get_parent(int* arr, int index) {
    if ((index > 1) && (index < arr_size)) {
        return index / 2;
    }
    return -1;
}

void increaseKey(int* arr, int index, int key) {
    arr[index] = key;
    /*while((index>1) && (arr[get_parent(arr, index)] < arr[index])) {
        swap(&arr[index], &arr[get_parent(arr, index)]);
        index = get_parent(arr, index);
      }*/
    for (int i = heap_size / 2 - 1; i >= 0; i--)
        Maxheapify(arr, heap_size, i);

}

void decreasekey(int* arr, int index, int key) {
    arr[index] = key;
    Maxheapify(arr, heap_size, index);
}

void insertkey(int* arr, int key) {
    heap_size++;
    increaseKey(arr, heap_size - 1, key);
}

void printQueue(int* arr) {
    for (int i = 0; i < heap_size; ++i)
        printf("%d ", arr[i]);
}
int main() {
    int arr[20];
    insertkey(arr, 7);
    insertkey(arr, 8);
    insertkey(arr, 5);
    insertkey(arr, 6);
    insertkey(arr, 9);
    insertkey(arr, 2);
    insertkey(arr, 4);
    insertkey(arr, 1);
    printQueue(arr);
    printf("\n%d\n", extractMax(arr));
    printQueue(arr);
    printf("\n%d\n", extractMax(arr));
    printQueue(arr);
}
