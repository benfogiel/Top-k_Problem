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

// Destructor
HashTable::~HashTable(){
	for (int i = 0; i < tableLen; i++){
                free(htarr[i]);
        }
        delete[] htarr;
}

void HashTable::insert(string str)
{
    int i = search(str);
    if (i != -1){
	htarr[i]->heapElm->frequency++;
    	return;
    }
    if (numElm == cap){
    	deleteElm(h.getRootString());
	insert(str);
	return;
    }
    int hash = stoi(sha256(str)); 
    int index = hash % tableLen; 
    int counter = 1;
    while(htarr[index] != NULL){
	index = (hash + counter*counter)%tableLen;
	counter++;
    }
    MinHeap::Node* n = new MinHeap::Node();
    htarr[index] = n;
    n->str = str;
    n->heapElm = h.insert();
    numElm++;
    return;
}

void HashTable::deleteElm(string s){
    int i = search(s);
    free(htarr[i]);
    htarr[i] = NULL;
    numElm--;
}

int HashTable::search(string s){
    int hash = stoi(sha256(s));
    int index = hash % tableLen;
    int counter = 1;
    while(htarr[index]->str != s && counter < tableLen){
        index = (hash + counter*counter)%tableLen;
        counter++;
    }
    if(counter >= tableLen) return -1;
    return index;
}

bool isPrime(int n)
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
int nextPrime(int N)
{
    if (N <= 1)
        return 2;
    int prime = N;
    bool found = false;
    while (!found) {
        prime++;
        if (isPrime(prime))
            found = true;
    }
    return prime;
}

//returns a hash given a string
string sha256(const string str)
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

void HashTable::writeHeap(ofstream& file) { h.write(file); }
