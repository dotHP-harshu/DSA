#include <stdio.h>
int search(int arr[], int n, int elem){
    for (int i = 0; i < n; i++) // go to eack element and find the given element. If element found then return the location(index No.)
    {
        if(arr[i]== elem){
            return i;
        }
    }
    return -1; // after reaching out whole array and not found the element then return -1 means element not found
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/4;
    int elem = 5;

    int result = search(arr, n, elem);
    
    if (result == -1)
    {
        printf("Element not found.\n");
    }
    else{
        printf("Element found in element No.: %d \n", result+1);
    }
    
    return 0;
}