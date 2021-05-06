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
#include "openssl/sha.h"
#include <random>

using namespace std;

HashTable::HashTable(int size) 
{ 
    tableLen = nextPrime(size*2); 
    numElm = 0; 
    cap = size; 
    Node n = Node();
    n.str = "";
    n.frequency = -1;
    n.heapElm = nullptr;
    htarr.resize(tableLen, n); 
}

void HashTable::insert(string str)
{
    cout << "Got to insert" << endl;
    int i = search(str);
    cout << "After Search i: " << i << " Heap Elm " << htarr.at(i).heapElm << endl;
    if (htarr.at(i).heapElm != nullptr)
    {
        cout << "Existing node found" << i << "Freq: " << htarr.at(i).heapElm->frequency  << endl;
        htarr.at(i).heapElm->frequency = htarr.at(i).heapElm->frequency + 1;
        cout << "iterated freq" << endl;
        return;
    }
    if (numElm == cap)
    {
    	deleteElm(h.getRootString());
        insert(str);
        return;
    }

    Node n = Node();
    n.str = str;
    n.heapElm = h.insert(str);
    htarr.at(i) = n;
    numElm++;
    return;
}

void HashTable::deleteElm(string s){
    int i = search(s);
    htarr.at(i).heapElm = nullptr;
    numElm--;
}

int HashTable::search(string s){
    cout << "got to search" << endl;
    int hash = stoi(sha256(s));
    cout << "This is the hash" << hash << endl;
    int index = hash % tableLen;
    int counter = 1;
    cout << "Index: " << index << endl;
    while(htarr.at(index).str.compare(s) && htarr.at(index).heapElm != nullptr){
        index = (hash + counter*counter)%tableLen;
        cout << "search index: " << index << endl;
        counter++;
    }
    cout << "After loop index " << index << endl;
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

//returns a hash given a string
string HashTable::sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX c;
    SHA256_Init(&c);
    SHA256_Update(&c, str.c_str(), str.size());
    SHA256_Final(hash, &c);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void HashTable::writeHeap(string file) 
{ 
    cout << "Made it to writeHeap" << endl;
    int freq;
    ofstream writeFile;
    writeFile.open(file, ios::app);
    if (writeFile.is_open()){
       while(h.getHeapSize() > 2){
            cout << "started writing" << endl;
            //freq = h.writeMin();
            freq = htarr.at(search(h.getRootString())).heapElm->frequency;
            cout << "Got frequency" << endl;
            writeFile << "STRING" << h.getRootString() << ":" << "Frequency" << freq << ",";
            h.deleteMin();
       }
       if(h.getHeapSize() == 2)
       {
            freq = htarr.at(search(h.getRootString())).heapElm->frequency;
            cout << "Got frequency" << endl;
            writeFile << "STRING" << h.getRootString() << ":" << "Frequency" << freq;
            h.deleteMin();
       }
    }else cout << "no file was provided to write to" << endl;
    writeFile.close();  
}
