#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int array[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];       // Current element to insert
        j = i - 1;

        // Shift elements of array[0..i-1] that are greater than key
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;    // Insert key at the correct position
    }
}

// Function to print the array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Main function
int main() {
    int data[] = {9, 5, 1, 4, 3};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array:\n");
    printArray(data, n);

    insertionSort(data, n);

    printf("Sorted array:\n");
    printArray(data, n);

    return 0;
}
