#include <stdio.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i, j;
    i = low + 1;
    j = high;
    int temp;

    do
    {

        while (arr[i] <= pivot) // increase i untill found an element is greater than or equal to pivot
        {
            i++;
        }
        while (arr[j] > pivot) // decrease j untill found an element is less than pivot
        {
            j--;
        }

        if (i<j) // when j cross the i swap them so than the left side of pivot contains smaller elements an right side contain greater elements
        {
            // swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i<j);
    // swap pivot'arr[low] and arr[j]'
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high)
{
    int partitionIndex; // an index number of pivot that is returned by partition function

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
}

int main()
{

    int arr[] = {12,8,5,6,96,2,1,3,4,7,5,6,9,4,2,1,};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted\n");
    printArray(arr, size);

    quickSort(arr,0, size-1);
    printf("\nsorted \n");
    printArray(arr, size);
    return 0;
}