# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define Data int
# define DataDefaultValue 0;

typedef struct node {
    Data data;
    struct node *next;
} Node;


Node *newNode(Data data, Node *next) {
    Node *pnode = (Node *) calloc(1, sizeof(Node));
    pnode->data = data;
    pnode->next = next;
    return pnode;
}

void addFirst(Node **ppnode, Data data) {
    *ppnode = newNode(data, *ppnode);
}

Data removeFirst(Node **ppnode) {
    if (*ppnode == NULL) {
        fprintf(stderr, "Exception in %s (%s: %d).\n", __func__, __FILE__, __LINE__);
        return DataDefaultValue;
    }
    Data data = (*ppnode)->data;
    Node *pnode = *ppnode;
    *ppnode = pnode->next;
    free(pnode);
    return data;
}

void printList(Node *pnode) {
    printf("%p -> ", pnode);
    int index = 0;
    while (pnode) {
        printf("(%p, %d, [%d], %p) -> ", pnode, pnode->data, index++, pnode->next);
        pnode = pnode->next;
    }
    printf("NULL\n");
}

void push(Node** ppstack, Data data) {
    addFirst(ppstack, data);
}

Data pop(Node **ppstack) {
    return removeFirst(ppstack);
}

Data peek(Node *pnode) {
    if (pnode == NULL) {
        fprintf(stderr, "Stack Underflow!\n");
        return DataDefaultValue;
    }
    return pnode->data;
}

int isEmpty(Node *pnode) {
    return pnode == NULL;
}

void printStack(Node *pstack) {
    while (pstack) {
        printf("|%d|\n"
               "---\n", pstack->data);
        pstack = pstack->next;
    }
    printf("\n");
}


Data removeLast(Node **ppnode) {
    if (*ppnode == NULL || (*ppnode)->next == NULL) {
        return removeFirst(ppnode);
    }
    Node *pnode = *ppnode, *plast = *ppnode;
    while (pnode->next) {
        plast = pnode;
        pnode = pnode->next;
    }
    Data data = plast->next->data;
    free(plast->next);
    plast->next = NULL;
    return data;
}


void addLast(Node **ppnode, Data data) {
    if (*ppnode == NULL) {
        return addFirst(ppnode, data);
    }
    Node *pnode = *ppnode;
    while (pnode->next) {
        pnode = pnode->next;
    }
    pnode->next = newNode(data, NULL);
}

Node *reverseList3(Node *oldList, Node *newList) {
    if(oldList == NULL) {
        return newList;
    }
    Node *pnode = oldList;
    oldList = oldList->next;
    pnode->next = newList;
    return reverseList3(oldList, pnode);
}

int addAfterData(Node *pnode, Data data, Data key) {//int position
    while (pnode && pnode->data != key) { // &&position--
        pnode = pnode->next;
    }
    if (!pnode) {
        return 1;
    }
    pnode->next = newNode(data, pnode->next);
    return 0;
}

void reverseList1(Node **ppnode) {
    Node *pnode = NULL;
    while (*ppnode) {
        addFirst(&pnode, removeFirst(ppnode));
    }
    *ppnode = pnode;
}

void reverseList2(Node **ppnode) {
    Node *prev = NULL, *current = *ppnode, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *ppnode = prev;
}

int isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/' ) {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

char *infixToPostfix(char *infix) {
    Node *stack = NULL;
    char *postfix = (char *) calloc(strlen(infix) + 1, sizeof(char));
    int i = 0, k = 0;
    for (i = 0, k = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isOperand(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
               postfix[k++] = (char) pop(&stack);
            }
            if (isEmpty(stack)) {
                fprintf(stderr, "Exception: wrong input!\n");
                free(postfix);
                return NULL;
            }
            pop(&stack);
        } else {
            if (c == '^') {
                while (!isEmpty(stack) && precedence(c) < precedence(peek(stack))) {
                    postfix[k++] = (char) pop(&stack);
                }
            } else {
                while (!isEmpty(stack) && precedence(c) <= precedence(peek(stack))) {
                    postfix[k++] = (char) pop(&stack);
                }
            }
            push(&stack, c);
        }
    }
    while (!isEmpty(stack)) {
        postfix[k++] = (char) pop(&stack);
    }
    postfix[k] = '\0';
    return postfix;
}

int evaluatePostfixExpression(char *postfix) {
    Node *stack = NULL;
    for (int i = 0; postfix[i] != '\0'; i++) { // /* off */ /*off
        if (isOperand(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (postfix[i]) {
                case '+' : push(&stack, operand1 + operand2);
                           break;
                case '-' : push(&stack, operand1 - operand2);
                           break;
                case '/' : push(&stack, operand1 / operand2);
                           break;
                case '*' : push(&stack, operand1 * operand2);
                           break;
                case '^' : push(&stack, pow(operand1, operand2));
                           break;
                default  : fprintf(stderr, "I should never see this: %c!\n", postfix[i]);
                           return 0;
            }
        }
    }
    return pop(&stack);
}

void driver1() {
    Node *list = NULL;
    //printList(list);
    //removeFirst(&list);
    //printList(list);
    addFirst(&list, 1);
    printList(list);
    addFirst(&list, 2);
    printList(list);
    addFirst(&list, 3);
    printList(list);
    printf("Removed: %d\n", removeFirst(&list));
    printList(list);
/*
    Node *stack = NULL;
    printStack(stack);
    push(&stack, 1);
    printStack(stack);
    push(&stack, 2);
    printStack(stack);
    push(&stack, 3);
    printStack(stack);
    printf("Popped: %d\n", pop(&stack));
    printStack(stack);
    */
}



void driver2() {
    Node *list = NULL;
    reverseList2(&list);
    printList(list);
    for (int i = 0; i < 3; i++) {
        addFirst(&list, i + 1);
        printList(list);
    }
    printf("%d\n", addAfterData(list, 4, 2));
    printf("DONE\n");
    printList(list);
    reverseList2(&list);
    printf("This line is not executed\n");
    printList(list);
    //addAtPosition(&list, 13, 2);
    //printList(list);
}

int driver3() {
    Node *list = NULL;
    addFirst(&list, 1);
    addFirst(&list, 2);
    addFirst(&list, 3);
    printList(list);
    //printf("Removed: %d\n", removeLast(&list));
    list = reverseList3(list, NULL);
    printList(list);
    //driver2();
    //driver1();
    //char *a = "A+(B*C-(D/E-F)*G)*H";
    //printf("%s\n", infixToPostfix(a));
}

int driver4() {
    char *a = "a*b/c"; //A+(B*C-(D/E-F)*G)*H";
    printf("Infix: %s\n", a);
    printf("Postfix: %s\n", infixToPostfix(a));
    //printf("Evaluated Value: %d", evaluatePostfixExpression(infixToPostfix(a)));
}

int main() {
    /*
    Node *pnode = NULL;
    addFirst(&pnode, 1);
    addFirst(&pnode, 2);
    printList(pnode);*/
    driver4();
}
