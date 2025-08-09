#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "include/minheap.h"


Node createNode(int key, void *data) {
    struct Node newNode;
    newNode.key = key;
    newNode.data = data;
    return newNode;
}

Heap *createHeap(size_t capacity, const Node *nums) {
    // Allocating memory to heap h
    Heap *h = (Heap *) malloc(sizeof(Heap));

    // Checking if memory is allocated to h or not
    if (h == NULL) {
        printf("Memory error");
        return NULL;
    }

    // Set the values to size and capacity
    h->size = 0;
    h->capacity = capacity;

    // Allocating memory to array
    h->arr = (Node *) malloc(capacity * sizeof(Node));

    // Checking if memory is allocated to h->arr or not
    if (h->arr == NULL) {
        printf("Memory error");
        free(h);
        return NULL;
    }

    if (nums != NULL) {
        //TO TRACK: added -1 for buffferOverflow
        for (size_t i = 0; i <= capacity -1; i++) {
            h->arr[i] = nums[i];
        }
        h->size = capacity;
    }

    // Heapify the array to satisfy the min heap property
    for (int i = (h->size - 2) / 2; i >= 0; i--) {
        heapify(h, i);
    }

    return h;
}

void swapNodes(Node *arr, int i, int j) {
    Node tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapify(Heap *h, size_t index) {
    size_t left = index * 2 + 1;
    size_t right = index * 2 + 2;
    size_t smallest = index;

    if (left < h->size && h->arr[left].key < h->arr[smallest].key)
        smallest = left;

    if (right < h->size && h->arr[right].key < h->arr[smallest].key)
        smallest = right;

    if (smallest != index) {
        swapNodes(h->arr, index, smallest);

        heapify(h, smallest);
    }
}

Node extract_min(Heap *h) {
    if (h == NULL) {
        return createNode(-1, NULL);
    }
    if (h->size == 0) {
        // printf("Heap is empty. Cannot extract minimum.");
        Node n = {.key = -1, .data = NULL};
        return n;
    }

    Node min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    heapify(h, 0);

    return min;
}

void printHeap(const Heap *h) {
    for (size_t i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i].key);
    }
    printf("\n");
}

void freeHeap(Heap *h) {
    free(h->arr);
    //TO TRACK: was after freeing h
    h->arr = NULL;
    free(h);

}
