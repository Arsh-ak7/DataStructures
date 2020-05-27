#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
int temp=*a;
*a=*b;
*b=temp;
}

void MinHeapify(int *arr, int n, int i){
int smallest=i;
int l=2*i+1;
int r=2*i+2;
if(l<n&&arr[smallest]>arr[l])
    smallest=l;
if(r<n&&arr[smallest]>arr[r])
    smallest=r;
if(smallest!=i){
    swap(&arr[smallest],&arr[i]);
    MinHeapify(arr,n,smallest);
}
}

void build_min_heap(int *arr,int size) {
  int i;
  for(i=size/2; i>=1; i--) {
    MinHeapify(arr,size,i);
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
build_min_heap(arr,size);
for(int i=0;i<size;i++)
    printf("%d\t",arr[i]);
}
