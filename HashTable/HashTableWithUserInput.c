#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define TABLE_SIZE 10
#define MAX_SIZE 256

struct person{
	char* name;
	int num;
	struct person* next;
};

struct person* HashTable[TABLE_SIZE];

void initTable() {
	for (int i = 0; i < TABLE_SIZE; ++i)
		HashTable[i] = NULL;

}

void printTable() {
	for (int i = 0; i < TABLE_SIZE; ++i) {
		if (HashTable[i] == NULL)
			printf("--NULL--\n");
		else {
			struct person* temp = HashTable[i];
			while (temp != NULL) {
				printf("%s %d->", temp->name, temp->num);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}

int hashFunction(int num) {
	return (num * 7) % 10;
}

void insIntoTable(struct person* p) {
	if (p == NULL) printf("WA");
	struct person* temp = p;
	int index = hashFunction(p->num);
	temp->next = HashTable[index];
	HashTable[index] = p;
}

struct person* tableLookUp(int nume) {
	int index = hashFunction(nume);
	struct person* temp = HashTable[index];
	while (temp != NULL) {
		if (temp->num == nume) {
			return temp;
			break;
			}
		temp = temp->next;

		}
	}


void deleteElement(int num) {
	int index = hashFunction(num);
	struct person* temp = HashTable[index];
	struct person* prev = NULL;
	if (temp->num == num) {
		HashTable[index] = temp->next;
		free(temp);
		return;
	}
	while (temp != NULL) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)return;//Not found
	prev->next = temp->next;
	free(temp);
}

void remove_new_line(char* string)
{
	size_t length = strlen(string);
	if ((length > 0) && (string[length - 1] == '\n'))
	{
		string[length - 1] = '\0';
	}
}

int main() {
	initTable();
	int n;
	printf("ENTER Number: ");
	scanf("%d", &n);
	getchar();
	/*for(int i=0;i<n;i++){
		struct person p;
		char str[256];
		printf("Enter Value: ");
		fgets(str,256,stdin);
		remove_new_line(str);
		int key;
		printf("Enter Key: ");
		scanf("%d",&key);
		getchar();
		strcpy(p.name,str);
		p.num=key;
		insIntoTable(&p);
	}*/
	//Agar aise neeche se user input le rhe to last enterd data hi fill kr rha table
        struct person* p=NULL;
	for (int i = 0; i < n; ++i) {
		p = (struct person*)malloc(sizeof(struct person));
		char* str=(char*)malloc(sizeof(char)*16);
		printf("Enter value: ");
		scanf("%[^\n]%*c", str);
		int key;
		printf("Enter the key: ");
		scanf("%d", &key);
		getchar();
		p->name=str;
		p->num = key;
		insIntoTable(p);
	}
	//Ye neeche wala works fine
	/*person p;
	p.name="asd";
	p.num=2;
	insIntoTable(&p);
	person p1;
	p1.name="a";
	p1.num=8;
	insIntoTable(&p1);*/
	printTable();
	int lp;
	printf("Enter Num:");
	scanf("%d", &lp);
	if (tableLookUp(lp) == NULL) {
		printf("NOT FOUND\n");
	}
	else {
		printf("%s\n", tableLookUp(lp)->name);
	}

}
