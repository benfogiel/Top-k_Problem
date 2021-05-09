//hashTable.cpp
//Author: Benjamin Fogiel

#include "hashTable.h"
#include "minHeap.h"
#include <iostream>
#include<cstring>
#include<iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <random>
#include<cmath>

using namespace std;

HashTable::HashTable(int size) 
{ 
    tableLen = nextPrime(size*2); 
    numElm = 0; 
    cap = size; 
    Node n = Node();
    n.str = "";
    n.frequency = -1;
    n.heapElm = 0;
    htarr.resize(tableLen, n);
    MinHeap* heap = new MinHeap(cap); 
    h = heap;
}

void HashTable::insertHash(string s)
{

    int i;
    i = search(s);

    // if elm already exists
    if (htarr.at(i).heapElm != 0)
    {
        h->iterateFreq(s);
        return;
    }

    htarr.at(i).str = s;
    htarr.at(i).frequency = 1;
    h->insert(&htarr.at(i));
    numElm++;
    return;
}

// deletes elm in Hash Table
void HashTable::deleteElm(string s){
    int index = search(s);
    // The heapElm pointer is the indication of if the bin is empty
    htarr.at(index).heapElm = 0;
    htarr.at(index).str = "";
    numElm--;
}

int HashTable::search(string s){
    int hash = abs(static_cast<int>(std::hash<std::string>{}(s)));
    int index = hash % (tableLen);
    int counter = 1;
    int indexMatch = index;
    while((htarr.at(indexMatch).str.compare(s) != 0) && (counter <= tableLen/2))
    {
        indexMatch = (hash + counter*counter)%(tableLen);
        counter++;
    }
    if (htarr.at(indexMatch).str.compare(s) == 0) return indexMatch;
    counter = 1;
    while((htarr.at(index).heapElm != 0) && (counter <= tableLen/2))
    {
        index = (hash + counter*counter)%(tableLen);
        counter++;
    }
    // If following is true, heap is full
    if (numElm == cap)
    {
        deleteElm(h->getRootString());
        return search(s);
    } 
    return index;
}

bool HashTable::isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}

// Function to return the smallest
// prime number greater than N
int HashTable::nextPrime(int N)
{
    if (N <= 1)
        return 2;
    int prime = N;
    bool found = false;
    while (!found) 
    {
        prime++;
        if (isPrime(prime))
            found = true;
    }
    return prime;
}

void HashTable::writeHeap(string file) 
{
    ofstream writeFile;
    writeFile.open(file, ios::trunc);
    if (writeFile.is_open()){
       while(h->getHeapSize() > 0){
            writeFile << h->getRoot()->str << ":" << h->getRoot()->frequency << ",";
            h->deleteMin();
       }
    }else cout << "no file was provided to write to" << endl;
    writeFile.close(); 
}