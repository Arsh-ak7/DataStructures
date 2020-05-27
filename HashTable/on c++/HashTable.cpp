#include<iostream>
#include<list>
#include<cstring>
using namespace std;

class HashTable{
    private: static const int Size=10;
    list<pair<int , string>> table[Size];

    public: 
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key,string value);
    void removeItem(int key);
    string SearchTable(int key);
    void printTable();                  
};


bool HashTable::isEmpty() const{
    int sum=0;
    for(int i{};i<Size;++i){
        sum+=table[i].size();
    }
    if(sum==0)
    return true;
    else
    return false;
    
}

