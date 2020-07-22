# include <stdio.h>

//# define Length int
typedef int Length;

typedef struct point {
    int x;
    long double y;
    char c;
} Point;

int main() {
    struct point s;
    Point *ps = &s;

    printf("%p %p %p %d %d %d %d\n", &s, &(s.x), &(s.y), sizeof(s), sizeof(s.x), sizeof(s.y), sizeof(s.c));
    printf("%p %p %p %d %d %d %d", &s, &(s.x), &(s.y), sizeof(ps), sizeof(ps->x), sizeof(ps->y), sizeof(ps->c));
    int j = 5;
    Length i = 5;
    struct point p1, p2;

    s.x;
    ps->x;

    return 0;


}
