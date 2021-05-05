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
    Node* heapElm;
    Node* hashElm;
    string str;
};

// A class for Min Heap
class MinHeap
{
public:

    int heap_size;
    int capacity;
    int count;
    vector<Node> harr;

    // Constructor
    MinHeap(int cap);

    // Destructor
    //~MinHeap();

    // to heapify a subtree with the root at given index
    void MinHeapify(int i);
  
    int parent(int i) { return i/2; }
  
    // to get index of left child of node at index i
    int left(int i) { return (2*i); }
  
    // to get index of right child of node at index i
    int right(int i) { return (2*i + 1); }
  
    // to extract the root which is the minimum element
    void swapMin();
  
    // Inserts a new key
    Node insert();

    //returns true if value at index i > j
    bool compare(int i, int j);

    // A utility function to swap two elements
    void swap(int x, int y);

    // Returns the string that refers to the root node
    string getRootString();

    //print heap in ascending order
    void write(string file);

    void deleteMin();

    void printRoot();
};

#endif
