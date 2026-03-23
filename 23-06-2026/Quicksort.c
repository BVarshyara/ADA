#include <stdio.h>
#include <time.h>

// Partition function (pivot = first element)
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];   // FIRST element as pivot
    int i = low + 1;
    int j = high;

    while (1)
    {
        // Move i forward while elements are <= pivot
        while (i <= high && arr[i] <= pivot)
            i++;

        // Move j backward while elements are > pivot
        while (arr[j] > pivot)
            j--;

        // If pointers cross, stop
        if (i >= j)
            break;

        // Swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Place pivot in correct position
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; // pivot index
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nExecution time: %f seconds\n", cpu_time_used);

    return 0;
}
