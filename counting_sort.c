#include <stdio.h>

void countingSort(int arr[], int n)
{
    // Step 1: Find the maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array and initialize to 0
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Step 3: Store frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 4: Reconstruct sorted array
    int idx = 0;
    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            arr[idx++] = i;
            count[i]--;
        }
    }
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    countingSort(arr, n);

    printf("\nSorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
