# include <stdio.h>
# include <stdlib.h>

# define GENERIC

# ifdef GENERIC
    # define Data void *
    # define DataDefaultValue NULL
# else
    # define Data int
    # define DataDefaultValue 0
# endif

typedef struct node {
    struct node *prev;
    Data data;
    struct node *next;
} Node;

Node *newNode(Node *prev, Data data, Node *next) {
    Node *pnode = (Node *) calloc(1, sizeof(Node));
    pnode->prev = prev;
    pnode->data = data;
    pnode->next = next;
    return pnode;
}

typedef struct student {
    int roll;
    char *name;
    int marks;
} Student;

Student *newStudent(int roll, char *name, int marks) {
    Student *pstudent = (Student *) calloc(1, sizeof(Student));
    pstudent->roll = roll;
    pstudent->name = name;
    pstudent->marks = marks;
    return pstudent;
}

void printStudent(void *pvdata) {
    Student *pstudent = (Student *) pvdata;
    printf("Roll : %d\n", pstudent->roll );
    printf("Name : %s\n", pstudent->name );
    printf("Marks: %d\n", pstudent->marks);
}


void addFirst(Node **ppnode, Data data) {
    *ppnode = newNode(NULL, data, *ppnode);
    if ((*ppnode)->next) {
        (*ppnode)->next->prev = *ppnode;
    }
}

void addLast(Node **ppnode, Data data) {
    if (*ppnode == NULL) {
        return addFirst(ppnode, data);
    }
    Node *pnode = *ppnode;
    while (pnode->next) {
        pnode = pnode->next;
    }
    pnode->next = newNode(pnode, data, NULL);
}

Data removeFirst(Node **ppnode) {
    if (*ppnode == NULL) {
        fprintf(stderr, "Failed to remove: the list is empty!\n");
        return DataDefaultValue;
    }
    Data data = (*ppnode)->data;
    Node *pnode = *ppnode;
    *ppnode = pnode->next; // *ppnode = (*ppnode)->next;
    free(pnode);
    if (*ppnode != NULL) {
        (*ppnode)->prev = NULL;
    }
    return data;

}

Data removeLast(Node **ppnode) {
    if (*ppnode == NULL || (*ppnode)->next == NULL) {
        return removeFirst(ppnode);
    }
    Node *pnode = *ppnode;
    while (pnode->next) {
        pnode = pnode->next;
    }
    pnode->prev->next = NULL;
    Data data = pnode->data;
    free(pnode);
    return data;
}

# ifdef GENERIC
    void printList(Node *pnode, void (*printData)(void *)) {
# else
    void printList(Node *pnode) {
# endif // GENERIC
    Node *plast = NULL;
    printf("Forward:\n");
    while (pnode != NULL) {
        # ifdef GENERIC
            printData(pnode->data);
            printf("--->\n");
        # else
            printf("%d -> ", pnode->data);
        # endif
        plast = pnode;
        pnode = pnode->next;
    }
    printf("NULL\n"
           "Backward:\n");
    while (plast) {
        # ifdef GENERIC
            printData(plast->data);
            printf("--->\n");
        # else
            printf("%d -> ", plast->data);
        # endif // GENERIC
        plast = plast->prev;
    }
    printf("NULL\n");
}

int main() {
    # ifdef GENERIC
    Node *list = NULL;
    addFirst(&list, (void *) newStudent(209, "Ujjwal", 32));
    addFirst(&list, (void *) newStudent(190, "Shivi",  34));
    printList(list, printStudent);
    /*
    Node *plist_fac = NULL;
    addFirst(&plist_fac, (void *) newFaculty(98, "Name", "DS"));
    printList(list, printFculty);
    */
    # else
    Node *list = NULL;
    addFirst(&list, 1);
    addFirst(&list, 2);
    printList(list);
    # endif
}
