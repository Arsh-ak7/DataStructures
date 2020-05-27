#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
int temp=*a;
*a=*b;
*b=temp;
}

void heapify(int *arr, int n,int i){
int largest = i;
int l=2*i+1;
int r=2*i+2;
if(l<n&&arr[l]>arr[largest])
    largest =l;
if(r<n&&arr[r]>arr[largest])
    largest=r;
if(largest!=i){
    swap(&arr[largest],&arr[i]);
    heapify(arr,n,largest);
    }
}

void heapSort(int* arr,int n){
for(int i=n/2-1;i>=0;i--)
    heapify(arr,n,i);

for(int i=n-1;i>=0;i--){
    swap(&arr[0],&arr[i]);
    heapify(arr,i,0);
}
}

int main(){
printf("Enter Number of elements: ");
int size;
scanf("%d",&size);
int* arr=(int*)malloc(sizeof(int)*size);
printf("Enter the elements:");
for(int i=0;i<size;++i)
    scanf("%d",&arr[i]);
heapSort(arr,size);
for(int i=0;i<size;i++)
    printf("%d\t",arr[i]);
}
