#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 // Number of elements
#define BUCKETS 5 // Number of buckets

// Node for linked list in each bucket
struct Node {
    float value;
    struct Node* next;
};

// Insert node in sorted order in a linked list
void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->value < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    float arr[SIZE] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51, 0.36, 0.49, 0.41};
    struct Node* buckets[BUCKETS] = {NULL};

    // Step 1: Put elements into buckets
    for (int i = 0; i < SIZE; i++) {
        int index = (int)(arr[i] * BUCKETS);
        insertSorted(&buckets[index], arr[i]);
    }

    // Step 2: Concatenate buckets into original array
    int k = 0;
    for (int i = 0; i < BUCKETS; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[k++] = current->value;
            current = current->next;
        }
    }

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
