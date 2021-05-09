//minHeap.h
// Author: Benjamin Fogiel

#include<iostream>
#include<cstring>
#include<climits>
#include<vector>

#ifndef MINHEAP_H
#define MINHEAP_H

using namespace std;

class Node {
public:
    int c;
    int frequency;
    // index of element in MinHeap
    Node* heapElm = nullptr;
    Node* hashElm = nullptr;
    string str;
};

// A class for Min Heap
class MinHeap
{
private:
    int heap_size;
    const int capacity;
    int count;
public:

    vector<Node> harr;

    // Constructor
    MinHeap(int cap);

    // to heapify a subtree with the root at given index
    void MinHeapify(int i);
  
    int parent(int i) { return i/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 1); }
  
    // to extract the root which is the minimum element
    void swapMin(string str);
  
    // Inserts a new key
    void insert(Node* hash);

    //returns true if value at index i > j
    bool compare(int i, int j);

    // A utility function to swap two elements
    void swap(int x, int y);

    // Returns the string that refers to the root node
    string getRootString();

    void deleteMin();

    void printRoot();

    int getHeapSize() { return heap_size; }

    Node* getRoot() { return &harr.at(1); }

    void iterateFreq(Node* n);
};

#endif
