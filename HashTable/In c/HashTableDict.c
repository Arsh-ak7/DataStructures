#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct elt{
    char* key;
    char* value;
    struct elt* next;
};

struct dict{
    int size;
    int count;
    struct elt** table;
};

#define INITIAL_SIZE 20
#define MAX_LOAD_FACTOR 1
#define GROWTH_FACTOR 2

struct dict* intDictCreate(int size){
   struct dict* d=malloc(sizeof(struct dict));
    d->size=size;
    d->count=0;
    d->table=malloc(sizeof(struct elt*)*d->size);
    for(int i=0;i<d->size;i++)
        d->table[i]=0;
    return d;
}

struct dict* DictCreate(){
return intDictCreate(INITIAL_SIZE);
}

void DeleteDict(struct dict* d){
    struct elt* e;
    struct elt* next;//Two Pointers needed as one moves through array and other through list
    for(int i=0;i<d->size;i++){
        for(e=d->table[i];e!=0;e=next){
            next=e->next;
            free(e->key);
            free(e->value);
            free(e);
        }
    }
    free(d->table);
    free(d);
}

int charAt(char* s,int n){
    for(int i=0;s[i]!='\0';++i){
        if(i==n)
        return s[i];
    }
}

unsigned long hashFunction(char* s){
    unsigned long hash=0;
    for(int i=0;i<strlen(s);i++)
        hash=hash*17 + charAt(s,i);
}

void insertDict(struct dict*,char*,char*);

void Grow(struct dict* d){
    struct dict* d2;
    struct dict swap;
    struct elt* e;
    d2=intDictCreate(d->size*GROWTH_FACTOR);
    for(int i=0;i<d->size;i++){
        for(e=d->table[i];e!=0;e=e->next){
            insertDict(d2,e->key,e->value);
        }
    }
    swap=*d;
    *d=*d2;
    *d2=swap;
    DeleteDict(d2);
}

void insertDict(struct dict* d,char* key, char* value){
    struct elt* e=malloc(sizeof(*e));
    unsigned long hashval=hashFunction(key)%d->size;
    e->key=strdup(key);
    e->value=strdup(value);
    e->next=d->table[hashval];
    d->table[hashval]=e;
    d->count++;
    if(d->count>=d->size*MAX_LOAD_FACTOR)
        Grow(d);
}

char* SearchDict(struct dict *d, char* key){
struct elt* e;
unsigned long hashval=hashFunction(key)%d->size;
for(e=d->table[hashval];e!=0;e=e->next){
    if(!strcmp(e->key,key))
        return e->value;
    }
    return 0;
}

void DeleteEleDict(struct dict* d, char* key){
    struct elt **prev;
    struct elt *e;
    unsigned long hashval=hashFunction(key)%d->size;
    for(prev=&(d->table[hashval]);*prev!=0;prev=&((*prev)->next)){
        if(!strcmp((*prev)->key,key)){
            e=*prev;
            *prev=e->next;
            free(e->key);
            free(e->value);
            free(e);

            return;
        }
    }
}

int main(){
    struct dict* d=DictCreate();
    insertDict(d,"foo","hello World");
    puts(SearchDict(d,"foo"));

}
