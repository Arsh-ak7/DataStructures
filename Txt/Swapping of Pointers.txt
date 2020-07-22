# include <stdio.h>

typedef int * intptr;

int fact(int n) {
    printf("Function: %s, Line: %d, &n = %p, n = %d\n", __func__, __LINE__, &n, n);
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

void swap(intptr m, intptr n) {
    int t = *m;
    *m = *n;
    *n = t;
}


void swap_pointers(intptr *m, int **n) {
    intptr t = *m;
    *m = *n;
    *n = t;
}

int main() {
    int n = 5;
    printf("Function: %s, Line: %d, &n = %p, n = %d\n", __func__, __LINE__, &n, n);
    printf("%d\n", fact(n));
    int a = 6, b = 7;
    swap(&a, &b);
    //

    int arr1[100] = {1, 2, 3};
    int arr2[100] = {5, 6, 7};
    int *pa = arr1, *pb = arr2;
    char *phello = "Hello, ", *pworld = "world!";
    swap_pointers(&pa, &pb);
    printf("%d %d\n", pa[0], pb[0]);

    const int x = 6;
    int *px = &x;
    *px = 7;

    int j = 7;
    *(&j) = 8;
}
