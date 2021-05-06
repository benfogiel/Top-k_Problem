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
    n.heapElm = 0;
    htarr.resize(tableLen, n); 
}

void HashTable::insert(string s)
{

    int i;
    i = search(s);
    if (htarr.at(i).heapElm != 0)
    {
        htarr.at(i).heapElm->frequency = htarr.at(i).heapElm->frequency + 1;
        return;
    }
    if (numElm == cap)
    {
    	deleteElm(h.getRootString());
        insert(s);
        return;
    }

    Node n = Node();
    n.str = s;
    n.frequency = 0;
    n.heapElm = h.insert(s);
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
    bool iterate = true;
    stringstream hashstr(sha256(s));
    int hash = 0;
    hashstr >> hash;
    int index = hash % tableLen;
    int counter = 1;
    while(iterate){
        if (htarr.at(index).str.compare(s) == 0) break;
        if (htarr.at(index).frequency == -1) break;
        index = (hash + counter*counter)%tableLen;
        counter++;
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
    h.writeMin(file);
}