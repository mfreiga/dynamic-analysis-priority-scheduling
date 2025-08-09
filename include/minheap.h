#ifndef MINHEAP_H
#define MINHEAP_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    void* data;
} Node;

typedef struct Heap {
    struct Node* arr;
    size_t size;
    size_t capacity;
} Heap;

Node createNode(int key, void* data);
Heap* createHeap(size_t capacity, const Node* nums);
Node extract_min(Heap* h);
void printHeap(const Heap* h);
void freeHeap(Heap* h);
void heapify(Heap* h, size_t index);

#endif /* MIN_HEAP_H */
