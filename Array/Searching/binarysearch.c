#include <stdio.h>

int search(int arr[], int elem, int lb, int ub)
{
    if (ub >= lb)
    {
        int mid = (lb + ub) / 2;
        if (arr[mid] == elem) // if the middle element is equal to the element then return 'mid'
        {
            return mid;
        }
        else if (arr[mid] > elem) // if the middle element is greater than element then set 'ub = mid-1' and 'lb = lb' and call the same function
        {
            return search(arr, elem, lb, mid - 1);
        }
        else if (arr[mid] < elem) // if the middle element is less than element then set 'lb = mid+1' and 'ub = ub' and call the same function
        {
            return search(arr, elem, mid + 1, ub);
        }
    }
    else // if element not found or ub < lb the retun -1 means element not found
    {
        return -1;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // initialize the array
    int n = sizeof(arr) / 4; // find the number of elements so that find the upper bond
    int elem = 0; // the element 


    int result = search(arr, elem, 0, arr[n - 1]);
    if (result ==-1){
        printf("Element not found.\n");
    }else{
        printf("Element found in elemnt No. %d\n",result+1);
    }
    
    return 0;
}