#include <stdio.h>
#include<string.h>
#include<stdbool.h>

#define TABLE_SIZE 10
#define MAX_SIZE 256

typedef struct {
	char* name;
	int num;
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
		else
			printf("%s\t%d\n", HashTable[i]->name,HashTable[i]->num);
	}
}

int hashFunction(int num) {
	return (num * 7) % 13;
}

void insIntoTable(person* p) {
	if (p == NULL) printf("WA");
	int index = hashFunction(p->num);
	for (int i = 0; i < TABLE_SIZE; ++i) {
		int trym = (index + i) % TABLE_SIZE;
		if (HashTable[trym] == NULL) {
			HashTable[trym]=p;
			break;
		}
	}
}

person* tableLookUp(int num) {
	int index = hashFunction(num);
	for (int i = 0; i < TABLE_SIZE; ++i) {
		int trym = (index + i) % TABLE_SIZE;
		if (HashTable[trym] != NULL && HashTable[trym]->num == num){
			return HashTable[trym];
		}
	}
	return NULL;
}

void deleteElement(int num){
    int index=hashFunction(num);
    for(int i=0;i<TABLE_SIZE;++i){
        int trym=(index+i)%TABLE_SIZE;
        if(HashTable[trym]!=NULL&&HashTable[trym]->num==num)
            HashTable[trym]=NULL;
    }
}

int main() {
	initTable();
	person p = {"nnb",7 };
	insIntoTable(&p);
	person p1 = {"nnw",8 };
	insIntoTable(&p1);
	person p2 = {"nn",9 };
	insIntoTable(&p2);
	person p3 = {"nqb",17 };
	insIntoTable(&p3);
	person p4 = {"nab",12 };
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
    deleteElement(9);
    printTable();
}
