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
public:

    vector<Node> harr;

    int heap_size;
    int capacity;
    int count;

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
    void swapMin(string str);
  
    // Inserts a new key
    Node* insert(string str);

    //returns true if value at index i > j
    bool compare(int i, int j);

    // A utility function to swap two elements
    void swap(int x, int y);

    // Returns the string that refers to the root node
    string getRootString();

    //print heap in ascending order
    string writeMin();

    Node* deleteMin();

    void printRoot();

    int getHeapSize() { return heap_size; }

    void iterateFreq(int i);
};

#endif
