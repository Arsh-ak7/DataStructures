# include <stdio.h>
# include <stdlib.h>

# define Data int
# define dataDefaultValue 0

typedef struct stack {
    int top1, top2;
    unsigned int capacity;
    Data *array;
} Stack;

Stack *newStack(const unsigned int capacity) {
    Stack *pstack = (Stack *) calloc(1, sizeof(Stack));
    pstack->top1 = -1;
    pstack->top2 = capacity;
    pstack->capacity = capacity;
    pstack->array = (int *) calloc(capacity, sizeof(int));
    return pstack;
}

int isEmpty1(Stack *pstack) {
    return pstack->top1 == -1;
}

int isEmpty2(Stack *pstack) {
    return pstack->top2 == pstack->capacity;
}

int isFull(Stack *pstack) {
    return pstack->top1 + 1 == pstack->top2;
}

int push1(Stack *pstack, Data data) {
    if (isFull(pstack)) {
        return -1;
    }
    pstack->array[++(pstack->top1)] = data;
    return 0;
}

int push2(Stack *pstack, Data data) {
    if (isFull(pstack)) {
        return -1;
    }
    pstack->array[--(pstack->top2)] = data;
    return 0;
}

Data pop1(Stack *pstack) {
    if (isEmpty1(pstack)) {
        fprintf(stderr, "Stack 1 Underflow!\n");
        return dataDefaultValue;
    }
    return pstack->array[(pstack->top1)--];
}

Data pop2(Stack *pstack) {
    if (isEmpty2(pstack)) {
        fprintf(stderr, "Stack 2 Underflow!\n");
        return dataDefaultValue;
    }
    return pstack->array[(pstack->top2)++];
}

Data peek1(Stack *pstack) {
    if (isEmpty1(pstack)) {
        fprintf(stderr, "Stack 1 Underflow!\n");
        return dataDefaultValue;
    }
    return pstack->array[(pstack->top1)];
}

Data peek2(Stack *pstack) {
    if (isEmpty2(pstack)) {
        fprintf(stderr, "Stack 2 Underflow!\n");
        return dataDefaultValue;
    }
    return pstack->array[(pstack->top2)];
}


int main(int argc, char **argv) {
    return 0;
}

