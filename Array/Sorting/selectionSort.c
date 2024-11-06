#include <stdio.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n ; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // swipe min and current element
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int arr[] = {8, 16, 9, 10, 1, 5, 12, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);

    for (int m = 0; m < n; m++)
    {
        printf("%d ", arr[m]);
    }
}