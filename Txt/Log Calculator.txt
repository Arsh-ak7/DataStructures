# include <stdio.h>
# include <math.h>

int f1(int n) {
    int c = 0;
    for (int i = 2; i <= n; i = 2 * i) {
        printf("i: %d\n", i);
        c++;
    }
    return c;
}

int f2(int n) {
    int c = 0;
    for (int i = n; i > 1; i = i / 2) {
        printf("i: %d\n", i);
        c++;
    }
    return c;
}

int f3(int n) {
    int c = 0;
    for (double i = 2; i <= n; i = i * i) {
        printf("i: %g\n", i);
        c++;
    }
    return c;
}

int main() {
    unsigned int n = 71024;
    printf("c: %d\n", f3(n));//, log(log(n)/log(2))/log(2));
    return 0;
}
