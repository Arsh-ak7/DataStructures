#include <stdio.h>
#include<string.h>
#include<stdbool.h>

#define TABLE_SIZE 10
#define MAX_SIZE 256

typedef struct {
	char* name;
	int num;
	struct person* next;
}person;

person* HashTable[TABLE_SIZE];

void initTable() {
	for (int i = 0; i < TABLE_SIZE; ++i)
		HashTable[i] = NULL;

}

void printTable() {
	for (int i = 0; i < TABLE_SIZE; ++i) {
		if (HashTable[i] == NULL)
			printf("--NULL--\n");
		else{
            person* temp=HashTable[i];
            while(temp!=NULL){
                printf("%s %d->",temp->name,temp->num);
                temp=temp->next;
            }
            printf("\n");
		}
	}
}

int hashFunction(int num) {
	return (num * 7) % 10;
}

void insIntoTable(person* p) {
	if (p == NULL) printf("WA");
	int index = hashFunction(p->num);
	p->next=HashTable[index];
	HashTable[index]=p;
}

person* tableLookUp(int num) {
	int index = hashFunction(num);
	person* temp=HashTable[index];
	while(temp!=NULL){
        temp=temp->next;
        if(temp->num==num){
            return temp;
            break;
        }
	}
}

void deleteElement(int num){
    int index = hashFunction(num);
	person* temp=HashTable[index];
	person* prev=NULL;
	if(temp->num==num){
        HashTable[index]=temp->next;
        free(temp);
        return;
	}
	while(temp!=NULL){
        prev=temp;
        temp=temp->next;
	}
	if(temp==NULL)return;//Not found
	prev->next=temp->next;
	free(temp);
}

int main() {
	initTable();
	person p = {"nnb",7};
	insIntoTable(&p);
	person p1 = {"nnw",78 };
	insIntoTable(&p1);
	person p2 = {"nn",976 };
	insIntoTable(&p2);
	person p3 = {"nqb",174 };
	insIntoTable(&p3);
	person p4 = {"nab",127 };
	insIntoTable(&p4);

	printTable();
	int lp;
	printf("Enter Num:");
	scanf("%d", &lp);
	if(tableLookUp(lp)==NULL){
        printf("NOT FOUND\n");
	}
	else{
        printf("%s\n",tableLookUp(lp)->name);
	}
    deleteElement(127);
    person p5 = {"nnb",127};
	insIntoTable(&p5);
    printTable();
}
