#include <stdio.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// i=0 ,j=0 {1 5 8 4 3 2}
//      j=1 {1 5 8 4 3 2}
//      j=2 {1 5 4 8 3 2}
//      j=3 {1 5 4 3 8 2}
//      j=4 {1 5 4 3 2 8}
// i=1 ,j=0 {1 5 4 3 2 8}
//      j=1 {1 4 5 3 2 8}
//      j=2 {1 4 3 5 2 8}
//      j=3 {1 4 3 2 5 8}
// i=2 ,j=0 {1 4 3 2 5 8}
//      j=1 {1 3 4 2 5 8}
//      j=2 {1 3 2 4 5 8}
// i=3 ,j=0 {1 3 2 4 5 8}
//      j=1 {1 2 3 4 5 8}
// i=4 ,j=0 {1 2 3 4 5 8}
// i=5 ,j=0 {1 2 3 4 5 8}

int main()
{
    int arr[] = {1, 5, 8, 4, 3, 2};
    sort(arr, 6);

    for (int m = 0; m < 6; m++)
    {
        printf("%d", arr[m]);
    }

    return 0;
}